#include <stdio.h>
#include <stdlib.h>
#define MAX_TERM 101
typedef struct 
{
    int term_num;
    int max_row;
    int max_column;
    int row[MAX_TERM];
    int column[MAX_TERM];
    float value[MAX_TERM];
} sparseMatrix;
sparseMatrix* create_sparseMatrix(int term_num,int max_row,int max_column,int row[term_num],int column[term_num],float value[term_num]);
void print_sparseMatrix(sparseMatrix* x);
sparseMatrix* transpose_sparseMatrix(sparseMatrix* x);
int main(){
    int row[] = {0,1,1,1,3,4,5,7};
    int column[] = {1,0,1,4,2,3,5,6};
    float value[] = {8,8,8,8,8,8,8,8};
    sparseMatrix* A= create_sparseMatrix(8,8,8,row,column,value);
    //print_sparseMatrix(A);

    printf("\n");
    sparseMatrix* B = transpose_sparseMatrix(A);
    printf("%d",B->column[0]);
    print_sparseMatrix(B);
}
sparseMatrix* create_sparseMatrix(int term_num,int max_row,int max_column,int row[term_num],int column[term_num],float value[term_num]){
    sparseMatrix* r = (sparseMatrix *)malloc(sizeof(sparseMatrix));
    r->term_num = term_num;
    r->max_row = max_row;
    r->max_column = max_column;
    int i;
    for(i = 0; i<term_num;i++){
        r->column[i] = column[i];
        r->row[i] = row[i];
        r->value[i] = value[i];
    }
    return r;
}
void print_sparseMatrix(sparseMatrix* x){
    int i ,j ;
    int k = 0;
    for(i = 0;i<x->max_row;i++){
        for(j = 0;j<x->max_column;j++){
            if(i == x->row[k]&& j == x->column[k]){
                printf("%.0f,",x->value[k]);
                k+=1;
            }
            else{
                printf("0,");
            }
        }
        printf("\n");
    }
}
sparseMatrix* transpose_sparseMatrix(sparseMatrix* x){
    sparseMatrix* r = (sparseMatrix *)malloc(sizeof(sparseMatrix));
    r->term_num = x->term_num;
    r->max_column = x->max_row;
    r->max_row = x->max_column;
    int i ,j;
    for(;i<x->term_num;i++){
        r->row[i] = x->column[i];
        r->column[i] = x->row[i];
        r->value[i] = x->value[i];
    }
    
    return r;
}