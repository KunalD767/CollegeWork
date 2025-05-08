import nltk
from nltk.classify import NaiveBayesClassifier
from nltk.tokenize import word_tokenize

# Download required resources
nltk.download('punkt')

# Sample training data
training_data = [
    ("He scored a goal", "sports"),
    ("She hit a six", "sports"),
    ("The match was intense", "sports"),
    ("I love pizza", "non-sports"),
    ("It's raining outside", "non-sports"),
    ("He is reading a book", "non-sports")
]

# Feature extraction
def extract_features(sentence):
    words = word_tokenize(sentence.lower())
    return {word: True for word in words}

# Prepare training features
training_features = [(extract_features(text), label) for text, label in training_data]

# Train Naive Bayes Classifier
classifier = NaiveBayesClassifier.train(training_features)

# Test sentences
test_sentences = [
    "She won the match",
    "We went to the stadium",
    "He ordered a burger",
    "Books are very informative",
    "The player scored again",
    "Weather is really nice today"
]

# Classify and print results
print("📝 Test Sentences Classification:\n")
for sentence in test_sentences:
    label = classifier.classify(extract_features(sentence))
    print(f"👉 \"{sentence}\"  ➡️  Predicted: {label}")


test_sentences = [
    "She defeated her opponent",
    "The team celebrated their victory",
    "He is baking a cake",
    "Libraries are quiet places",
    "The striker scored twice",
    "It looks cloudy today"
]

print("Test Sentences Classification:\n")
for sentence in test_sentences:
    label = classifier.classify(extract_features(sentence))
    print(f"\"{sentence}\" -> Predicted: {label}")
