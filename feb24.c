#include <stdio.h>

int main() {
    int N;
    printf("ENTER THE SIZE");
    scanf("%d", &N);
    
    int arr1[N], arr2[N];
    printf("ENTER THE 1ST ARRAY ELEMENT");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("ENTER THE 2ST ARRAY ELEMENT");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr2[i]);
    }
    
    int flag = 1;
    for (int i = 0; i < N; i++) {
        if (arr1[i] != arr2[N - 1 - i]) {
            flag= 0;
            break;
        }
    }
    
    printf("%d\n", flag);

}



