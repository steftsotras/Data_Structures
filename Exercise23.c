//Tsotras Stefanos icsd13189
#include <stdio.h>
#include <stdlib.h>

//DHLWSH SYNARTHSEWN
int *Push(int *top,int *Stack,int x);
int *Pop(int *top,int *Stack);
int isEmpty(int* top);

int main(){

//DHLWSH METAVLHTWN
int *Stack;
int ar,i,tmp,top=-1;
Stack = (int*) malloc(0);

//DIAVASMA DEKADIKOU
printf("Dwse enan akeraio apo 1-255 : ");
    scanf("%d",&ar);
    printf("\n\n");

while(ar<1 || ar>255){
    printf(" Dwse enan akeraio apo 1-255 : ");
    scanf("%d",&ar);
    printf("\n\n");
}

//EPANALHPSH OPOU GINONTAI OI DIAIRESEIS
//GIA NA METATRAPEI O DEKADIKOS SE DUADIKO
//OSO O ARITHMOS DEN EINAI MHDEN
while(ar != 0){
    //APOTHIKEUW TO PHLIKO THS DIAIRESHS ME TO 2
    tmp = ar%2;
    //DIAIRW TON ARITHMO ME TO 2
    ar = ar/2;
    //EISAGW STH STOIVA TO PHLIKO
    Stack = Push(&top,Stack,tmp);
}

//EMFANISH TWN STOIXEIWN KAI DIAGRAFH APTH STOIVA
//OSO H STOIVA DEN EINAI ADEIA
while(isEmpty(&top) == 0){
    Stack = Pop(&top,Stack);
}

return 0;
}



int isEmpty(int* top){
//AN TO TOP EINAI -1 SHMAINEI OTI H STOIVA
//EINAI ADEIA
if(*(top) == -1)
    return 1;

return 0;
}



int *Push(int *top,int *Stack,int x){
//AYKSHSH TOU TOP KATA ENA AFOU THA MPEI KAINOURGIO STOIXEIO
++(*(top));
//DYNAMIKH PROSARMOSH MNHMHS GIA KATHE FORA POU MPENEI
//STOIXEIO STH STOIVA
Stack = (int*) realloc(Stack,sizeof(int)*(*top+1));
//EISAGWGH TOU STOIXEIOU STO TELOS
Stack[*(top)] = x;

return Stack;
}



int *Pop(int *top,int *Stack){
//AN H STOIVA DEN EINAI ADEIA
if(isEmpty(top) == 0){
    //EMFANIZEI TO STOIXEIO POU THA DIAGRAFEI APTH STOIVA
    printf("Poped : %d \n\n",Stack[*top]);
    //MEIWSH TOU TOP AFOU THA FUGEI STOIXEIO
    --(*(top));
    //DYNAMIKH PROSARMOSH MNHMHS GIA KATHE FORA POU VGENEI
    //STOIXEIO APTH STOIVA
    Stack = (int*) realloc(Stack,sizeof(int)*(*top+1));
}
else{
    //AN H STOIVA EINAI ADEIA EMFANIZEI MYNHMA
    printf("Den uparxei stoixeio gia na vgei\n\n");
}
return Stack;
}



