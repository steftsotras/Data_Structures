//Tsotras Stefanos icsd13189

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMIT 30000

//DHLWSH SYNARTHSHS DUADIKHS ANAZHTHSHS
void Duadikh(int *p,int n,int k,int *sygkriseis2,int *petuxhmenes2);

//DHLWSH SYNARTHSHS SEIRIAKHS ANAZHTHSHS
void Seiriakh(int* arr,int r,int N,int* sygkriseis,int* petuxhmenes);

int main(){

//DHLWSH METABLHTWN GIA ZHTHMA1
int N,i,r;
double mesosXronos=0;
int *arr;
int petuxhmenes=0,sygkriseis=0;
clock_t start, end;
double elapsed;

//DHLWSH METABLHTWN GIA ZHTHMA2
int N2,r2;
int *arr2;
double mesosXronos2=0;
int petuxhmenes2=0,sygkriseis2=0;
clock_t start2, end2;
double elapsed2;

int epilogh=0;
//srand((long) 2000666);  BGAZEI TOUS IDIOUS "TUXAIOUS" ARITHMOUS
                        //ME THN IDIA AKRIBWS SEIRA
srand(time(NULL));

while(epilogh != 1 && epilogh != 2){
//MENU EPILOGHS
printf("\n\n**********************MENU*********************\n\n");
printf("1. Gia ektelesh seiriakhs anazhthshs pathse 1\n\n");
printf("2. Gia ektelesh duadikhs  anazhthshs pathse 2\n\n");
printf("***********************************************\n\n");
printf("   Eisodos : ");
scanf("%d",&epilogh);
}

if(epilogh == 1){
//DIAVASMA TOU MEGETHOUS TOU PINAKA
printf("\n\nEISAGWGH MEGETHOUS PINAKA : ");
scanf("%d",&N);
printf("\n\n");

//DESMEUSH MNHMHS GIA TON PINAKA
arr =(int *) malloc(N*sizeof(int));



//ARXIKOPOIHSH PINAKA
for(i=0;i<N;i++){
    *(arr + i) = rand() % LIMIT;
}

//1000 FORES EPANALHPSH THS SEIRIAKHS
for(i=0;i<1000;i++){

    //EPILOGH RANDOM KLEIDIOU
    r = rand()%LIMIT;

    //KSEKINAEI H KATAMETRHSH TOU XRONOU
    start = clock();

    //KALW THN SEIRIAKH SYNARTHSH
    Seiriakh(arr,r,N,&sygkriseis,&petuxhmenes);             //PERNAW TA COUNTERS SYGKRISEIS KAI PETYXHMENES
                                                            //ME ANAFORA ETSI WSTE OTAN ALLAZOUN OI TIMES TOUS
                                                            //MESA STH SYNARTHSH NA ALLAZOUN KAI STHN MAIN
    //TELIWNEI KAI UPOLOGIZEI POSOS XRONOS PERASE
    end = clock();
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    mesosXronos = mesosXronos + elapsed;
}

printf("Apotelesmata Seiriakhs Anazhthshs : \n\n\n");
//EMFANISH TWN APOTELESMATWN
printf("Mesos # Sygkrisewn  : %f \n\n",(double) sygkriseis/1000);
printf("Mesos Xronos Anazhthshs : %f\n\n",mesosXronos/1000);
printf("Pososto Epituxhmenwn Anazhthsewn  : %f%%\n\n",(double) petuxhmenes/10);


//APELEUTHELWSH MNHMHS
free(arr);
}
else{

    //DIAVASMA MEGETHOUS PINAKA
printf("\n\nEISAGWGH MEGETHOUS PINAKA : ");
scanf("%d",&N2);
printf("\n");

//DESMEUSH MNHMHS
arr2 = (int *) malloc(N2*sizeof(int ));

//ARXIKOPOIHSH TOU PINAKA SUMFWNA ME THN AKOLOUTHIA
*arr2= 1+rand()%3;
for(i=1;i<N2;i++){
    *(arr2+i)= *(arr2+i-1) + 1 + rand()%3;
}

//EKTELESH DUADIKHS 1000 FORES
for(i=0;i<1000;i++){

    //ORISMOS TOU KLEIDIOU POU THA ANAZHTHTHEI
    //ME VASH TIS TIMES TOU PINAKA DLD (arr[0] - arr[N2-1])
    r2 = *arr2 + rand()%(*(arr2+N2-1) - *arr2);

    //KSEKINAEI H KATAMETRHSH TOU XRONOU
    start2 = clock();

    //KALW THN DUADIKH SUNARTHSH
    Duadikh(arr2,N2,r2,&sygkriseis2,&petuxhmenes2);         //PERNAW TA COUNTERS SYGKRISEIS KAI PETYXHMENES
                                                            //ME ANAFORA ETSI WSTE OTAN ALLAZOUN OI TIMES TOUS
                                                            //MESA STH SYNARTHSH NA ALLAZOUN KAI STHN MAIN
    //TELIWNEI KAI UPOLOGIZEI POSOS XRONOS PERASE
    end2 = clock();
    elapsed2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    mesosXronos2 = mesosXronos2 + elapsed2;
}

printf("Apotelesmata Duadikhs Anazhthshs : \n\n\n");

//EMFANISH TWN APOTELESMATWN
printf("Mesos # Sygkrisewn  : %f \n\n",(double) sygkriseis2/1000);
printf("Mesos Xronos Anazhthshs : %f\n\n",mesosXronos2/1000);
printf("Pososto Epituxhmenwn Anazhthsewn  : %f%%\n\n",(double) petuxhmenes2/10);

free(arr2);
}
return 0;
}

