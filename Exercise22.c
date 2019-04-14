//Tsotras Stefanos icsd13189
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S 100



//DOMH VIVLIOU
typedef struct book{
    char *title;
    char *writer;
    char *genre;
    char *desc;
    float pop;
    struct book *next;
    struct book *prev;
}book;

book *head=NULL;
book *tail=NULL;


//DHLWSH SYNARTHSEWN
void displayAll();
void addBook();
void checkPop(book *node);
void displayBook();
void swapElements(book *node1, book *node2);
void deleteBook(char *title);
int countBooks();
void displayPopular();
void displayLPopular();

int main(){

//DHLWSH METAVLHTWN
int i,select;
char con='y';
char *title;

while(con == 'y'){
    //MENU
    printf(" Menu \n1. Insert a Book\n2. Print list\n3. View a Book\n4. Delete a Book\n5. View number of books in list\n6. View most popular books\n7. View least popular books\nInput : ");
    scanf("%d",&select);
    printf("\n\n");
    switch(select){
        case 1 :
            addBook();
            break;
        case 2 :
            displayAll();
            break;
        case 3 :
            displayBook();
            break;
        case 4 :
            title=(char *)malloc(S*sizeof(char ));
            //DIAVASMA APTON XRHSTH
            fflush(stdin);
            printf("Dwse ton titlo tou vivliou pou thes na diagrapseis : ");
            fgets(title,S,stdin);
            deleteBook(title);
            break;
        case 5 :
            printf("H lista exei %d vivlia",countBooks());
            break;
        case 6 :
            displayPopular();
            break;
        case 7 :
            displayLPopular();
            break;
        default :
            printf("Wrong input!");
    }

    //FLUSH INPUT BUFFER
    fflush(stdin);
    printf("Press y to continue or anything else to quit ");
    scanf("%c",&con);
    printf("\n");
}


}

//SYNARTHSH EISAGWGHS VIVLIOU STH LISTA
void addBook(){

//DHLWSH KAI DESMEUSH MNHMHS GIA TIS IDIOTITES TOU VIVLIOU
char *title=(char *)malloc(S*sizeof(char ));
char *writer=(char *)malloc(S*sizeof(char ));
char *genre=(char *)malloc(S*sizeof(char ));
char *desc=(char *)malloc(S*sizeof(char ));

//DIAVASMA APTON XRHSTH
fflush(stdin);
printf("Dwse ton titlo tou vivliou : ");
fgets(title,S,stdin);

fflush(stdin);
printf("Dwse ton suggrafea tou vivliou : ");
fgets(writer,S,stdin);

fflush(stdin);
printf("Dwse to eidos tou vivliou : ");
fgets(genre,S,stdin);

fflush(stdin);
printf("Dwse mia perigrafh tou vivliou : ");
fgets(desc,S,stdin);
printf("\n\n");

//DHMIOURGIA TOU KAINOURGIOU KOMVOU KAI DESMEUSH MNHMHS
book *current;
current = (struct book*) malloc(sizeof(struct book));

//EISXWRHSH TWN METAVLHTWN STON KOMVO
current->title=title;
current->writer=writer;
current->genre=genre;
current->desc=desc;
current->pop=0;

//AN EINAI ADEIA H LISTA
if(head == NULL){
    current->next = NULL;
    current->prev = NULL;
    head = current;

}
else{
    //DIASXISH LISTAS
    book *tmp = head;
    while(tmp->next != NULL){
        //AN O TITLOS UPARXEI HDH STH LISTA EMFANISH MYNHMATOS KAI EPISTROFH
        if(strcmp(tmp->title,current->title) == 0){
                printf("The book is already inside the list\n\n");
                return;
        }
        tmp=tmp->next;
    }
    //AN DEN VRETHEI O TITLOS STH LISTA TOTE
    //EISXWRHSH TOU KOMVOU STO TELOS
    tmp->next= current;
    current->next = NULL;
    current->prev = tmp;

}
tail = current;

}


void swapElements(book *node1, book *node2){

char *title=(char *)malloc(S*sizeof(char ));
char *writer=(char *)malloc(S*sizeof(char ));
char *genre=(char *)malloc(S*sizeof(char ));
char *desc=(char *)malloc(S*sizeof(char ));
float popularity;

//PROSWRINH APOTHIKEUSH TWN STOIXEIWN THS NODE2
title = node2->title;
writer = node2->writer;
genre = node2->genre;
desc = node2->desc;
popularity = node2->pop;

//PERASMA TWN STOIXEIWN TOU 1OU KOMVOU STON DEUTERO
node2->title = node1->title;
node2->writer = node1->writer;
node2->genre = node1->genre;
node2->desc = node1->desc;
node2->pop = node1->pop;

//PERASMA TWN STOIXEIWN TOU 2OU KOMVOU STON 1O
node1->title = title;
node1->writer = writer;
node1->genre = genre;
node1->desc = desc;
node1->pop = popularity;
}


void checkPop(book *node){

//AN EINAI O MONADIKOS KOMVOS H O PRWTOS TOTE EPISTREFEI
if(node == head){
    return;
}
book *tmp = node->prev;
//DIASXISH LISTAS APO TO PROHGOUMENO STOIXEIO APTO DIKO MAS
//MEXRI NA FTASEI STO HEAD->PREV POU EINAI NULL
while(tmp != NULL){
    //AN EXEI PARAPANW DHMOTIKOTITA APO ENA STOIXEIO
    //TOTE TA ALLAZEI KAI VGENEI
    if(tmp->pop < node->pop){
        swapElements(tmp,node);
    }
    //AN EXOUN IDIA DHMOTIKOTHTA
    else if(tmp->pop == node->pop){
        //KAI TO STOIXEIO MAS EINAI ALFAVITIKA MIKROTERO
        //TOTE TA ALLAZEI KAI VGENEI
        if(tolower(tmp->title[0]) > tolower(node->title[0])){
            swapElements(tmp,node);
        }
    }
    tmp = tmp->prev;
}

}

