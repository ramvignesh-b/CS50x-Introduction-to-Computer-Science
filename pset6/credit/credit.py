from cs50 import get_int

number = get_int("Card Number: ")
number = str(number)
possible = 'INVALID'


def checksum(number):
    digits = list(map(int, str(number)))
    odd_sum = sum(digits[-1::-2])
    sum_val = 0
    for digit in digits[-2::-2]:
        digit *= 2
        if digit > 9:
            digit = (digit % 10) + 1
        sum_val += digit
    if (odd_sum + sum_val) % 10 == 0:
        return True
    else:
        return False;


if len(number) == 13:
    if number[:1] == "4":
        possible = 'VISA'
if len(number) == 15:
    if number[:2] in ["34", "37"]:
        possible = 'AMEX'
if len(number) == 16:
    if number[:1] == "4":
        possible = 'VISA'
    elif number[:2] in ["51", "52", "53", "54", "55"]:
        possible = 'MASTERCARD'
if possible != 'INVALID':
    if checksum(number) == True:
        print(possible+'\n')
    else:
        print('INVALID\n')
else:
    print('INVALID\n')


