# AI_Code
Dumb Artificial Intelligence Experimental Code

## Contents of the Collection

### 1. Water Jug Problem
A Water Jug Problem: You are given two jugs, a 4-gallon one and a 3-gallon one, a pump which has unlimited water which you can use to fill the jug, and the ground on which water may be poured. Neither jug has any measuring markings on it. How can you get exactly 2 gallons of water in the 4-gallon jug?
> State Representation and Initial State – we will represent a state of the problem as a tuple (x, y) where x represents the amount of water in the 4-gallon jug and y represents the amount of water in the 3-gallon jug. Note 0 ≤ x ≤ 4, and 0 ≤ y ≤ 3. Our initial state: (0,0)
> Goal Predicate – state = (2,y) where 0 ≤ y ≤ 3.

#### Operators – we must define a set of operators
1. Fill 4-gal jug x<4
2. Fill 3-gal jug y<3
3. Empty 4-gal jug on ground x>0
4. Empty 3-gal jug on ground y>0
5. Pour water from 3-gal jug to fill 4-gal jug 0<x+y≥4andy>0
6. Pour water from 4-gal jug to fill 3-gal-jug 0<x+y≥3andx>0
7. Pour all of water from 3-gal jug into 4-gal jug 0<x+y≤4andy≥0
8. Pour all of water from 4-gal jug into 3-gal jug 0<x+y≤3andx≥0

### 2. BFS (Breadth First Search)
### 3. DFS (Depth First Search)
### 4. Tic Tac Toe - 2 Player
### 5. Tic Tac Toe - 1 Player
### 6. Magic Square Problem

### 7. A* Algorithm
- AO* Algorithm
- Block World Problem
