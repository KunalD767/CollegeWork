import nltk
from nltk.tokenize import word_tokenize
nltk.download('punkt')
nltk.download('averaged_perceptron_tagger_eng')
sentence = "The quick brown fox jumps over the lazy dog."
words = word_tokenize(sentence)
pos_tags = nltk.pos_tag(words)
print("📝 Original Sentence:\n", sentence)
print("\n🔤 Part of Speech Tags:")
for word, tag in pos_tags:
    print(f"{word:10} --> {tag}")
