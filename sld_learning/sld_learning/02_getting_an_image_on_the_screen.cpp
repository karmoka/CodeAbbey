#include <SDL.h>
#include <stdio.h>
#include <memory>
#include <iostream>

#define EnsureMsg(CONDITION, MSG, ...)\
{\
	if (CONDITION)\
	{\
		printf(MSG, __VA_ARGS__);\
		return;\
	}\
}

#define EnsureMsgRet(CONDITION, RET, MSG, ...)\
{\
	if (CONDITION)\
	{\
		printf(MSG, __VA_ARGS__);\
		return RET;\
	}\
}

class Constants
{
public:
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;
};

template<typename T>
class AssetManager
{
	void LoadAsset(std::string InAssetName, T& OutAsset) = 0;
};


class Game
{
protected:
	std::shared_ptr<SDL_Surface> ScreenSurface;
	std::shared_ptr<SDL_Window> Window;

public:
	virtual void Run() = 0;

	virtual bool Init()
	{
		int SdlErrorCode = SDL_Init(SDL_INIT_VIDEO);
		EnsureMsgRet(SdlErrorCode < 0, false, "SDL could not initialize! SDL_Error %i", SdlErrorCode);
		
		Window.reset(SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN));
		EnsureMsgRet(Window == nullptr, false, "Window could not be created! SDL_Error %i", SDL_GetError());

		ScreenSurface.reset(SDL_GetWindowSurface(Window.get()));
		return true;
	}

	virtual bool Close()
	{
		//Destroy window
		if (Window != nullptr)
		{
			SDL_DestroyWindow(Window.get());
		}
		//Quit SDL subsystems
		SDL_Quit();
		return true;
	}
};

class TutorialGame : public Game
{
	std::shared_ptr<SDL_Surface> SurfaceHelloWorld = NULL;

public:
	bool Init() override
	{
		if (!Game::Init())
			return false;
		SurfaceHelloWorld.reset(SDL_LoadBMP("hello_world.bmp"));
		if (!SurfaceHelloWorld)
		{
			printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
			return false;
		}
		return true;
	}

	void Run() override
	{
		bool quit = false;
		SDL_Event Event;
		while (!quit)
		{
			while (SDL_PollEvent(&Event) != 0)
			{
				quit = Event.type == SDL_QUIT;
			}
			SDL_UpdateWindowSurface(Window.get());
			SDL_BlitSurface(SurfaceHelloWorld.get(), NULL, ScreenSurface.get(), NULL);
		}
		printf("Closing Game");
	}

	bool Close()
	{
		if (SurfaceHelloWorld)
		{
			SDL_FreeSurface(SurfaceHelloWorld.get());
		}
		return Game::Close();
	}
};

int main( int argc, char* args[] )
{
	std::shared_ptr<Game> _Game = std::shared_ptr<Game>(new TutorialGame());
	if (!_Game->Init())
	{
		printf("Failed to init game!\n");
		return -1;
	}

	_Game->Run();
	_Game->Close();
	return 0;
}