from math import sqrt

def max_prime(num:int) -> list:
    max_prime = -1
    

    while num % 2 == 0:
        max_prime = 2
        num /= 2

    for i in range(3, int(sqrt(num)) + 1, 2):
        while num % i == 0:
            max_prime = i
            num /= i

    return num if num > 2 else max_prime

print(max_prime(600851475143 ))