//YLOPOIHSH THS SEIRIAKHS ANAZHTHSHS
void Seiriakh(int *arr,int r,int N,int *sygkriseis,int *petuxhmenes){

    int i;
    //GIA OSO EINAI TO MEGETHOS TOU PINAKA
    for(i=0;i<N;i++){
        //METRHSH TWN SYNOLIKWN SYGKRISEWN
        ++*sygkriseis;
        //AN BREI TO KLEIDI TOTE
        if((*(arr+i)) == r){
            //METRHSH TWN PETYXHMENWN ANAZHTHSEWN
            ++*petuxhmenes;
            //KAI STAMATAEI THN LOOPA
            break;
        }
    }

}

//ULOPOIHSH SYNARTHSHS DYADIKHS ANAZHTHSHS
void Duadikh(int *p,int n,int k,int *sygkriseis2,int *petuxhmenes2){

//DHLWSH METAVLHTWN
int i;
int low=0;
int high=n-1;
int middle;


//GIA OSO TO LOW DEN KSEPERNAEI TO HIGH
while(low<=high){

    //TIMH TOU MIDDLE ANALOGA ME TIS TIMES
    //LOW KAI HIGH
    middle=(low+high)/2;

    //METRHSH TWN SYNOLIKWN SYGKRISEWN
    ++*sygkriseis2;

    //AN BREI TO KLEIDI STH MESH TOTE
    if(*(p+middle) == k){
        //METRHSH TWN PETYXHMENWN ANAZHTHSEWN
        ++*petuxhmenes2;
        //KAI STAMATAEI THN LOOPA
        break;
    }
    //ALLIWS AN TO KLEIDI EINAI MIKROTERO TOU MESAIOU
    else if(p[middle]>k){
        //DWSE NEA TIMH STO HIGH ENA PRIN THN MESH
        //TO LOW MENEI OPWS EINAI ARA H EPOMENH
        //EPANALHPSH THA EINAI STO PEDIO [low , middle-1]
        high=middle-1;
    }
    else{
        //ANTISTOIXA AN TO KLEIDI EINAI MEGALUTERO
        low=middle+1;
    }
}

}

