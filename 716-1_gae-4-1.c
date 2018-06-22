#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} node;

typedef node* stack;


int init(stack *root){
    *root = NULL;
    return 1;
}

// удаление списка
int destroy(stack *root){
    stack tmp;
    while(*root != NULL){
        tmp = *root;
        *root = (*root)->next;
        free(tmp);
    }
    return 1;
}

// проверка списка на пустоту
bool isEmpty(stack root){
    if(root != NULL) return 1;
    else return 0;
}

// добавление элемента в стек
int push(stack *stk, int value){
    if(((*stk) == NULL)){
        stack tmp = (stack)malloc(sizeof(node));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = NULL;
        *stk = tmp;
        return 1;
    }else{
        stack tmp = (stack)malloc(sizeof(node));
        tmp->prev = NULL;
        tmp->value = value;
        tmp->next = *stk;
        (*stk)->prev = tmp;
        (*stk) = tmp;
        return 1;
    }
}

// Удаление элемента из стека
stack pop(stack *stk){
    stack tmp = *stk;
    if (((*stk)->next != NULL) && ((*stk)->prev == NULL)) {
        (*stk)->next->prev = NULL;
        (*stk) = (*stk)->next;
    }
    return tmp;
}


int print(stack *stk){
    stack tmp = *stk;
    do{
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    while( tmp != NULL);

    printf("\n");

    return 1;
}

int main()
{
    stack root, tmp;
    init(&root);

    int n, i, k, a, x, b;
    // 1
    scanf("%d", &n);
    while(n<0){
        printf("Error! Invalid number\n");
        scanf("%d", &n);
    }
    scanf("%d", &x);
    push(&root, x);

    // 2
    for(i = 1; i<n; i++){
        scanf("%d", &x);
        tmp = root;
        push(&root, x);
        tmp = tmp->prev;
    }
    print(&root);

    // 3
    scanf("%d", &k);

    while(n<k){
        printf("Error! Invalid number\n");
        scanf("%d", &k);
    }

    tmp = root;
    for(i=0; i<k; i++){
        tmp = tmp->next;
        pop(&root);
    }

    print(&root);

    // 5
    scanf("%d%d", &a, &b);
    tmp = root;
    for(i=1; i<=a; i++){
        tmp=tmp->next;
        pop(&root);
    }
    push(&root, b);

    print(&root);
    return 0;
}

