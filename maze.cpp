#include "maze.hpp"

Maze::Maze(std::vector<std::vector<int>> initial_state, int width, int height, int startX, int startY, int exitX, int exitY)
: width(width), height(height)
 {
    
    setupVisited();

    setupMap(initial_state);

    this->map[startY][startX] = CellType::Start;
    this->map[exitY][exitX] = CellType::Exit;

}

Maze::~Maze() {
}

bool Maze::isPassable(int x, int y) {
    return this->map[x][y] != CellType::Wall;
}

CellType Maze::getCellType(int x, int y) {
    return this->map[x][y];
}

void Maze::setupVisited(){

    for (int i = 0; i < height; i++){
        std::vector<bool> fila;
        for (int j = 0; j < width; j++){
            fila.push_back(false);
        }
        visited.push_back(fila);
        
    }

}

void Maze::setupMap(std::vector<std::vector<int>> initial_state){

    for (int i = 0; i < height; i++){

        std::vector<CellType> fila;

        for (int j = 0; j < width; j++){

            if (initial_state[i][j] == 0) fila.push_back(CellType::Passable);
            else fila.push_back(CellType::Wall);

        }

        this->map.push_back(fila);

    }
    
}

int Maze::getWidth(){
    return width;
}

int Maze::getHeight(){
    return height;
}
