% Example graph represented as a tree:
%               a
%            /     \
%           b       c
%         /   \       \
%        d     e       f
% Facts defining the graph structure
edge(a, b).
edge(a, c).
edge(b, d).
edge(b, e).
edge(c, f).
edge(e, f).

% Helper predicate for bidirectional traversal
connected(X, Y) :- edge(X, Y).
connected(X, Y) :- edge(Y, X).

% Query to check if a node exists in the graph
node_exists(Node) :- 
    (connected(Node, _) -> 
        format("Node: ~w exists.~n", [Node])
    ; 
        format("Node: ~w does not exist.~n", [Node])
    ).

% BFS traversal with start and end node
bfs(Start, End) :-
    (\+ connected(Start, _); \+ connected(End, _)) ->
        format("Cannot reach: either ~w or ~w does not exist.~n", [Start, End]);
    bfs_helper([(Start, none)], [], End, Path),
    reverse(Path, FinalPath),
    format("Final Path: "),
    print_path(FinalPath).

% Base case: Empty queue, return visited path
bfs_helper([], _, _, []).

% Base case: End node found
bfs_helper([(Node, Parent) | _], Visited, End, [Node | Visited]) :-
    Node == End, !.

% Recursive case: Process the queue
bfs_helper([(Node, Parent) | Queue], Visited, End, Path) :-
    (
        Parent \= none -> 
            format("Node: ~w (Parent: ~w)~n", [Node, Parent])
        ; 
            format("Starting Node: ~w~n", [Node])
    ),
    % Continue traversal for unvisited neighbors
    \+ member(Node, Visited),
    findall((Neighbor, Node), 
            (connected(Node, Neighbor), \+ member(Neighbor, Visited)), 
            Neighbors),
    append(Queue, Neighbors, NewQueue),
    bfs_helper(NewQueue, [Node | Visited], End, Path).

% Skip visited nodes
bfs_helper([(_, _) | Queue], Visited, End, Path) :-
    bfs_helper(Queue, Visited, End, Path).

% Helper to print path in a-b-c format
print_path([Node]) :- format("~w~n", [Node]).
print_path([Node1, Node2 | Rest]) :- 
    format("~w-", [Node1]),
    print_path([Node2 | Rest]).