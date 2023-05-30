class TextAnalyzer:
    def __init__(self, text):
        self.text = text

    @staticmethod
    def is_palindrome(word):
        return word.lower() == word.lower()[::-1]

    def find_palindromes(self):
        palindromes = []
        words = self.text.split()
        for word in words:
            if self.is_palindrome(word):
                palindromes.append(word)
        return palindromes

    def find_unique_words(self):
        words = self.text.split()
        unique_words = set(words)
        return unique_words


# Example usage
text = "A man, a plan, a canal, Panama"
analyzer = TextAnalyzer(text)

# Using class method
palindromes = analyzer.find_palindromes()
print("Palindromes:", palindromes)

# Using string method
unique_words = analyzer.find_unique_words()
print("Unique words:", unique_words)