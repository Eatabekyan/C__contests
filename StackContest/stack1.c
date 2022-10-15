#include <stdio.h>
#include <stdlib.h>

#define N 100
typedef int Data;

struct Stack {
    int n;
    Data a[N];
};

void stack_create(struct Stack * s);
void stack_push(struct Stack * s, Data x);
Data stack_pop(struct Stack * s);
Data stack_get(struct Stack * s);
void stack_print(struct Stack * s);
int  stack_size(struct Stack * s);
void stack_clear(struct Stack * s);

void stack_create(struct Stack * s) {
    s->n = 0;
};


void stack_push(struct Stack * s, Data x) {
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


int main() {
    struct Stack s;
    stack_create(&s);
    stack_push(&s, 5);
    stack_print(&s);
    stack_push(&s, 19);
    stack_print(&s);
    int x = stack_size(&s);
    printf("size=%d\n", x);
    x = stack_pop(&s);
    printf("x=%d\n", x);
    stack_print(&s);
    x = stack_pop(&s);
    printf("x=%d\n", x);
    stack_print(&s);
    stack_clear(&s);
    return 0;
}
