import time

# ======================= WAY 1 ============================
start = time.time()
current = 0 
while True:
    current += 20
    for i in range(19, 10, -1):
        if current % i != 0:
            break
    else:
        print(current)
        break
print("Way 1 took : {} seconds".format(time.time() - start))


# ======================= WAY 2 ============================
start = time.time()
current = 0
check_list = [11, 12, 13, 14,15,16,17,18,19]
while True:
    current += 20
    if all(current % n == 0 for n in check_list):
        print(current)
        break
print("Way 2 took : {} seconds".format(time.time() - start))