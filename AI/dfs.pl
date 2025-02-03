% Edges
%     1
%    / \
%   2   3
%  /     \
% 4  ---  5
%  \     /
%   \   /
%     6


% Graph edges

edge(1, 2).
edge(1, 3).
edge(2, 4).
edge(4, 6).
edge(3, 5).
edge(4, 5).
edge(5, 6).

% BFS implementation
bfs(Start, Goal) :-
    bfs_queue([[Start]], Goal).

bfs_queue([[Goal|Path]|_], Goal) :-
    reverse([Goal|Path], Solution),
    write('BFS Path: '), write(Solution), nl.

bfs_queue([Path|Paths], Goal) :-
    extend_path(Path, NewPaths),
    append(Paths, NewPaths, UpdatedQueue),
    bfs_queue(UpdatedQueue, Goal).

extend_path([Node|Path], NewPaths) :-
    findall([NewNode, Node|Path], (edge(Node, NewNode), \+ member(NewNode, [Node|Path])), NewPaths).

% DFS implementation
dfs(Start, Goal) :-
    dfs_path(Start, Goal, [Start], Path),
    reverse(Path, Solution),
    write('DFS Path: '), write(Solution), nl.

dfs_path(Goal, Goal, Path, Path).

dfs_path(Node, Goal, Visited, Path) :-
    edge(Node, NextNode),
    \+ member(NextNode, Visited),
    dfs_path(NextNode, Goal, [NextNode|Visited], Path).