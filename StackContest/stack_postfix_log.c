#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int n;
    int * c;
};


struct Stack * create();
void push(struct Stack * s, int x);
int pop(struct Stack * s);
void destroy(struct Stack * s);

struct Stack * create() {
    struct Stack * s = malloc(sizeof(struct Stack));
    s->c = (int*)calloc(100002, sizeof(int));
    s->n = 0;
    return s;
}
;

void push(struct Stack * s, int x) {
    s->c[s->n] = x;
    s->n++;
}
;

int pop(struct Stack * s) {
    s->n--;
    return s->c[s->n];
}
;

void destroy(struct Stack * s) {
    free(s->c);
    free(s);
}
;



int main() {
    char c;
    int x = 0, y = 0;
    struct Stack * s = create();
    while(1) {
        scanf("%c", &c);
        switch(c) {
            case '!':
                x = pop(s);
                push(s, !x);
                break;
            case '|':
                x = pop(s);
                y = pop(s);
                push(s, x || y);
                break;
            case '&':
                x = pop(s);
                y = pop(s);
                push(s, x && y);
                break;
            case '=':
                printf("%d", s->c[0]);
                destroy(s);
                return 0;
            default:
                push(s,c-'0');
        }
    }
    printf("%d", s->c[0]);
    destroy(s);
    return 0;
}

