# If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
# If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
# NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) 
# contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]

number_map = {
    0: {
        0: "",
        1: "one",
        2: "two",
        3: "three",
        4: "four",
        5: "five",
        6: "six",
        7: "seven",
        8: "eight",
        9: "nine",
        10: "ten"
    },
    1: {
        11: "eleven",
        12: "twelve",
        13: "thirteen",
        14: "fourteen",
        15: "fifteen",
        16: "sixteen",
        17: "seventeen",
        18: "eighteen",
        19: "nineteen",
    },
    10: {
        2: "twenty",
        3: "thirty",
        4: "forty",
        5: "fifty",
        6: "sixty",
        7: "seventy",
        8: "eighty",
        9: "ninety",
    }
}

sum_t = 0
for i in range(1, 1001):
    # It would also be possible (and probably easier) to calculate the numbers of 
    # letters for 1 to 99, multiply that by 10, add 100 * the lenght of "{num} hundred" and the length of "one thousand"
    s = ""
    if i == 1000:
        s = "one thousand "
    i %= 1000

    if i >= 100:
        s += number_map[0][i // 100] + " hundred "
        if i % 100 != 0:
            s += "and "

    i %= 100 # We treat the values below 100
    if i > 19:
        s += number_map[10][i // 10] + " " + number_map[0][i % 10]
    elif i > 10:
        s += number_map[1][i]
    else:
        s += number_map[0][i]
    sum_t += len(s.replace(" ", "").rstrip())

print(sum_t)