//Tsotras Stefanos icsd13189
#include <stdio.h>
#include <stdlib.h>


//DHMIOURGIA STRUCT
typedef struct node{
    int number;
    struct node *next;
}node;
node *head;

typedef struct node2{
    int number;
    struct node2 *next;
    struct node2 *prev;
}node2;
node2 *head2;
node2 *tail2;

//DHLWSH SYNARTHSEWN
node* addNodeSingle(node *head, int, int );
node* addAscending (node *head, int);
int countList (node *head);
void displayList (node *head);
node* deleteFirst (node *head);
node* deleteNode (node *head, int);
node2* addNodeDouble(node2 *head,node2 **tail,int,int);
void ReversedisplayList (node2 *head,node2 *tail);
node* swapElements1(node *head);
node2* swapElements2(node2 *head,node2 *tail);

int main(){

head2 = NULL;
tail2 = NULL;

head = NULL;

head = addNodeSingle(head,3,1);
head = addNodeSingle(head,2,1);
head = addNodeSingle(head,5,1);
head = addNodeSingle(head,1,1);
head = addNodeSingle(head,2,1);
printf("\n1. addNodeSingle : ");
displayList(head);

head = NULL;

head = addAscending(head,3);
head = addAscending(head,2);
head = addAscending(head,5);
head = addAscending(head,1);
head = addAscending(head,2);

printf("2. addAscending  : ");
displayList(head);

printf("3. countList ,Ta stoixeia einai : %d \n\n",countList(head));

head = deleteFirst(head);
printf("5. deleteFirst  : ");
displayList(head);

head = deleteNode(head,3);
printf("6. deleteNode(3)  : ");
displayList(head);

head2 = addNodeDouble(head2,&tail2,5,1);
head2 = addNodeDouble(head2,&tail2,7,1);
head2 = addNodeDouble(head2,&tail2,1,0);
head2 = addNodeDouble(head2,&tail2,3,1);
printf("8. addNodeDouble : ");
ReversedisplayList(head2,tail2);

printf("10. swapElements1 : \n");
printf("Prin to swap : ");
displayList(head);
printf("Meta to swap : ");
head = swapElements1(head);
displayList(head);

printf("10. swapElements2 : \n");
printf("Prin to swap : ");
ReversedisplayList(head2,tail2);
printf("Meta to swap : ");
head2 = swapElements2(head2,tail2);
ReversedisplayList(head2,tail2);

}

node* addNodeSingle(node *head, int num, int pos){

//TEMPORARY NODE CURRENT
node* current;
current = (struct node*) malloc(sizeof(struct node));

//AN H LISTA EINAI ADEIA
if(head == NULL){

    current->number=num;
	current->next = NULL;
	head=current;
}
//ALLIWS AN O XRHSTHS EPITHUMEI NA MPEI STHN ARXH
else if(pos == 0){
    current->number=num;
	current->next = head;
	head=current;
}
//ALLIWS STO TELOS
else{
    //ORISMOS ENOS VOITHITIKOU KOMVOU GIA THN DIASXISH LISTAS
    node *tmp;

    //DIASXISH LISTAS
    tmp=head;
    //O TMP META THN WHILE THA EXEI TON TELEUTAIO KOMVO(OXI NULL)
    while(tmp->next != NULL){
        tmp=tmp->next;
    }

    //AFOU THA GINEI O TELEUTAIOS KOMVOS
    //TO NEXT THA DEIXNEI SE NULL
    current->number=num;
    current->next = NULL;
    tmp->next = current;


}
return head;
}



node* addAscending (node *head, int num)
{
node* current;
current = (struct node*) malloc(sizeof(struct node));

//AN H LISTA EINAI ADEIA
if(head == NULL){
    current->number=num;
	current->next = NULL;
	head=current;
}
else{

    //ORISMOS DUO VOITHITIKWN KOMVWN GIA THN DIASXISH LISTAS
    node *tmp;
    node *prev;

    tmp=head;
    //EISXWRHSH TOU ARITHMOU STON KOMVO
    current->number=num;
    //AN TO PRWTO STOIXEIO EXEI MEGALYTERO
    //ARITHMO MPENEI STHN ARXH KAI EPISTREFEI
    if(num < tmp->number){
        current->next = head;
        head=current;
        return head;
    }
    //ALLIWS DIASXISH LISTAS
    while (num > tmp->number){
        //KRATHMA TOU PROHGOUMENOU KOMVOU
        prev = tmp;
        tmp=tmp->next;
        //AN FTASEI STO TELEUTAIO STOIXEIO KAI DEN
        //EXEI VREI MEGALYTERO ARITHMO TOTE MPENEI STO TELOS
        if (tmp->next == NULL){
            current->next = NULL;
            tmp->next=current;
            return head;
        }
    }
    //AN VGEI MPENEI KAPOU ENDIAMESA KAI
    //O PROHGOUMENOS DEIXNEI STON KAINOURGIO
    prev->next=current;
    //ENW O KAINOURGIOS DEIXNEI STON KOMVO POU EIXE
    //MEGALYTERO ARITHMO APO AUTON
    current->next=tmp;

}
return head;
}

void displayList(node *head){
node *temp;
//AN EINAI ADEIA
if(head==NULL){
    printf("H lista einai kenh\n\n");
}
else{
    temp=head;
    //DIASXISEI LISTAS
    while (temp!=NULL){
        //EKTYPWSH STOIXEIWN
        printf("%d ",temp->number);
        temp=temp->next;
    }
    printf("\n\n");
}
}

