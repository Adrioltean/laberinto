#ifndef UTIL_HPP
#define UTIL_HPP

#include <queue>
#include "maze.hpp"

bool dfs(Maze &maze, int x, int y, int *moves);
bool bfs(Maze &maze, int x, int y, int *moves);

#endif