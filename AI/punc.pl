:- use_module(library(lists)).

% Define punctuation characters
punctuation_marks(['.', ',', ';', ':', '!', '?', '-', '(', ')', '[', ']', '{', '}', '\'', '"', '/', '\\', '|', '@', '#', '$', '%', '^', '&', '*', '_', '+', '=', '<', '>', '`', '~']).

% Predicate to remove punctuation
remove_punctuation([], []).  % Base case: Empty list remains empty
remove_punctuation([H|T], Result) :-
    punctuation_marks(Punct),
    member(H, Punct),  % Check if H is punctuation
    remove_punctuation(T, Result).  % Skip punctuation

remove_punctuation([H|T], [H|Result]) :-
    remove_punctuation(T, Result).  % Keep non-punctuation characters

% Convert an input string into a list, process, and convert back to string
remove_punctuation_from_string(Input, Output) :-
    string_chars(Input, CharList),  % Convert string to char list
    remove_punctuation(CharList, CleanList),  % Remove punctuation
    string_chars(Output, CleanList).  % Convert back to string