int countList (node *head){
node *temp;

int length = 0;
temp=head;
//AN EINAI ADEIA GYRNAEI 0
if(temp==NULL){
    return length;
}
else{
    //DIASXISH LISTAS
    while (temp!=NULL){
        //AYKSHSH TOU COUNTER GIA OSA STOIXEIA UPARXOUN
        length++;
        temp=temp->next;
    }
}
return length;

}

node* deleteFirst (node *head){

node *temp;
//AN EINAI ADEIA
if(head==NULL){
    printf("H lista einai kenh\n\n");
}
else{
    //HEAD GINETAI TO EPOMENO STOIXEIO
    temp=head;
    head = temp->next;
    //APELEYTHERWSH MNHMHS
    free(temp);
}
return head;

}


node* deleteNode (node *head, int num){

node *temp;
node *prev;
//AN EINAI ADEIA
if(head==NULL){
    printf("H lista einai kenh\n\n");
}
//AN EINAI TO PRWTO STOIXEIO
if(num == head->number){
    //HEAD GINETAI TO EPOMENO STOIXEIO
    head = temp->next;
    //APELEYTHERWSH MNHMHS
    free(temp);
    return head;
}
temp=head;
//DIASXISH LISTAS
while(temp != NULL){
    prev = temp;
    temp = temp->next;
    //AN VREI TO NOUMERO ENDIAMESA
    if(num == temp->number){
        //TO PROHGOUMENO STOIXEIO DEIXNEI PLEON
        //STO EPOMENO
        prev->next = temp->next;
        free(temp);
        return head;
    }
}
//AN VGEI APTH WHILE SHMAINEI OTI DEN VRIKE KAPOIO STOIXEIO
printf("Den vrethike komvos me tetoio noumero\n\n");
return head;
}



node2* addNodeDouble(node2 *head,node2 **tail,int num,int pos){

//DHMIOURGIA TOU KAINOURGIOU KOMVOU KAI DESMEUSH MNHMHS
node2 *current;
current = (struct node2*) malloc(sizeof(struct node2));
//EISXWRHSH TWN DEDOMENWN
current->number = num;

//AN EINAI ADEIA H LISTA
if(head == NULL){
    current->next = NULL;
    current->prev = NULL;
    head = current;
    *tail = current;
}
//MPENEI STHN PRWTH THESH
else if(pos == 0){
    //TO PROHGOUMENO TOU PRWTOU DEIXNEI STO
    //PIA PRWTO CURRENT
    head->prev = current;
    //TO NEXT TOU KAINOURGIOU DEIXNEI STO PRWHGOUMENO PRWTO
    current->next = head;
    //TO PREV TOU KAINOURGIOU DEIXNEI NULL
    current->prev = NULL;
    //TO HEAD DEIXNEI STO KAINOURGIO KOMVO
    head = current;
}
else{
    //DIASXISH LISTAS
    node2 *tmp = head;
    while(tmp->next != NULL){
        tmp=tmp->next;
    }
    //EISXWRHSH TOU KOMVOU STO TELOS
    tmp->next= current;
    //TO EPOMENO EINAI NULL
    current->next = NULL;
    //TO PREVIOUS DEIXNEI STO
    //PROHGOUMENO TELEUTAIO
    current->prev = tmp;
    //TO TAIL DEIXNEI STON KAINOURGIO KOMVO
    *tail = current;
}
return head;
}

void ReversedisplayList(node2 *head,node2 *tail){

//AN H LISTA EINAI ADEIA EPISTREFEI
if(head == NULL){
    printf("H lista einai kenh\n\n");
    return;
}
//DIASXISH LISTAS
node2 *tmp = tail;
while(tmp != NULL){
    //EMFANISH TWN STOIXEIWN TIS LISTAS
    printf("%d ",tmp->number);
    tmp = tmp->prev;
}
printf("\n\n");
}

//H XRONIKH POLUPLOKOTHTA THS SYNARTHSHS EINAI O(n)
node* swapElements1(node *head){

//AN H LISTA EINAI ADEIA
if(head == NULL){
    printf("H lista einai kenh\n\n");
    return head;
}
//AN H LISTA EXEI MONO ENA STOIXEIO
else if(head->next == NULL){
    printf("H lista exei mono ena stoixeio\n\n");
    return head;
}
//APOTHIKEUSH TOU NUMBER TOU PRWTOU STOIXEIOU
int temp = head->number;
//DIASXISH LISTAS MEXRI TO TELEUTAIO STOIXEIO
node *tmp = head;
while(tmp->next != NULL){
    tmp = tmp->next;
}
//APOTHIKEUSH TOU NUMBER TOU TELEUTAIOU
//STOIXEIOU STO PRWTO
head->number = tmp->number;
//KAI APOTHIKEUSH TOU NUMBER TOU PRWTOU
//STO TELEUTAIO
tmp->number = temp;

return head;
}

//H XRONIKH POLUPLOKOTHTA THS SYNARTHSHS EINAI È(1)
node2* swapElements2(node2 *head,node2 *tail){

//AN H LISTA EINAI ADEIA
if(head == NULL){
    printf("H lista einai kenh\n\n");
    return head;
}
//AN H LISTA EXEI MONO ENA STOIXEIO
else if(head->next == NULL){
    printf("H lista exei mono ena stoixeio\n\n");
    return head;
}
int temp = head->number;

head->number = tail->number;
tail->number = temp;

return head;
}
