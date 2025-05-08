def reverse_words(sentence):
    return ' '.join(word[::-1] for word in sentence.split())

# Sample usage
input_sentence = "Hello World from Python"
reversed_sentence = reverse_words(input_sentence)
print(reversed_sentence)
