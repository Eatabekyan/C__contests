struct Node * list_create(){
    return NULL;
};
struct Node * list_push(struct Node * list, Data x){
    struct Node *n = malloc(sizeof(struct Node));
    n->val = x;
    n->next = list;
    list = n;
    return list; 
};
/////////////////
void list_print(struct Node * list){
    struct Node * l = list;
    if(l == NULL){
        printf("\n");
        return;    
    }
    while(l){
        printf("%d ",l->val);
        l = l->next;	
    }
    printf("\n");
};
////////////////////
struct Node * list_clear(struct Node * list){
    struct Node * li = list;
    struct Node * l;
    while(li){
        l = li->next;
        free(li);
        li = l;	
    }
    list = NULL;
    return list;
};
////////////////////////////
struct Node * list_pop (struct Node * list, Data * px){
    if(list != NULL){
        struct Node * li = list;
        *px = li->val;
        list = li->next;
        free(li);
        return list;
    }
    return NULL;
};
///////////////////
Data list_get(struct Node * list){
    return list->val;
};
//////////////////////
int list_size(struct Node * list){
    struct Node * l = list;
    int s = 0;	
    while(l){
        s++;
        l = l->next;	
    }
    return s;
};
////////////////////////////
int list_is_empty(struct Node * list){
    if(list == NULL)
        return 1;
    return 0;

};
