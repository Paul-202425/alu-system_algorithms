#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphs.h"
#include "queues.h"

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

/**
 * struct bt_ctx_s - Context shared by the recursive backtracking calls
 *
 * @map: Two-dimensional array (0 is walkable, 1 is blocked)
 * @rows: Number of rows in the map
 * @cols: Number of columns in the map
 * @visited: Array flagging the cells already visited
 * @arr: Cells of the path currently being explored
 * @target: Coordinates of the target point
 * @len: Number of cells in the path found
 */
typedef struct bt_ctx_s
{
	char **map;
	int rows;
	int cols;
	char *visited;
	point_t *arr;
	point_t const *target;
	int len;
} bt_ctx_t;

queue_t *backtracking_array(char **map, int rows, int cols,
		point_t const *start, point_t const *target);

#endif /* PATHFINDING_H */
