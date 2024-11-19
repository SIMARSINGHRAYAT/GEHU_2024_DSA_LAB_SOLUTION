#include<stdio.h>
int main(){
    int t;
    printf("Enter number of testcases :\n");
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        printf("Enter size of array :\n");
        scanf("%d", &n);
        int arr[100];
        printf("Enter elements of the array :\n");
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
        }
        int key;
        printf("Enter value of key :\n");
        scanf("%d", &key);
        printf("Printing left rotate of the array from the provided key...\n");
        for(int j = key; j < n; j++){
            printf("%d ", arr[j]);
        }
        for(int j = 0; j < key; j++){
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
return 0;
}