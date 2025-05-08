import nltk
from nltk.stem import WordNetLemmatizer
from nltk.tokenize import word_tokenize
nltk.download('punkt')
nltk.download('wordnet')
nltk.download('omw-1.4')  
lemmatizer = WordNetLemmatizer()
sentence = "The leaves were falling from the trees and children were running happily."
words = word_tokenize(sentence)
lemmatized_words = [lemmatizer.lemmatize(word) for word in words]
print("📝 Original Sentence:\n", sentence)
print("\n🌱 Lemmatized Words:\n", ' '.join(lemmatized_words))