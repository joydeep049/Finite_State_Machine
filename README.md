# Deterministic Finite Automata 

Defines a Deterministic finite automata which accepts strings containing letters a and b
which either:
1. Start with 'a'.
2. End with 'b'.

<h2> Transition Diagram</h2>

![FSM](https://github.com/user-attachments/assets/a0ea989d-d740-4e44-a74a-5cfe8d58466d)

<h2> Transition Table</h2>

| Current State | Input | Next State |
| -------------| -----| ------
| Start   <t>      | a     | A_Start    |
| Start         | b     | Middle     |
| A_Start       | a     | A_Start    |
| A_Start       | b     | A_Start     |
| Middle        | a     | Middle     |
| Middle        | b     | End        |
| End           | a     | Middle     |
| End           | b     | End        |

