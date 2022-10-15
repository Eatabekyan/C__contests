List list_create(){
    return NULL;
};
void list_push(List * plist, Data x){
   List l = malloc(sizeof(struct Node));
   l->next = *plist;
   l->val = x;
   *plist = l; 
};
/////////////////
void list_print(List list){
    if(list == NULL){
        printf("Empty list\n");
        return;
    }
    List l = list;
    while(l){
        printf("%d ",l->val);
        l = l->next;	
    }
    printf("\n");
};
////////////////////
void list_clear(List * plist){
    List li = *plist;
    List l;
    while(li){
        l = li->next;
        free(li);
        li = l;	
    }
    *plist = NULL;
};
////////////////////////////
Data list_pop(List * plist){
    if(*plist != NULL){
        List li = *plist;
        Data x = li->val;
        *plist = li->next;
        free(li);
        return x;
    }
    return 0;
};
///////////////////
Data list_get(List list){
    return list->val;
};
//////////////////////
int list_size(List list){
    List l = list;
    int s=0;	
    while(l){
        s++;
        l = l->next;	
    }
    return s;
};
////////////////////////////
int list_is_empty(List list){
    if(list == NULL)
        return 1;
    return 0;

};
