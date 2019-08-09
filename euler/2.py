
previous = 0
current = 1
total = 0

while True:
    previous, current = current, previous + current
    if current > 4000000:
        break
    if current % 2 == 0:
        total += current

print(total)