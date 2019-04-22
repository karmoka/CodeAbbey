#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <stdlib.h>

using namespace std;

string readFileToString(string fileName) {
    ifstream in(fileName);
    string line;
    string s = "";
    while (getline(in, line)) {
        s += line;
    }
    return s;
}

bool isDelimiter(char c, vector<char>& delimiters) {
    for (int j = 0; j < delimiters.size(); ++j) {
        if (c == delimiters[j]) {
            return true;
        }
    }
    return false;
}

int rand_(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}

string chooseNext(vector<pair<string, int>>& pairs) {
    if (pairs.size() == 1) return pairs[0].first;
    if (pairs.size() == 0) return "";

    int index = 0;
    int max = 0;
    for (int i = 0; i < pairs.size(); ++i) {
        int weight = rand_(0, pairs[i].second);
        if (weight > max) {
            max = weight;
            index = i;
        }
    }
    return pairs[index].first;
}

void insert(vector<pair<string, int>>& pairs, const string& word_) {
    auto index = find_if(pairs.begin(), pairs.end(), [word_](pair<string, int> p) { return p.first == word_;});
    if (index == pairs.end()) {
        pairs.push_back({word_, 1});
    } else {
        (*index).second += 1;
    }
}

int main()
{
    string input = readFileToString("alice_oz.txt");
    vector<char> delimiters {' ', '.', ',', ';'};
    
    int begin = 0;
    int end = 0;
    vector<string> words;
    for (int i = 0; i < input.length(); ++i) {
        if (isDelimiter(input[i], delimiters)) {
            end = i;
            words.push_back(input.substr(begin, end - begin + 1));
            begin = end + 1;
        }
    }

    bool firstPrefixSet = false;
    map<string, vector<pair<string, int>>> prefixMap;
    for (int index = 0; index < words.size() - 2; ++index) {
        string prefix = words[index] + words[index+1];
        insert(prefixMap[prefix], words[index+2]);
    }

    
    int max = 100000;
    for (int i = 0; i < 1; ++i) {
        ofstream out("output/out" + to_string(i) + ".txt");
        string first = words[0];
        string second = words[1];
        string currentPrefix = first + second;
        int cnt = 0;
        while (prefixMap[currentPrefix].size() != 0) {
            out << first;
            first = second;
            // int index = rand_(0, prefixMap[currentPrefix].size() - 1);
            second = chooseNext(prefixMap[currentPrefix]);
            // second = prefixMap[currentPrefix][index].first;
            currentPrefix = first + second;
            cnt += 1;
            // if (cnt > max) break;
        }
        out << first + second << endl;
        out.close();
    }
}