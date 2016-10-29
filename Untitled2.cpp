/***********************************************************************
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 264 - Count on Cantor
 *
 * Technique: Zig Zag / Spiral Diagonal traversal,
 *            2D struct array,
 *            2D half diagonal fill,
 *            Recursive Dynamic Programming
 ***********************************************************************/


#include<stdio.h>
#include<string.h>

// N * N should be almost twice greater than or equal to M.
// Or, N should be such that N*(N+1)/2 is greater than M.
#define N 4500


#define M 10000000


/**
 * Table to construct the sequence
 */
struct CantorTable{
    int numerator;
    int denominator;
} CT[N][N];


// Holds cantor values from 1 to M by index
CantorTable OrderedCantor[M];


/**
 * Fill in the cantor table.
 */
void CantorFill(){

    for(int row = 0; row < N; ++row){

        int cutoff = N - row;

        for(int col = 0; col < cutoff; ++col){
            CT[row][col].numerator   = row + 1;
            CT[row][col].denominator = col + 1;
        }

    }

}


void RecursiveCantor(int r, int c, int index, int diagonal){

    // base case
    if( r < 0 || c < 0 || index > M ){
        return;
    }


    OrderedCantor[index].numerator = CT[r][c].numerator;
    OrderedCantor[index].denominator = CT[r][c].denominator;



    // Amount of times to travel in diagonal
    ++diagonal;



    if(r == 0){

        // when odd move down left
        if(c % 2){
            for(int i = 0; i <c+diagonal ; ++i){
                ++index;
                r = r + 1;
                c = c - 1;
                RecursiveCantor( r, c, index, diagonal );
            }
        }

        // when even Move right
        else{
            ++index;
            c = c + 1;
            RecursiveCantor( r, c, index, diagonal );
        }
    }

    if(c == 0){

        // when odd move down
        if(r % 2){
            ++index;
            r = r + 1;
            RecursiveCantor( r, c, index, diagonal );
        }

        // when even Move up right
        else{
            for(int i = 0; i <r+diagonal ; ++i){
                ++index;
                r = r - 1;
                c = c + 1;
                RecursiveCantor( r, c, index, diagonal );
            }
        }

    }

}



int main() {


    // Initialize Cantor table
    CantorFill();


    // Pass in row, column, index, diagonal traversal size
    RecursiveCantor(0, 0, 1, 0);


    int n;


    while( scanf("%d", &n) == 1 ){
        printf("TERM %d IS %d/%d\n", n, OrderedCantor[n].numerator, OrderedCantor[n].denominator );
    }

    return 0;
}
