#include<stdio.h>
#define MAX_ROW 50
#define MAX_COL 50
void enter(float matrix[MAX_ROW][MAX_COL], int &amount_rows, int &amount_columns);
void printMatrix(float matrix[MAX_ROW][MAX_COL], int amount_rows, int amount_columns);
bool isSquareMatrix(int amount_rows, int amount_columns);// là ma trận vuông
float getSumOfRows(float matrix[MAX_ROW][MAX_COL], int amount_rows, int amount_columns, int row);// tong cua 1 hang
float getSumOfColumns(float matrix[MAX_ROW][MAX_COL], int amount_rows, int amount_columns, int col);// tong cua 1 hang
void printSumOfRows(float matrix[MAX_ROW][MAX_COL], int amount_rows, int amount_columns);// tong cua cac hang
void printSumOfColumns(float matrix[MAX_ROW][MAX_COL], int amount_rows, int amount_columns);// tong cua cac hang
int main(){
    float matrix[MAX_ROW][MAX_COL];
    int amount_rows, amount_columns;
    enter(matrix, amount_rows, amount_columns);
    printMatrix(matrix, amount_rows, amount_columns);
    printSumOfRows(matrix, amount_rows, amount_columns);
    printSumOfColumns(matrix, amount_rows, amount_columns);
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
float getSumOfRows(float matrix[MAX_ROW][MAX_COL], int amount_rows, int amount_columns, int row){
    float sum = 0;
    for(int col = 0; col < amount_columns; col++){
        sum+=matrix[row][col];
    }
    return sum;
}
float getSumOfColumns(float matrix[MAX_ROW][MAX_COL], int amount_rows, int amount_columns, int col){
    float sum = 0;
    for(int row = 0; row < amount_rows; row++){
        sum+=matrix[row][col];
    }
    return sum;
}
bool isSquareMatrix(int amount_rows, int amount_columns){
    return amount_rows == amount_columns;
}
void printSumOfRows(float matrix[MAX_ROW][MAX_COL], int amount_rows, int amount_columns){
    float sum = 0;
    printf("\nsum of rows:");
    for(int row = 0; row < amount_rows; row++){
        sum = getSumOfRows(matrix,amount_rows,amount_columns,row);
        printf("%.2f ",sum);
    }
}
void printSumOfColumns(float matrix[MAX_ROW][MAX_COL], int amount_rows, int amount_columns){
    float sum = 0;
    printf("\nsum of columns:");
    for(int col = 0; col < amount_columns; col++){
        sum = getSumOfColumns(matrix,amount_rows,amount_columns,col);
        printf("%.2f ",sum);
    }
}