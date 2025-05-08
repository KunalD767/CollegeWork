% Tic Tac Toe Prolog

% Define winning conditions
win(Board, Player) :-
    row_win(Board, Player);
    col_win(Board, Player);
    diag_win(Board, Player).

row_win(Board, Player) :-
    nth0(0, Board, Player), nth0(1, Board, Player), nth0(2, Board, Player);
    nth0(3, Board, Player), nth0(4, Board, Player), nth0(5, Board, Player);
    nth0(6, Board, Player), nth0(7, Board, Player), nth0(8, Board, Player).

col_win(Board, Player) :-
    nth0(0, Board, Player), nth0(3, Board, Player), nth0(6, Board, Player);
    nth0(1, Board, Player), nth0(4, Board, Player), nth0(7, Board, Player);
    nth0(2, Board, Player), nth0(5, Board, Player), nth0(8, Board, Player).

diag_win(Board, Player) :-
    nth0(0, Board, Player), nth0(4, Board, Player), nth0(8, Board, Player);
    nth0(2, Board, Player), nth0(4, Board, Player), nth0(6, Board, Player).

% Determine winner
winner(Board, invalid) :-
    win(Board, x),
    win(Board, o), !.

winner(Board, x) :- 
    win(Board, x), !.

winner(Board, o) :- 
    win(Board, o), !.

winner(_, draw).

% Check if a move is valid
valid_move(Board, Index) :-
    nth0(Index, Board, e).

% Make a move
make_move(Board, Index, Player, NewBoard) :-
    valid_move(Board, Index),
    nth0(Index, Board, e, Rest),
    nth0(Index, NewBoard, Player, Rest).

% Best move – just first empty
find_best_move(Board, BestMove) :-
    nth0(BestMove, Board, e), !.

% Find all best moves (all empty spots)
find_all_best_moves(Board, BestMoves) :-
    findall(Index, nth0(Index, Board, e), BestMoves).

% Simulate series of moves
verify_solution(Board, [], Board).
verify_solution(Board, [Move|Moves], FinalBoard) :-
    length(Moves, N), PlayerIndex is N mod 2,
    (PlayerIndex = 0 -> Player = x ; Player = o),
    valid_move(Board, Move),
    writef('Move %w is valid on board: %w\n', [Move, Board]),
    make_move(Board, Move, Player, NewBoard),
    verify_solution(NewBoard, Moves, FinalBoard),
    (Moves = [] -> writef('Solution verified. Final board: %w\n', [NewBoard]) ; true).

% For test cases
play_win_cases :-
    % Horizontal win
    verify_solution([e,e,e,e,e,e,e,e,e], [0,3,1,4,2], Final1),
    nl, writeln('Horizontal Win Case (x wins):'),
    print_board(Final1),

    % Vertical win
    verify_solution([e,e,e,e,e,e,e,e,e], [0,1,3,2,6,4,7], Final2),
    nl, writeln('Vertical Win Case (o wins):'),
    print_board(Final2),

    % Diagonal win
    verify_solution([e,e,e,e,e,e,e,e,e], [0,1,4,2,8], Final3),
    nl, writeln('Diagonal Win Case (x wins):'),
    print_board(Final3),

    % Draw
    verify_solution([e,e,e,e,e,e,e,e,e], [1,0,2,7,3,5,4,6,8], Final4),
    nl, writeln('Draw Case (Game Draw):'),
    print_board(Final4).

% Display board nicely
print_board(Board) :-
    print_row(Board, 0), writeln(''),
    print_row(Board, 3), writeln(''),
    print_row(Board, 6), writeln('').

print_row(Board, Start) :-
    I1 is Start + 1,
    I2 is Start + 2,
    nth0(Start, Board, A), nth0(I1, Board, B), nth0(I2, Board, C),
    writef('%w | %w | %w\n', [A,B,C]).