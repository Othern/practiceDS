#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int exp;
    float cof;
    struct _node* next;
}node;
node* create_polynominals(int num,float cof[num],int exp[num]);
void print_polynominals(node* head);
node *add(node *A, node *B);

int main(){
    float cof[] = {6,-1,2,3,4,5};
    int exp[] = {0,1,2,3,4,9};
    node* A = create_polynominals(6,cof,exp);
    node *B = create_polynominals(6, cof, exp);
    node *C = add(A, B);
    print_polynominals(C);
}

node* create_polynominals(int num,float cof[num], int exp[num]){
    int i;
    node* tp = (node *)malloc(sizeof(node));
    node* head = tp;
    for(i = 0;i<num;i++){
        node *temp = (node *)malloc(sizeof(node));
        temp->cof = cof[i];
        temp->exp = exp[i];
        temp->next = NULL;

        tp->next = temp;
        tp = tp->next;
    }
    return head->next;
}
void print_polynominals(node *head){
    for(;head; head = head->next){
        if(head->cof > 0){
            printf("+");
        }
        printf("%.0f*x^%d",head->cof,head->exp);
    }
}
node *add(node *A, node *B){
    node* temp = (node *)malloc(sizeof(node));
    node* r = temp;
    while(A && B){
        node* tp = (node *)malloc(sizeof(node));
        tp->next = NULL;
        if(A->exp < B->exp){
            tp->cof = A->cof;
            tp->exp = A->exp;
            A = A->next;
        }
        else if(A->exp == B->exp){
            tp->cof = A->cof+B->cof;
            tp->exp = A->exp;
            A = A->next;
            B = B->next;
        }
        else{
            tp->cof = B->cof;
            tp->exp = B->exp;
            B = B->next;
        }
        temp->next = tp;
        temp = temp->next;
    }
    while(A){
        node *tp = (node *)malloc(sizeof(node));
        tp->next = NULL;
        tp->cof = A->cof;
        tp->exp = A->exp;
        temp->next = tp;
        temp = temp->next;
        A = A->next;

    }
    while(B){
        node *tp = (node *)malloc(sizeof(node));
        tp->next = NULL;
        tp->cof = B->cof;
        tp->exp = B->exp;
        temp->next = tp;
        temp = temp->next;
        B = B->next;
    }
    return r->next;
}