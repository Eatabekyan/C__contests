#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int n;
    char * c;
};


struct Stack * create();
void push(struct Stack * s, char x);
char pop(struct Stack * s);
void destroy(struct Stack * s);

struct Stack * create() {
    struct Stack * s = malloc(sizeof(struct Stack));
    s->c = (char*)calloc(100002, sizeof(char));
    s->n = 0;
    return s;
};

void push(struct Stack * s, char x) {
    s->c[s->n] = x;
    s->n++;
};

char pop(struct Stack * s) {
    if(s->n == 0) {
        return 'x';
    }
    s->n--;
    return s->c[s->n];
};

void destroy(struct Stack * s) {
    free(s->c);
    free(s);
};



int main() {
    char * c = malloc(sizeof(char) * 100002);
    scanf("%s", c);
    struct Stack * s = create();
    for(int i = 0 ; i <strlen(c) ; i++) {
        if(c[i] == '{' || c[i] == '[' || c[i] == '(' || c[i] == '<') {
            push(s,c[i]);
        } else {
            switch(c[i]) {
                case '}':
                    if(pop(s) != '{') {
                        printf("NO\n");
                        free(c);
                        destroy(s);
                        return 0;
                    }
                    break;
                case ']':
                    if(pop(s) != '[') {
                        printf("NO");
                        free(c);
                        destroy(s);
                        return 0;
                    }
                    break;
                case '>':
                    if(pop(s) != '<') {
                        printf("NO");
                        free(c);
                        destroy(s);
                        return 0;
                    }
                    break;
                case ')':
                    if(pop(s) != '(') {
                        printf("NO");
                        free(c);
                        destroy(s);
                        return 0;
                    }
                    break;
                
            }
        }
    }
    if(s->n == 0) {
        printf("YES\n");
    } else {
        printf("NO");
    }
    free(c);
    destroy(s);
    return 0;
}

