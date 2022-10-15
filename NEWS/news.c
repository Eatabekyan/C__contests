#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// для временного хранения данных, считанных из файла
typedef  struct TR{
  char name[20]; // имя жителя
  char sosed[20]; // имя соседа
  short int status; // статус (1 - рыцарь, 0 - ложь)
}TmpRes;

// описание жителя города
typedef  struct Res{
  char name[20]; // имя жителя
  char status;  // статус (1 - рыцарь, 0 - ложь)
}Villager;

// описание дома жителя
typedef struct D{
   Villager vllgr; // житель
   struct D *right; // указатель на соседа справа
}Dom;

// описание горока
typedef struct Cn{
  Dom * tzar; // указатель на первый дом
// предполагается, что это начало односвязного циклического списка,
// описывающего деревню
  Dom * last; // указатель на последний дом
  int n;   // количество домов
}Country;

// получение данных из файла
TmpRes * getData(FILE *f, int *n);

// печать плана города в формате
// царь(статус)->житель1(статус)->...->царь(статус)
void prCountry(Country *cnt);

// строим деревню из временного хранилища, где
// n - количество элементов в tm, а 
// gde - номер вставляемого элемента в список cnt
void bildCountry(TmpRes* tm, int n, int gde, Country* cnt);

// освобождение памяти, занятой под список
void destroyCountry(Country* cnt);

// моделирование одного дня жизни деревни
// nw - статус новости (1 - истина, 0 - ложь)
// функция возращает статус новости в конце дня
// новость в этом статусе поступает к царю в начале 
// следующего дня
int oneDay(Country *cnt, int nw);


/////////////////////////////////////////////////////////////////////////////////

TmpRes * getData(FILE *f, int *n) {
    int s = *n;
    TmpRes * t = (TmpRes *)malloc(s*sizeof(TmpRes));
    char buff[20];
    for(int i = 0; i<s ; i++) {
        fscanf(f, "%s", buff);
        strcpy(t[i].name, buff);
        fscanf(f, "%s", buff);
        strcpy(t[i].sosed, buff);
        fscanf(f, "%s", buff);
        t[i].status = buff[0]-'0';
        
    }    
    fclose(f);
    return t;    
};

void bildCountry(TmpRes* tm, int n, int gde, Country* cnt) {
    cnt->tzar = (Dom *) malloc((n+2)*sizeof(Dom));
    cnt->n = 0;
    for(int j = 0; j<n;j++){
        strcpy(cnt->tzar[cnt->n].vllgr.name, tm[gde].name);
        cnt->tzar[cnt->n].vllgr.status = tm[gde].status + '0';
        cnt->n++;
        cnt->last = &(cnt->tzar[cnt->n-1]);
        
        for(int i = 0; i<n; i++) {
            if(!strcmp(tm[i].name, tm[gde].sosed)) {
                gde = i;
                break;
            }
        }
    }
    for(int i = 0; i<n-1; i++) {
            cnt->tzar[i].right = &(cnt->tzar[i+1]);
    }
    cnt->last->right = cnt->tzar;
    free(tm);
};

void prCountry(Country* cnt) {
    Dom* p = cnt->tzar;
    for(int i = 0; i < cnt->n; i++){
        printf("%s(%c)->", p->vllgr.name, p->vllgr.status);
        p=p->right; 
    }
    printf("%s(%c)\n", cnt->tzar->vllgr.name, cnt->tzar->vllgr.status);
};

int oneDay(Country * cnt, int nw) {
    Dom* p = cnt->tzar;
    int ne = nw ;
    p = cnt->last;
    Dom * s;
    
    while(1) {
        if(p == cnt->tzar || cnt->n == 1) {
            return ne;
        }  
    	if (p->vllgr.status == '0') {
		    if(ne == 0) {
		        ne = 1;
		    }else{
		        ne = 0;
		    }    	
    	}
        s = p;
        for(int i = 0 ;i < cnt->n-1;i++){
            p=p->right;
         } 
        if(ne == 0 && s->vllgr.status == '1') {
            p->right = s->right;
            cnt->n--;
            cnt->last=&(cnt->tzar[cnt->n-1]);
        }
        if(ne == 1 && s->vllgr.status == '0') {
            s->vllgr.status = '1';
        }
        
    }
    
};

void runNews(Country * cnt, int news, int days) {
    for(int i=0;i<days;i++){
        oneDay(cnt, news);
        prCountry(cnt);
    }
};
void destroyCountry(Country* cnt) {
    free(cnt->tzar);
};




int main(){
    printf("ТЕСТ1\n");
    int n = 9;//ТЕСТ1
    TmpRes * t = getData(fopen("./test1.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    Country cnt;
    bildCountry(t, n, 0, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 1);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 0, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    printf("ТЕСТ2\n");
    n = 9;
    t = getData(fopen("./test1.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    bildCountry(t, n, 0, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 0);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 0, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    printf("ТЕСТ3\n");
    n = 9;
    t = getData(fopen("./test1.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    bildCountry(t, n, 0, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 1);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 1, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    printf("ТЕСТ4\n");
    n = 9;
    t = getData(fopen("./test1.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    bildCountry(t, n, 0, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 0);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 1, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    printf("ТЕСТ5\n");
    n = 8;
    t = getData(fopen("./test2.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    
    bildCountry(t, n, 7, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 0);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 0, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    printf("ТЕСТ6\n");
    n = 8;
    t = getData(fopen("./test2.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    
    bildCountry(t, n, 7, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 0);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 1, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    printf("ТЕСТ7\n");
    n = 8;
    t = getData(fopen("./test2.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    
    bildCountry(t, n, 7, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 1);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 0, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    printf("ТЕСТ8\n");
    n = 8;
    t = getData(fopen("./test2.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    
    bildCountry(t, n, 7, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 1);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 1, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    printf("ТЕСТ9\n");
    n = 9;
    t = getData(fopen("./test3.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    
    bildCountry(t, n, 0, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 0);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 0, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    printf("ТЕСТ10\n");
    n = 9;
    t = getData(fopen("./test3.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    
    bildCountry(t, n, 0, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 1);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 0, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    
    printf("ТЕСТ11\n");
    n = 9;
    t = getData(fopen("./test3.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    
    bildCountry(t, n, 0, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 0);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 1, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    
    printf("ТЕСТ12\n");
    n = 9;
    t = getData(fopen("./test3.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    
    bildCountry(t, n, 0, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 1);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 1, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    
    printf("ТЕСТ13\n");
    n = 11;
    t = getData(fopen("./test4.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    
    bildCountry(t, n, 0, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 0);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 0, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    
    printf("ТЕСТ14\n");
    n = 11;
    t = getData(fopen("./test4.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    
    bildCountry(t, n, 0, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 1);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 0, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    
    printf("ТЕСТ15\n");
    n = 11;
    t = getData(fopen("./test4.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    
    bildCountry(t, n, 0, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 0);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 1, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    
    
    
    printf("\n\n\n\n\n");printf("\n\n\n\n\n");printf("\n\n\n\n\n");
    
    
    
    printf("ТЕСТ16\n");
    n = 11;
    t = getData(fopen("./test4.txt", "r"), &n);
    for(int i =0;i<n;i++) {
        printf("%s:", t[i].name);
        printf("%s:", t[i].sosed);
        printf("%u\n\n\n\n",t[i].status);
    }
    
    
    bildCountry(t, n, 0, &cnt);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    oneDay(&cnt, 1);
    prCountry(&cnt);
    printf("\n\n\n\n\n");
    runNews(&cnt, 1, 10);
    prCountry(&cnt);
    destroyCountry(&cnt);
    return 0;
}















