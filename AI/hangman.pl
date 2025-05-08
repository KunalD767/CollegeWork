:- dynamic word/1, guessed_letters/1, attempts_left/1.
 
% Initialize the game
set_word(Word) :-
   retractall(word(_)),
   assertz(word(Word)),
   retractall(guessed_letters(_)),
   assertz(guessed_letters([])),
   retractall(attempts_left(_)),
   assertz(attempts_left(6)).  % Set max attempts
 
% Display the word with guessed letters
show_word :-
   word(W),
   guessed_letters(GL),
   show_word_helper(W, GL), nl.
 
show_word_helper([], _).
show_word_helper([H|T], GL) :-
   (   member(H, GL) -> write(H) ; write('_') ),
   write(' '),
   show_word_helper(T, GL).
 
% Process a guess
guess(Letter) :-
   guessed_letters(GL),
   (   member(Letter, GL)
   ->  write('Already guessed that letter!'), nl
   ;   retract(guessed_letters(GL)),
       assertz(guessed_letters([Letter|GL])),
       word(W),
       (   member(Letter, W)
       ->  write('Correct guess!'), nl
       ;   wrong_guess
       )
   ),
   show_word,
   check_game_status.
 
% Handle incorrect guesses
wrong_guess :-
   attempts_left(N),
   N > 1,
   NewN is N - 1,
   retract(attempts_left(N)),
   assertz(attempts_left(NewN)),
   write('Wrong guess! '), write(NewN), write(' attempts left.'), nl.
 
wrong_guess :-
   retract(attempts_left(_)),
   assertz(attempts_left(0)),
   write('Game over! You lost.'), nl,
   word(W),
   write('The correct word was: '), write(W), nl,
   abort.
 
% Check for win condition
check_game_status :-
   word(W),
   guessed_letters(GL),
   (   all_letters_guessed(W, GL)
   ->  write('Congratulations, you won!'), nl, abort
   ;   true
   ).
 
all_letters_guessed([], _).
all_letters_guessed([H|T], GL) :-
   member(H, GL),
   all_letters_guessed(T, GL).
 
% Start the game
start :-
   write('Enter a word to guess: '),
   read(Word),
   atom_chars(Word, Chars),
   set_word(Chars),
   play.
 
% Play the game in a loop
play :-
   check_game_status,
   write('Enter your guess (single letter): '),
   read(Letter),
   atom_chars(Letter, [L]),  % Convert input to single character
   guess(L),
   play.