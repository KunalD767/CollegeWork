% Predicate to convert Celsius to Fahrenheit
% Formula: F = (C * 9/5) + 32
celsius_to_fahrenheit(Celsius, Fahrenheit) :-
    Fahrenheit is (Celsius * 9/5) + 32.
below_freezing_C(Celsius) :-
    Celsius =< 0.
below_freezing_F(Fahrenheit) :-
    Fahrenheit =< 32.