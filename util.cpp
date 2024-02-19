#include "util.hpp"

bool dfs(Maze &maze, int x, int y, int *moves) {
    *moves = *moves + 1;
    // Marca la celda actual como visitada
    maze.visited[x][y] = true;

    // Si la celda actual es la salida, se ha encontrado la solución
    if (maze.getCellType(x, y) == CellType::Exit) {
        return true;
    }

    // Explora las celdas adyacentes
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            
            // Limitar movimiento solo hacia arriba, abajo y hacia los lados
            if (dx == dy || dx + dy == 0) continue;
                
            // Limites del laberinto
            if (x + dx < 0 || x + dx >= maze.getHeight() 
                || y + dy < 0 || y + dy >= maze.getWidth()){
                continue;
            }
            
            // No explora las celdas que son paredes o que ya han sido visitadas
            if (maze.isPassable(x + dx, y + dy) && !maze.visited[x + dx][y + dy]) {
                if (dfs(maze, x + dx, y + dy, moves)) {
                    return true;
                }
            }
        }
    }

    // No se encontró la solución
    return false;
}

bool bfs(Maze &maze, int x, int y, int *moves) {
    // Crea una cola para almacenar las celdas por explorar
    std::queue<std::pair<int, int>> queue;

    // Marca la celda actual como visitada
    maze.visited[x][y] = true;

    // Agrega la celda actual a la cola
    queue.push({x, y});

    // Mientras la cola no esté vacía
    while (!queue.empty()) {
        *moves = *moves + 1;

        // Obtiene la celda actual de la cola
        std::pair<int, int> current = queue.front();
        queue.pop();

        // Si la celda actual es la salida, se ha encontrado la solución
        if (maze.getCellType(current.first, current.second) == CellType::Exit) {
            return true;
        }

        // Explora las celdas adyacentes
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                
                // Limitar movimiento solo hacia arriba, abajo y hacia los lados
                if (dx == dy || dx + dy == 0) continue;
                
                
                // Limites del laberinto
                if (current.first + dx < 0 || current.first + dx >= maze.getHeight() 
                    || current.second + dy < 0 || current.second + dy >= maze.getWidth()){
                    continue;
                }

                
                // No explora las celdas que son paredes o que ya han sido visitadas
                if (maze.isPassable(current.first + dx, current.second + dy) 
                    && !maze.visited[current.first + dx][current.second + dy]) {
                    
                    // Marca la celda como visitada
                    maze.visited[current.first + dx][current.second + dy] = true;

                    // Agrega la celda a la cola
                    queue.push({current.first + dx, current.second + dy});
                }
            }
        }                       
    }

    return false;

}