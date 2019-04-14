//Tsotras Stefanos icsd13189
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort (int *A, int N,int* sygkriseis);
void quicksort(int a[], int lo, int hi,int* sygkriseis);
void merge(int arr[], int l, int m, int r,int* sygkriseis);
void mergesort(int arr[], int l, int r,int* sygkriseis);


int main()
{
    int i, N, k, option;
    int *A;
    double mesosXronos=0;
    int sygkriseis=0;
    clock_t start, end;
    double elapsed;


    printf("\n 1.Insertion Sort\n 2.Merge Sort\n 3.Quick Sort\n 4.Exit.\n");

    printf("Choice : ");
    scanf("%d", &option);


    printf("\n\n Size of Array : ");
    scanf("%d", &N);
    printf("\n\n");

    //DESMEUSH MNHMHS GIA TON PINAKA
    A= (int *) malloc(N*sizeof(int ));

    for ( i=0; i<100; i++){
        for(k=0; k<N; k++){
            A[k]=(rand()%50001);
         }

    //INSERTION SORT
    if(option==1){

         start = clock();

         InsertionSort(A , N, &sygkriseis);

        //YPOLOGISMOS XRONOU
         end = clock();
         elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
         mesosXronos = mesosXronos + elapsed;



    }

    //MERGESORT SORT
    else if(option==2){

        start = clock();
        mergesort(A,0,N, &sygkriseis);
        end = clock();
        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        mesosXronos = mesosXronos + elapsed;

    }

    //QUICKSORT
    else if(option==3){

        start = clock();
        quicksort(A, 0, N-1, &sygkriseis);
        end = clock();
        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        mesosXronos = mesosXronos + elapsed;

    }

    else if (option==4){
        printf("goodbye");
    }
    else{
        printf("wrong");
    }

}

//EMFANISH SYGKRISEWN KAI XRONOU
        printf("Mesos # Sygkrisewn  : %f \n",(double) sygkriseis/100);
        printf("Mesos Xronos taksinomhshs : %f\n",mesosXronos/100);

}


void InsertionSort (int A[], int N,int *sygkriseis)
{

    int c, d, t;

    for(c=1 ; c<=N; c++){

        d = c;

        while (A[d] > A[d-1]) {
            t = A[d];
            A[d] = A[d-1];
            A[d-1] = t;
            d--;
            ++*sygkriseis;
        }
    }


}


void mergesort(int arr[], int l, int r, int *sygkriseis)
{
    if (l < r)
    {
        ++*sygkriseis;
        //brisko to meso
        int m = (l+r)/2;

        //taksinomw anadromika ta 2 misa
        mergesort(arr, l, m, sygkriseis);
        mergesort(arr, m+1, r, sygkriseis);

        merge(arr, l, m, r, sygkriseis);

    }

}

void merge(int arr[], int l, int m, int r,int *sygkriseis)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    //dhmiurgw prosorinouspinakes
    int L[n1], R[n2];

    // metaferw stoixeia se L[] kai R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    //sygxvneyv tous prosorinous pinakes ston arxiko taksinomwntas
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = R[j];
            j++;
        }
        else
        {
            arr[k] = L[i];
            i++;
        }
        k++;
        ++*sygkriseis;
    }

    //antigrafw ta stoixeia tou L an uparxnoun
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    //antigrafw ta stoixeia tou R an uparxnoun

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}




void quicksort(int a[], int first, int last, int *sygkriseis)
{
    int h, l, aksonas, t, c;

    if (first < last)
    {
        l = first;
        h = last;
        aksonas = a[last];

        do {
            while ((l < h) && (a[l] >= aksonas))
                l = l+1;
                ++*sygkriseis;

            while ((h > l) && (a[h] <= aksonas))
                h = h-1;
                ++*sygkriseis;

            if (l < h) {
                t = a[l];
                a[l] = a[h];
                a[h] = t;
            }
        } while (l < h);

        a[last] = a[l];
        a[l] = aksonas;

        quicksort( a, first, l-1, sygkriseis );
        quicksort( a, l+1, last, sygkriseis );

    }
}

