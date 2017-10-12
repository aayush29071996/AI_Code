//
// Created by Saswat Das on 10/10/17.
//

#include <iostream>

using namespace std;

#define MAX 5

struct BLOCK {
    int len;
    int where;
    int pos;
    int list[MAX];
} block[MAX];

void move_block(int B) {
    int i, A, P, L;
    A = block[B].where;
    P = block[B].pos + 1;
    L = block[A].len;

    for(i = P; i<L; i++) {
        int B = block[A].list[i];
        block[B].where = B;
        block[B].pos = block[B].len;
        block[B].list[block[B].len++] = B;
    }
    block[A].len = P;
}

void move(int B1, int B2) {
    int i,A,B,P,L,T;
}


