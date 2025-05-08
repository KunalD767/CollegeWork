import nltk
from nltk.stem import PorterStemmer
from nltk.tokenize import word_tokenize

# Download tokenizer
nltk.download('punkt')

# Initialize stemmer
stemmer = PorterStemmer()

# Sample sentence
sentence = "Computationally thinking machines are running efficiently."

# Tokenize
words = word_tokenize(sentence)

# Apply stemming
stemmed_words = [stemmer.stem(word) for word in words]

# Output
print("📝 Original Sentence:\n", sentence)
print("\n🪓 Stemmed Words:\n", ' '.join(stemmed_words))

