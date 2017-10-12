//
// Created by Saswat Das on 12/10/17.
//



#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int cols = 100;
const int rows = 100;

class Cell {
public:
    int i;
    int j;

    int f;
    int g;
    int h;
    Cell *previous;
    bool wall;
    list<Cell*> neighbours;
    bool isPath;

    Cell(int i, int j) {
        this->i = i;
        this->j = j;
        this->wall = false;

        if((rand()%100) < 30) {
            this->wall = true;
        }
        this->previous = nullptr;
        this->isPath = false;
    }

    void show() {
        if(this->wall) cout<<"█";
        else if(this->isPath) cout<<".";
        else cout<<" ";
    }

    void addNeighbours();
};

vector<vector<Cell>> grid;
list<Cell*> openSet;
list<Cell*> closedSet;

Cell *startcell;
Cell *endcell;

int huristic(Cell *a, Cell *b) {
    int d = abs(a->i - b->i) + abs(a->j - b->j);
    return d;
}

void Cell::addNeighbours(){
    int i = this->i;
    int j = this->j;

    if(i < cols-1 ) this->neighbours.push_back(&grid[i+1][j]);
    if(i > 0 ) this->neighbours.push_back(&grid[i - 1][j]);
    if(j < rows -1 ) this->neighbours.push_back(&grid[i][j+1]);
    if(j >0 ) this->neighbours.push_back(&grid[i][j-1]);
    if(i>0 && j>0) this->neighbours.push_back(&grid[i - 1][j -1]);
    if(i< cols-1 && j>0) this->neighbours.push_back(&grid[i + 1][j -1]);
    if(i> 0 && j < rows -1) this->neighbours.push_back(&grid[i - 1][j + 1]);
    if(i< cols -1 && j < rows -1) this->neighbours.push_back(&grid[i + 1][j + 1]);
}

int main() {
    srand(time(NULL));
    for(int i = 0; i< rows ;i++) {
        vector<Cell> vcel;
        for(int j = 0; j < cols; j++) {
            vcel.push_back(Cell(i, j));
        }
        grid.push_back(vcel);
    }

    for(int i = 0; i< rows ;i++) {
        for(int j = 0; j < cols; j++) {
            grid[i][j].addNeighbours();
        }
    }

    startcell = &grid[0][0];
    endcell = &grid[rows-1][cols-1];
    startcell->wall = false;
    endcell->wall = false;

    // Add the start cell to the open set that need to be checked
    openSet.push_back(startcell);

    while(!openSet.empty()) {
        Cell *current = openSet.front();
        list<Cell*>::iterator osi;
        for(osi=openSet.begin(); osi != openSet.end(); osi++){
            if((*osi)->f < current->f){
                current = *osi;
            }
        }

        if(current == endcell) {
            Cell *temp = current;

            while(temp->previous != nullptr) {
                temp->isPath = true;
                temp = temp->previous;
            }
            cout<<"Reached\n";
            break;
        }

        openSet.remove(current);
        closedSet.push_back(current);

        list<Cell*>::iterator neighbour;

        for(neighbour = current->neighbours.begin(); neighbour!= current->neighbours.end(); neighbour++){
            if(find(closedSet.begin(), closedSet.end(), *neighbour) == closedSet.end() && !(*neighbour)->wall) {
                int tempG = current->g + 1;

                bool newPath = false;
                if(find(openSet.begin(), openSet.end(), *neighbour) != openSet.end()){
                    if(tempG < (*neighbour)->g) {
                        (*neighbour)->g = tempG;
                        newPath = true;
                    }
                } else {
                    (*neighbour)->g = tempG;
                    newPath = true;
                    openSet.push_back(*neighbour);
                }

                if(newPath) {
                    (*neighbour)->h = huristic(*neighbour, endcell);
                    (*neighbour)->f = (*neighbour)->g + (*neighbour)->h;
                    (*neighbour)->previous = current;
                }
            }
        }
    }

    for(int i =0; i< rows; i++) {
        for(int j=0; j<cols; j++) {
            grid[i][j].show();
        }
        cout<<endl;
    }

    return 0;
}