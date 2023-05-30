import string

# Enumerate lowercase ASCII letters
lowercase_letters = string.ascii_lowercase
enumerated_letters = list(enumerate(lowercase_letters, start=1))

# Print the enumerated letters
for index, letter in enumerated_letters:
    print(index, letter)
