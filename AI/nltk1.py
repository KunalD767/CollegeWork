import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
# Download required resources 
nltk.download('punkt')
nltk.download('punkt_tab')
nltk.download('stopwords')
with open('input.txt', 'r') as file:
    text = file.read()
# Tokenize
words = word_tokenize(text)
stop_words = set(stopwords.words('english'))
filtered_words = [word for word in words if word.lower() not in stop_words]
print("Original Text:\n", text)
print("\nFiltered Text (No Stop Words):\n", ' '.join(filtered_words))
