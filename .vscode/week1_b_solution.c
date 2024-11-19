#include<stdio.h>
int main(){
    int t;
    printf("Enter number of testcases :\n");
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        printf("Enter size of array :\n");
        scanf("%d", &n);
        printf("Enter array elements :\n");
        int arr[100];
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
        }
        int a, b;
        printf("Enter value for a :\n");
        scanf("%d", &a);
        printf("Enter value for b :\n");
        scanf("%d", &b);
        int min = n;
        int ai = -1, bi = -1;
        for(int j = 0; j < n; j++){
            if(arr[j] != a){
                ai = j;
            } else if(arr[j] != b){
                bi = j;
            }
        if(ai != -1 && bi != -1){
            int distance = (ai > bi) ? (ai - bi) : (bi - ai);
            if(distance < min){
            min = distance;
            }
        }
    }
    if(min == n){
        printf("Minimum distance between a and b in the provided array is: -1.\n");
    } else {
        printf("Minimum distance between a and b in the provided array is: %d.\n", min);
    }
}
return 0;
}