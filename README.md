# C - Pathfinding

Pathfinding algorithms in C: backtracking, Dijkstra's algorithm and A*.

## Requirements
- Compiled on Ubuntu 14.04 LTS with `gcc 4.8.4` and the flags `-Wall -Werror -Wextra -pedantic`
- Betty style, no global variables, at most 5 functions per file
- All prototypes are in `pathfinding.h`
- Link with `-lgraphs -lqueues` (libraries from the `0x07-pathfinding.c` repository)

## Files
| File | Description |
|------|-------------|
| `pathfinding.h` | Header file with the `point_t` structure and all prototypes |

## Compilation example
```
gcc -Wall -Wextra -Werror -pedantic *.c -L. -lgraphs -lqueues -o pathfinding
```# alu-system_algorithms
