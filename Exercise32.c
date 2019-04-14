//Tsotras Stefanos icsd13189
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//DHLWSH SYNARTHSEWN
void swapheap(int* a,int* b);
void InsertHeap(int *heap,int i,int num);
void Printable(int *A,int n);
void Create_heap(int *A,int n);
void Fixheap(int *A,int i,int hs);
void InitializeTable(int *A,int n);
void heapSort(int *A,int n);

int main(){

//DHLWSH METABLHTWN
int i,N,comp=0,num,hs=21,input=0,number;
int *heap= (int *)malloc(hs*sizeof(int ));
srand(time(NULL));

//MENU EPILOGWN
while(input != 7){
printf("    Menu\n1. Dhmiourgia pinaka tuxaiwn\n2. Dhmiourgia swrou apo pinaka\n");
printf("3. Prosthiki neou stoixeiou sto swro\n4. Emfanisi pinaka swrou\n5. Dendroeidhs anaparastash\n");
printf("6. Taksinomisi kai emfanish taksinomimenou\n7. Eksodos\n");
printf("Input : ");
scanf("%d",&input);
printf("\n");

switch(input){

case 1:
   InitializeTable(heap,hs);
   break;
case 2:
   Create_heap(heap,hs);
   break;
case 3:
    printf("Dwse mia timh : ");
    scanf("%d",&number);
    printf("\n\n");
    InsertHeap(heap,hs,number);
    break;
case 4:
    Printable(heap,hs);
    break;
case 5:
    printf("Oops,under construction!\n\n");
    break;
case 6:
    heapSort(heap,hs);
    break;
case 7:
    break;

}
}

}

//DHMIOURGIA PINAKA APO TUXAIOUS
void InitializeTable(int *A,int n){
int i;
for(i=0;i<n;i++){
    A[i]= 1+rand()%99;
}

}

//EMFANISH PINAKA
void Printable(int *A,int n){
int i;
for(i=0;i<n;i++){
    printf("%d ",A[i]);
}
printf("\n\n");
}

//DHMIOURGIA TOU SWROU APO PINAKA
void Create_heap(int *A,int n){
int i;
int hs = n;
//KALWNTAS APTON TELEUTAIO PATERA THN FIXHEAP
for(i=n/2; i>0;i--){
   Fixheap(A,i,hs);
}

}

//ANTALAGH DEDOMENWN PATERA-PAIDIWN OTAN
//TO PAIDI EINAI MIKROTERO, DIADOXIKA GIA
//OLA TA APO KEI KAI KATW
void Fixheap(int *A,int i,int hs){

int temp = A[i];
if(A[2*i] < A[2*i+1]){
    A[i] = A[2*i];
    A[2*i] = temp;
}
else if(A[2*i] > A[2*i+1]){
    A[i] = A[2*i+1];
    A[2*i+1] = temp;
}
else{
    A[i] = A[2*i];
    A[2*i] = temp;
}


if(2*i > hs){
    return;
}

if( A[i] > A[2*i]){
  Fixheap(A,2*i,hs);
}
else if( A[i] > A[2*i+1]){
  Fixheap(A,2*i+1,hs);
}

}

//ANTALAGH DEDOMENWN
void swapheap(int* a,int* b){

int temp=*a;
*a=*b;
*b=temp;

}

//EISAGWGH KAINOURGIOU STOIXEIOU STON SWRO
void InsertHeap(int *heap,int n,int num){
int i=n;
heap[n]=num;
int j = n/2;

while(heap[i] < heap[j] && i > 1){
    swapheap(&heap[i],&heap[j]);
    i=j;
    j = j/2;
}

}

//TAKSINOMHSH TOU SWROU
void heapSort(int *A,int n){

Create_heap(A,n);
int hs=n,i;
for(i=n;i>1;i--){
  swapheap(&A[1],&A[hs]);
  hs--;
  Fixheap(A,1,hs);
}

}
