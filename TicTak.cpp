//
// Created by Saswat Das on 10/10/17.
//

#include <iostream>
#include <stack>
#include <queue>
#include <list>

using namespace std;

char board[3][3]; // We will play on a 3x3 board
enum PLAYER {
    ONE,
    TWO
};


void printBoard() {
    cout<<"\n\n";
    cout<<"\t\t"<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"\t-----------------\n";
    cout<<"\t\t"<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"\t-----------------\n";
    cout<<"\t\t"<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}

void printInst() {
    cout<<"\t\tTic Tac Toe\n";
    cout<<"Choose a cell number from 1-9 to place your marker\n";
    cout<<"\n";
    cout<<"\t\t"<<1<<" | "<<2<<" | "<<3<<endl;
    cout<<"\t-----------------\n";
    cout<<"\t\t"<<4<<" | "<<5<<" | "<<6<<endl;
    cout<<"\t-----------------\n";
    cout<<"\t\t"<<7<<" | "<<8<<" | "<<9<<endl;
    cout<<"\n== == == == = = = == == == == =="<<endl;
}

void intializeBoard() {
    for(int i=0;i<3 ;i++) {
        for(int j=0; j<3;j++){
            board[i][j]=' ';
        }
    }
}

int main() {
    printInst();
    int moves = 0;
    bool gameOver = false;
    PLAYER player;
    intializeBoard();
    do {
        printBoard();
        player = (moves % 2) == 0?ONE:TWO;
        int cell;
        cout<<((player == ONE)?"X> ":"O>");
        cin>>cell;
        int a = (cell-1)/3;
        int b = (cell-1)%3;
        if(board[a][b] == ' '){
            if(player == ONE) board[a][b] = 'X';
            else if(player == TWO) board[a][b] = 'O';
        }else{
            cout<<"marker already placed, choose another cell\n";
            continue;
        }

        // Checking for  row win
        for(int i = 0; i< 3; i++) {
            if(board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][1] !=' '){
                cout<<board[i][0]<<" won!";
                gameOver = true;
                break;
            }
        }
        // Checking for  col win
        for(int i = 0; i< 3; i++) {
            if(board[0][i] == board[1][i] && board[2][i] == board[1][i] && board[1][i] !=' '){
                cout<<board[0][i]<<" won!";
                gameOver = true;
                break;
            }
        }
        // Checking for  diagonal win
        if(board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] !=' '){
            cout<<board[1][1]<<" won!";
            gameOver = true;
            break;
        }
        // Checking for  diagonal win
        if(board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] !=' '){
            cout<<board[1][1]<<" won!";
            gameOver = true;
            break;
        }
        moves++;
    } while (moves < 9 && !gameOver);
    cout<<"\nGAME OVER";
    return 0;
}
