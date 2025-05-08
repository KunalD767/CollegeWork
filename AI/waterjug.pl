% Production rules (concise):
% 1: (X,Y), X<4 -> (4,Y)            Fill 4L jug move(state(X, Y), state(4, Y), 1, 'Fill 4L jug') :- X < 4.
% 2: (X,Y), Y<3 -> (X,3)             Fill 3L jug
move(state(X, Y), state(X, 3), 2, 'Fill 3L jug') :- Y < 3.
% 3: (X,0), X>0 -> (X-D, D)          Pour from 4L into 3L (D<=3)
move(state(X, 0), state(Xd, D), 3, 'Pour 4L->3L') :-
    X > 0, between(1, X, D), D =< 3, Xd is X - D.
% 4: (0,Y), Y>0 -> (D, Y-D)          Pour from 3L into 4L (D<=4)
move(state(0, Y), state(D, Yd), 4, 'Pour 3L->4L') :-
    Y > 0, between(1, Y, D), D =< 4, Yd is Y - D.
% 5: (X,Y), X>0 -> (0,Y)             Empty 4L jug
move(state(X, Y), state(0, Y), 5, 'Empty 4L jug') :- X > 0.
% 6: (X,Y), Y>0 -> (X,0)             Empty 3L jug
move(state(X, Y), state(X, 0), 6, 'Empty 3L jug') :- Y > 0.
% 7: (X,Y), X<4, Y>0 -> (4, Y-(4-X))  Pour from 3L to fill 4L
move(state(X, Y), state(4, Ynew), 7, 'Fill 4L from 3L') :-
    X < 4, Y > 0, Transfer is 4 - X, Y >= Transfer, Ynew is Y - Transfer.
% 8: (X,Y), Y<3, X>0 -> (X-(3-Y), 3)  Pour from 4L to fill 3L
move(state(X, Y), state(Xnew, 3), 8, 'Fill 3L from 4L') :-
Y < 3, X > 0, Transfer is 3 - Y, X >= Transfer, Xnew is X - Transfer.
% 9: (X,Y), Y>0, X+Y=<4 -> (X+Y, 0)   Pour all from 3L to 4L
move(state(X, Y), state(Xnew, 0), 9, 'Pour all 3L->4L') :-
    Y > 0, X + Y =< 4, Xnew is X + Y.
% 10: (X,Y), X>0, X+Y=<3 -> (0, X+Y)  Pour all from 4L to 3L
move(state(X, Y), state(0, Ynew), 10, 'Pour all 4L->3L') :-
    X > 0, X + Y =< 3, Ynew is X + Y.
% 11: (0,2) -> (2,0)                Pour 2L from 3L to 4L
move(state(0, 2), state(2, 0), 11, 'Pour 2L 3L->4L').
% 12: (2,Y) -> (0,Y)                Empty 2L in 4L jug on the ground
move(state(2, Y), state(0, Y), 12, 'Empty 2L from 4L') :- Y >= 0.
% Solver: from state(0,0) to state(2,0)
solve(State, State, _, [State], []).
solve(State, Goal, Visited, [State|Path], [move(Rule, Desc, State, Next)|Moves]) :-
    move(State, Next, Rule, Desc),
    \+ member(Next, Visited),
    solve(Next, Goal, [Next|Visited], Path, Moves).
% Find three distinct solutions.
find_solutions(Sols) :-
    findall((Path, Moves),
            solve(state(0,0), state(2,0), [state(0,0)], Path, Moves),
            All),
    list_to_set(All, Unique),
    Unique = [S1, S2, S3 | _],
    Sols = [S1, S2, S3].
verify_solution([]).
verify_solution([move(Rule, _, From, To)|Rest]) :-
    ( move(From, To, Rule, _) ->
        format('R~w: valid~n', [Rule])
    ;   format('R~w: invalid~n', [Rule])
    ),
    verify_solution(Rest).
print_moves([]).
print_moves([move(Rule, _, From, To)|Rest]) :-
    format('R~w: ~w -> ~w~n', [Rule, From, To]),
    print_moves(Rest).
print_rules :-
    nl, write('Production Rules:'), nl,
    write('1: Fill 4L jug'), nl,
    write('2: Fill 3L jug'), nl,
    write('3: Pour from 4L->3L'), nl,
    write('4: Pour from 3L->4L'), nl,
    write('5: Empty 4L jug'), nl,
    write('6: Empty 3L jug'), nl,
    write('7: Fill 4L from 3L'), nl,
    write('8: Fill 3L from 4L'), nl,
    write('9: Pour all 3L->4L'), nl,
    write('10: Pour all 4L->3L'), nl,
    write('11: Pour 2L from 3L->4L'), nl,
    write('12: Empty 2L from 4L'), nl, nl.
% Run: print rules, solutions, and then verify moves (short output)
run :-
    print_rules,
    find_solutions(Sols),
    print_solutions(Sols).
print_solutions([]).
print_solutions([(Path, Moves)|Rest]) :-
    write('Solution:'), nl,
    print_moves(Moves),
    write('Verification:'), nl,
    verify_solution(Moves),
    nl,
    print_solutions(Rest).




