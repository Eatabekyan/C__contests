void list_init(struct Node * list){
      list->next = list->prev = list;
};
///////////////////////////////////////////////
void list_insert(struct Node * list, struct Node * t){
        struct Node * l = list->next;
        t->next = l;
        l->prev = t;
        list->next = t;
        t->prev = list;
};
////////////////////////////////////////////////
void list_insert_before(struct Node * list, struct Node * t){
    struct Node * l = list;
    while(l->next!=list){
        l = l->next;    
    }
    l->next = t;
    t->prev = l;
    t->next = list;
};
/////////////////////////////////////
struct Node * list_push_front(struct Node * list, Data d){
    struct Node * t = malloc(sizeof(struct Node));
    t->data = d; 
    list_insert(list, t);
    return t; 
    
};
///////////////////////////////////////////////////////
struct Node * list_push_back(struct Node * list, Data d){
    struct Node * t  = malloc(sizeof(struct Node));
    t->data = d;
    list_insert_before(list, t);
    return t;
}
////////////////////////////////////////////
void list_remove(struct Node * t){
    struct Node * tp = t->prev;
    struct Node * tn = t->next;
    tp->next = tn;
    tn->prev = tp;
};
////////////////////////////////////////////
void list_print(struct Node * list){
        struct Node * l = list->next;
        while(l != list){
            printf("%d ",l->data);
            l = l->next;	
        }
    printf("\n");
};

////////////////////
void list_clear(struct Node * list){
    struct Node * li = list->next;
    struct Node * l;
    while(li != list){
        l = li->next;
        free(li);
        li = l;	
    }
    list->prev = list->next =list;
};
////////////////////////////
Data list_pop_front(struct Node * list){
        struct Node * li = list -> next;
        return list_delete(li);

};
//////////////////////////////////
Data list_pop_back(struct Node * list){
        struct Node * li = list;
        while(li->next != list){
            li = li->next;        
        }
        return list_delete(li);
};
//////////////////////////////
Data list_delete(struct Node * t){
    Data x = t->data;
    list_remove(t);
    free(t);
    return x;
};

////////////////////////////
int list_is_empty(struct Node * list){
    if(list == list->next && list->prev == list)
        return 1;
    return 0;

};
