
#include<bits/stdc++.h>
using namespace std;

#define sz 100002

int A[sz];

int binarySearch(int L, int E, int ans);

int main() {

    int n, i, ans, index;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    sort(A, A+n);
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    while(1) {
        scanf("%d", &ans);
        index = binarySearch(0, n-1, ans);

        if(index > -1) {
            printf("The first occurance index is: %d\n", index+1);
        }else {
            printf("This is element is not found\n");
        }
    }
    return 0;
}

int binarySearch(int l, int h, int ans) {
    int mid, index = -1, cn = 0;

    while(l <= h) {
        cn++;
        mid = (l+h) / 2;
        if(A[mid] == ans) {
            index = mid;
            h = mid - 1;
        }
        else if(A[mid] < ans) l = mid + 1;
        else h = mid - 1;
    }
    printf("Count = %d\n", cn);

    return index;
}

/*
10
22 4 6 0 -1 3 -22 29 999 23
*/

