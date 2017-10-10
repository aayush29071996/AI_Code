//
// Created by Saswat Das on 10/10/17.
//

#include <iostream>


void generateSquare(int n) {

    int square[n][n];
    memset(square, 0, sizeof(square));

    int i = n/2;
    int j = n-1;

    for(int num=1; num <= n*n;) {
        if(i==-1 && j==n) {
            j = n-2;
            i = 0;
        } else {
            if(j == n) j=0;
            if(i < 0) i = n-1;
        }

        if(square[i][j]) {
            j-=2;
            i++;
            continue;
        } else
            square[i][j] = num++;
        j++; i--;
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%3d ",square[i][j]);
        printf("\n");
    }
}

int main (){
    int n = 7;
    generateSquare(n);
    return 0;
}