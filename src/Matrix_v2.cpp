#include<stdio.h>
#define MAX_ROW 50
#define MAX_COL 50
void enter(float matrix[MAX_ROW][MAX_COL], int &amount_rows, int &amount_columns);
void printMatrix(float matrix[MAX_ROW][MAX_COL], int amount_rows, int amount_columns);
int main(){
    float matrix[MAX_ROW][MAX_COL];
    int amount_rows, amount_columns;
    enter(matrix, amount_rows, amount_columns);
    printMatrix(matrix, amount_rows, amount_columns);
    return 0;
}
void enter(float matrix[MAX_ROW][MAX_COL], int &amount_rows, int &amount_columns){
    float temp;
    printf("\nAmount rows: ");
    scanf("%d",&amount_rows);
    printf("\nAmount columns: ");
    scanf("%d",&amount_columns);
    for(int row = 0; row < amount_rows; row++){
        for(int col = 0; col < amount_columns; col++){
            printf("\nEnter numbers at row %d , column %d: ",row,col);
            scanf("%f",&temp);
            matrix[row][col] = temp;
        }
    }
}
void printMatrix(float matrix[MAX_ROW][MAX_COL], int amount_rows, int amount_columns){
    for(int row = 0; row < amount_rows; row++){
        for(int col = 0; col < amount_columns; col++){
            printf("%.2f ",matrix[row][col]);
        }
        printf("\n");
    }
}