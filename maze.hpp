#ifndef MAZE_HPP
#define MAZE_HPP

#include <utility>
#include <vector>

enum CellType {
    Passable = 0,
    Wall = 1,
    Start = 2,
    Exit = 3
};

class Maze {
    
    private:
        int width;
        int height;
        void setupVisited();
        void setupMap(std::vector<std::vector<int>>);
        std::vector<std::vector<CellType>> map;
        
    public:
        std::vector<std::vector<bool>> visited;

        Maze(std::vector<std::vector<int>>, int, int, int, int, int, int);
        ~Maze();
        bool isPassable(int, int);
        CellType getCellType(int, int);
        int getWidth();
        int getHeight();
};


#endif