void deleteBook(char *title){

//AN H LISTA EINAI ADEIA EPISTREFEI
if(head == NULL){
    printf("The list is empty!\n\n");
    return;
}

//DIASXISH LISTAS
book *tmp = head;
//GIA OSO DEN VRISKEI TON TITLO
while(strcmp(tmp->title,title) != 0){
    //AN EFTASE MEXRI TON TELEUTAIO KOMVO
    //KAI DEN TO VRIKE TOTE EPISTREFEI
    if(tmp->next == NULL){
        printf("Book not found!\n\n");
        return;
    }
    else{
        //ALLIWS PROXWRAEI STO EPOMENO
        tmp = tmp->next;
    }
}

//AFOU VGIKE APO THN WHILE VRIKE TON TITLO

//AN VRISKETE STON PRWTO KOMVO
if(tmp == head){
    //TO HEAD DEIXNEI PIA STON EPOMENO KOMVO
    head = head->next;
    //KAI TO PREV TOU NEOU PIA HEAD EINAI NULL
    head->prev = NULL;
    //APELEYTHERWSH MNHMHS
    free(tmp);
}
//AN VRISKETE STON TELEUTAIO KOMVO
else if(tmp == tail){
    //TO TAIL DEIXNEI PIA STON PROIGOUMENO KOMVO
    tail = tmp->prev;
    //KAI TO NEXT TOU NEOU PIA TAIL EINAI NULL
    tail->next = NULL;
    free(tmp);
}
else{
    //TO PROHGOUMENO STOIXEIO DEIXNEI EKEI POU EDEIXNE
    //AUTO POU THA DIAGRAFTEI
    tmp->prev->next = tmp->next;
    free(tmp);
}

}

int countBooks(){

int count=0;

//AN H LISTA EINAI ADEIA EPISTREFEI
if(head == NULL){
    return 0;
}
//DIASXISH LISTAS
book *tmp = head;
while(tmp != NULL){
    count++;
    tmp = tmp->next;
}
return count;
}


void displayPopular(){

//AN H LISTA EINAI ADEIA EPISTREFEI
if(head == NULL){
    printf("The list is empty!\n\n");
    return;
}
printf("Most popular books : ");
//DIASXISH LISTAS
book *tmp = head;

while(tmp != NULL){
    //EMFANIZEI TA VIVLIA POU EXOUN IDIA DHMOTIKOTHTA ME TO PRWTO
    //VIVLIO STH LISTA POU EINAI KAI TO PIO DHMOFILES
    if(tmp->pop == head->pop){
        printf("Title       : %sWriter      : %sGenre       : %sDescription : %sPopularity : %.2f\n\n",tmp->title,tmp->writer,tmp->genre,tmp->desc,tmp->pop);
    }
    tmp = tmp->next;
}
}

void displayLPopular(){

//AN H LISTA EINAI ADEIA EPISTREFEI
if(head == NULL){
    printf("The list is empty!\n\n");
    return;
}
printf("Least popular books : ");
//DIASXISH LISTAS
book *tmp = tail;

while(tmp != NULL){
    //EMFANIZEI TA VIVLIA POU EXOUN IDIA DHMOTIKOTHTA ME TO TELEUTAIO
    //VIVLIO STH LISTA POU EINAI KAI TO LIGOTERO DHMOFILES
    if(tmp->pop == tail->pop){
        printf("Title       : %sWriter      : %sGenre       : %sDescription : %sPopularity : %.2f\n\n",tmp->title,tmp->writer,tmp->genre,tmp->desc,tmp->pop);
    }
    tmp = tmp->prev;
}

}


//SUNARTHSH EMFANISHS OLWN TWN VIVLIWN STH LISTA
void displayAll(){
int count=0;

//AN H LISTA EINAI ADEIA EPISTREFEI
if(head == NULL){
    printf("The list is empty!\n\n");
    return;
}
//DIASXISH LISTAS
book *tmp = head;
while(tmp != NULL){
    count++;
    //EMFANISH TWN STOIXEIWN TOU VIVLIOU
    printf("   Book %d\nTitle       : %sWriter      : %sGenre       : %sDescription : %sPopularity : %.2f\n\n",count,tmp->title,tmp->writer,tmp->genre,tmp->desc,tmp->pop);
    tmp = tmp->next;
}
}

//EMFANISH SYGKEKRIMENOU VIVLIOU VASH TITLOU
void displayBook(){

//AN H LISTA EINAI ADEIA EPISTREFEI
if(head == NULL){
    printf("The list is empty!\n\n");
    return;
}

char *title=(char *)malloc(S*sizeof(char ));
//DIAVASMA APTON XRHSTH
fflush(stdin);
printf("Dwse ton titlo tou vivliou pou psaxneis : ");
fgets(title,S,stdin);

//DIASXISH LISTAS
book *tmp = head;

while(tmp != NULL){

    //AN O TITLOS UPARXEI STH LISTA EMFANISH TOU VIVLIOU,AUKSHSH DHMOTIKOTHTAS, MPENEI STH SWSTH THESH META THN AYKSHSH THS DHMOTIKOTHTAS TOU KAI EPISTROFH
    if(strcmp(tmp->title,title) == 0){
        tmp->pop = tmp->pop + 0.5;
        printf("Title       : %sWriter      : %sGenre       : %sDescription : %sPopularity : %.2f\n\n",tmp->title,tmp->writer,tmp->genre,tmp->desc,tmp->pop);
        checkPop(tmp);
        return;
    }
    tmp=tmp->next;
}
}



