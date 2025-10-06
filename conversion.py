def digit_to_word(digit):
    words = {
        '0': 'Zero', '1': 'One', '2': 'Two', '3': 'Three', '4': 'Four',
        '5': 'Five', '6': 'Six', '7': 'Seven', '8': 'Eight', '9': 'Nine',
        '.': 'Point', '-': 'Minus'
    }
    return words.get(digit, '')

def number_to_words(number_str):
    return ' '.join(digit_to_word(ch) for ch in number_str if ch in '0123456789.-')

# Get input from user
number_input = input("Enter a decimal number: ")

# Print the number in words
print("Number in words:", number_to_words(number_input))
