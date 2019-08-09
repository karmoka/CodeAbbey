candidates = []
for i in range(900, 999):
    for j in range(900, 999):
        candidates.append(i * j)
candidates.reverse()


for candidate in candidates:
    s = str(candidate)
    if s[0] == s[5] and s[1] == s[4] and s[2] == s[3]:
        print(s)
        exit()
