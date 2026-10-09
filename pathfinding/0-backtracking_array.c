#include "pathfinding.h"

/**
 * explore - Recursively looks for a path to the target (backtracking)
 * @c: Search context
 * @x: Current X coordinate
 * @y: Current Y coordinate
 * @depth: Number of cells already in the current path
 *
 * Return: 1 if a path to the target was found, 0 otherwise
 */
static int explore(bt_ctx_t *c, int x, int y, int depth)
{
	if (x < 0 || y < 0 || x >= c->cols || y >= c->rows)
		return (0);
	if (c->map[y][x] == '1' || c->visited[y * c->cols + x])
		return (0);

	c->visited[y * c->cols + x] = 1;
	printf("Checking coordinates [%d, %d]\n", x, y);
	c->arr[depth].x = x;
	c->arr[depth].y = y;

	if (x == c->target->x && y == c->target->y)
	{
		c->len = depth + 1;
		return (1);
	}
	if (explore(c, x + 1, y, depth + 1) ||
	    explore(c, x, y + 1, depth + 1) ||
	    explore(c, x - 1, y, depth + 1) ||
	    explore(c, x, y - 1, depth + 1))
		return (1);

	return (0);
}

/**
 * build_queue - Copies the cells of a path into a new queue
 * @arr: Cells of the path, from start to target
 * @len: Number of cells in the path
 *
 * Return: Pointer to the queue, or NULL on failure
 */
static queue_t *build_queue(point_t const *arr, int len)
{
	queue_t *path;
	point_t *point;
	int i;

	path = queue_create();
	if (path == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		point = malloc(sizeof(point_t));
		if (point == NULL)
		{
			while (path->front)
				free(dequeue(path));
			free(path);
			return (NULL);
		}
		*point = arr[i];
		queue_push_back(path, point);
	}
	return (path);
}

/**
 * backtracking_array - Searches for the first path from start to target
 * @map: Read-only two-dimensional array (0 is walkable, 1 is blocked)
 * @rows: Number of rows in map
 * @cols: Number of columns in map
 * @start: Coordinates of the starting point
 * @target: Coordinates of the target point
 *
 * Return: Queue of points from start to target, or NULL if no path exists
 */
queue_t *backtracking_array(char **map, int rows, int cols,
		point_t const *start, point_t const *target)
{
	bt_ctx_t c;
	queue_t *path;

	if (!map || !start || !target || rows <= 0 || cols <= 0)
		return (NULL);

	path = NULL;
	c.map = map;
	c.rows = rows;
	c.cols = cols;
	c.target = target;
	c.len = 0;
	c.visited = calloc((size_t)rows * cols, sizeof(char));
	c.arr = malloc(sizeof(point_t) * rows * cols);

	if (c.visited && c.arr && explore(&c, start->x, start->y, 0))
		path = build_queue(c.arr, c.len);

	free(c.visited);
	free(c.arr);
	return (path);
}
