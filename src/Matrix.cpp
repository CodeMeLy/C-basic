#include <stdio.h>
#define MAX_ROW 50
#define MAX_COL 50
void enterMatrix(int matrix[MAX_ROW][MAX_COL],int &row_numbers, int &column_numbers);
void printMatrix(int matrix[MAX_ROW][MAX_COL], int row_numbers, int column_numbers);
int main(){
    int matrix[MAX_ROW][MAX_COL];
    int row_numbers, col_numbers;
    enterMatrix(matrix,row_numbers,col_numbers);
    printMatrix(matrix,row_numbers,col_numbers);
    return 0;
}
void enterMatrix(int matrix[MAX_ROW][MAX_COL],int &row_numbers, int &column_numbers){
    int temp;
    printf("\nEnter number of row: ");
    scanf("%d",&row_numbers);
    printf("Enter number of column: ");
    scanf("%d",&column_numbers);
    printf("Enter value of element in matrix: \n");
    for(int row = 0; row < row_numbers; row++){
        for(int col = 0; col < column_numbers; col++){
            printf("at row = %d, col = %d: ", row,col);
            scanf("%d",&temp);
            matrix[row][col] = temp;
        }
    }
}
void printMatrix(int matrix[MAX_ROW][MAX_COL], int row_numbers, int column_numbers){
    printf("\nmatrix: \n");
    for(int row = 0; row < row_numbers; row++){
        for(int col = 0; col < column_numbers; col++){
            printf("%d ",matrix[row][col]);
        }
        printf("\n");
    }
}