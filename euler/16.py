# Ce serait trop chiant à faire en c++. Autant que j'aime le language
# autant qu'il n'est pas agréable de gérer les grands nombres avec

str_num = str(2**1000)
sum_total = 0
for c in str_num:
    sum_total += int(c)

print(sum_total)