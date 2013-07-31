/****************************************************************
 *                                                              *
 *                      Merge Sort                              *
 *                                                              *
 ****************************************************************/

#include<stdio.h>
#include<stdlib.h>

// Prototype
void mergeSort(int* arrPtr, int l, int h);

int main() {
    int n, i, j; // variables for array size and looping
    printf("Enter the size of array:- ");
    scanf("%d",&n);
    int* arrPtr; // Array pointer for dynamic array
    arrPtr = (int*) malloc(sizeof(int)*n+1);

    printf("Enter the values in array: \n");
    for(i=0; i<n; i++)
        scanf("%d", &arrPtr[i]);
    arrPtr[n] = '\0';

    // for showing graphically
    printf("Arrary before sorting: \n");
    for(i=0; i<n; i++) {
        printf("%2d", arrPtr[i]);
        for(j=0; j<arrPtr[i]; j++)
            printf("*");
        printf("\n");
    }

    // calling mergeSort function for sorting
    mergeSort(arrPtr, 0, n-1);

    printf("\nArray after sorting: \n");
    for(i=0; i<n; i++) {
        printf("%2d",arrPtr[i]);
        for(j=0; j<arrPtr[i]; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}

void mergeSort(int* arrPtr, int l, int h) {
    int length = h - l + 1;
    int* temp; // for temprary array
    temp = (int*) malloc(sizeof(int)*length+1);

    // checking for length 1
    if(h <= l)
        return;

    int mid = (l + h)/2; // mid point of array
    mergeSort(arrPtr, l, mid);
    mergeSort(arrPtr, mid+1, h);

    int i, j, k; // looping variables
    for(i=l, j=mid+1, k=l; i<=mid && j<=h; k++) {
        if(arrPtr[i] < arrPtr[j]) {
            temp[k] = arrPtr[i];
            i++;
        }
        else {
            temp[k] = arrPtr[j];
            j++;
        }
    }

    // If one part is merged completly than the rest part is joined directly without merging
    while(i <= mid) {
        temp[k] = arrPtr[i];
        i++;
        k++;
    }
    while(j <= h) {
        temp[k] = arrPtr[j];
        j++;
        k++;
    }

    // updating the array values using temporary array
    for(k=l; k<=h; k++)
        arrPtr[k] = temp[k];

    // for showing graphically
    int n;
    printf("\nArray while sorting\n");
    for(k=l; k<=h; k++) {
        printf("\t%2d", arrPtr[k]);
        for(n=0; n<arrPtr[k]; n++)
            printf("*");
        printf("\n");
    }
    return;
}
