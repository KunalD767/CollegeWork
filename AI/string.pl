:- use_module(library(lists)).
:- use_module(library(string)).

% Convert a string into a list of words
split_into_words(Sentence, WordList) :-
    split_string(Sentence, " ", " ", WordList).

% Sort the words alphabetically
sort_sentence(Sentence, SortedSentence) :-
    split_into_words(Sentence, WordList),  % Split sentence into words
    sort(WordList, SortedList),            % Sort words alphabetically
    atomic_list_concat(SortedList, ' ', SortedSentence).  % Join back into a sentence
