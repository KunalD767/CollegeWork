import nltk
from nltk.corpus import movie_reviews
import random
from nltk.classify import NaiveBayesClassifier
from nltk.classify.util import accuracy
from nltk.tokenize import TreebankWordTokenizer
nltk.download('movie_reviews', force=True)
nltk.download('punkt', force=True)

documents = [(list(movie_reviews.words(fileid)), category)
             for category in movie_reviews.categories()
             for fileid in movie_reviews.fileids(category)]

random.shuffle(documents)

all_words = nltk.FreqDist(w.lower() for w in movie_reviews.words())

word_features = list(all_words)[:2000]

def document_features(document):
    words = set(document)
    features = {}
    for word in word_features:
        features[f'contains({word})'] = (word in words)
    return features

featuresets = [(document_features(d), c) for (d, c) in documents]

train_set, test_set = featuresets[100:], featuresets[:100]

classifier = NaiveBayesClassifier.train(train_set)

print("Classifier accuracy:", accuracy(classifier, test_set))

user_input = input("Enter a sentence to classify (positive or negative): ")
tokenizer = TreebankWordTokenizer()
tokens = tokenizer.tokenize(user_input)
features = document_features(tokens)
prediction = classifier.classify(features)

print("\nInput Sentence:", user_input)
print("Predicted Sentiment:", prediction)
# The plot was engaging and well-paced.
# Complete waste of time and money.