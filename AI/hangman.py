import getpass

def display_word(word, guessed_letters):
    return " ".join([letter if letter in guessed_letters else "_" for letter in word])

def play_hangman():
    word_to_guess = getpass.getpass("Enter the word to guess: ").lower()
    guessed_letters = set()
    attempts_left = 6

    print("Welcome to Hangman!")
    print("Try to guess the word. You have", attempts_left, "incorrect guesses.")

    while attempts_left > 0:
        print("\nWord:", display_word(word_to_guess, guessed_letters))
        print("Guessed letters:", " ".join(sorted(guessed_letters)))
        print("Attempts left:", attempts_left)

        guess = input("Enter a letter: ").lower()

        if not guess.isalpha() or len(guess) != 1:
            print("Please enter a single alphabetical character.")
            continue

        if guess in guessed_letters:
            print("You've already guessed that letter.")
            continue

        guessed_letters.add(guess)

        if guess in word_to_guess:
            print("Good guess!")
        else:
            print("Wrong guess.")
            attempts_left -= 1

        if all(letter in guessed_letters for letter in word_to_guess):
            print("\nCongratulations! You guessed the word:", word_to_guess)
            break
    else:
        print("\nGame over. The word was:", word_to_guess)

if __name__ == "__main__":
    play_hangman()