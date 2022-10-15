#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Stack {
    int n;
    int size;
    Data * a; 
};


struct Stack * stack_create(int size);
void stack_push(struct Stack * s, Data x);
Data stack_pop(struct Stack * s);
Data stack_get(struct Stack * s);
void stack_print(struct Stack * s);
int  stack_size(struct Stack * s);
int  stack_is_empty(struct Stack * s);
void stack_clear(struct Stack * s);
void stack_destroy(struct Stack * s);


struct Stack * stack_create(int size) {
    struct Stack * s = malloc(sizeof(struct Stack));
    s->size = size;
    s->n = 0;
    s->a = (int*)calloc(100002, sizeof(Data));
    return s;
};
void stack_push(struct Stack * s , Data x) {
    s->a[s->n] = x;
    s->n++; 
    
};
Data stack_pop(struct Stack * s) {
    s->n--;
    return s->a[s->n];
};


Data stack_get(struct Stack * s) {
    return s->a[s->n-1];
};


void stack_print(struct Stack * s) {
    if(s == NULL || s->n == 0) {
        printf("Empty stack\n");
        return;
    }
    for(int i = 0 ; i < s->n ; i++) {
        printf("%d ", s->a[i]);
    }
    printf("\n");
};



int  stack_size(struct Stack * s) {
    return s->n;
};


void stack_clear(struct Stack * s) {
    free(s);
};

int  stack_is_empty(struct Stack * s) {
    return s->n==0;
};

void stack_destroy(struct Stack * s) {
    free(s->a);
    free(s);
};
int main() {
    struct Stack * sp = stack_create(10);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    stack_push(sp, 5);
    stack_print(sp);
    stack_push(sp, 2);
    stack_print(sp);
    // 5 19 -2

    
    stack_push(sp,4);
    stack_print(sp);
    stack_destroy(sp);
    return 0;
}
