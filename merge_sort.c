#include<stdio.h>
#include<stdlib.h>

void mergeSort(int* arrPtr, int l, int h);

int main() {
    int n, i;
    printf("Enter the size of array:- ");
    scanf("%d",&n);
    int* arrPtr;
    arrPtr = (int*) malloc(sizeof(int)*n+1);
    printf("Enter the values in array: \n");
    for(i=0; i<n; i++)
        scanf("%d", &arrPtr[i]);
    arrPtr[n] = '\0';
    mergeSort(arrPtr, 0, n-1);
    for(i=0; i<n; i++)
        printf("%d\n",arrPtr[i]);

    return 0;
}

void mergeSort(int* arrPtr, int l, int h) {
    int length = h - l + 1;
    int* temp;
    temp = (int*) malloc(sizeof(int)*length+1);
    if(h <= l)
        return;
    int mid = (l + h)/2;
    mergeSort(arrPtr, l, mid);
    mergeSort(arrPtr, mid+1, h);
    int i, j, k;
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
    for(k=l; k<=h; k++)
        arrPtr[k] = temp[k];
    return;
}
