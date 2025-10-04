def int_to_roman(num):
    val = [
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    ]
    
    syms = [
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    ]
    
    roman_numeral = ""
    i = 0
    
    while num > 0:
        count = num // val[i]
        roman_numeral += syms[i] * count
        num -= val[i] * count
        i += 1
    
    return roman_numeral

number = int(input("Enter an integer (1 to 3999): "))

if 1 <= number <= 3999:
    print("Roman numeral:", int_to_roman(number))
else:
    print("Number out of range. Please enter a number between 1 and 3999.")
