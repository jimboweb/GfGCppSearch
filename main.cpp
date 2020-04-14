#include <iostream>
using namespace std;

// binary search
// arr: input array
// n: size of array
// x: element to be searched

int searchInSortedRec(int arr[], int start, int end, int x);

int searchInSortedRecLeftMost(int arr[], int start, int end, int x);

int searchInSorted(int arr[], int n, int x)
{
    return searchInSortedRec(arr,0,n,x);
}

int searchInSortedRec(int arr[], int start, int end, int x){
    if (start>end)
        return -1;

    int middle = (start+end)/2;
    if(arr[middle]==x)
        return middle;
    if(arr[middle]<x)
        return searchInSortedRec(arr,middle+1,end,x);
    return searchInSortedRec(arr,start,middle-1,x);

}

int findInInfiniteArray(int *arr, int x){
    if(arr[0]==x)
        return 0;
    int ind=1;
    while(arr[ind]<x){
        ind=ind*2+1;
    }
    return searchInSortedRec(arr,ind/2,ind,x);
}

int leftmostOneInBinary(int *arr, int start, int end){
    if (start>end)
        return -1;

    int middle = (start+end)/2;
    if(arr[middle]==1&&(middle==start||arr[middle-1]!=1))
        return middle;
    if(arr[middle]<1)
        return leftmostOneInBinary(arr,middle+1,end);
    return leftmostOneInBinary(arr,start,middle-1);

}

int leftmostZeroInBinary(int *arr, int n, int start, int end){
    if (start>end)
        return n;
    int middle = (start+end)/2;
    if(arr[middle]==0&&(middle==start||arr[middle-1]!=0))
        return middle;
    if(arr[middle]>0)
        return leftmostZeroInBinary(arr,n,middle+1,end);
    return leftmostZeroInBinary(arr,n,start,middle-1);

}

int rightmostOneInBinary(int *arr, int start, int end){
    if (start>end)
        return -1;

    int middle = (start+end)/2;
    if(arr[middle]==1&&(middle==end-1||arr[middle+1]!=1))
        return middle;
    if(arr[middle]<1)
        return rightmostOneInBinary(arr,start,middle-1);
    return rightmostOneInBinary(arr,middle+1,end);

}




//number of ones in sorted array
int numOnes(int arr[], int n){
    return leftmostZeroInBinary(arr, n, 0, n);
}

int countOnesNaive(int arr[], int n){
    int i=0,count=0;
    while(arr[i]==1) {
        count++;
        i++;
    }
    return count;
}

int testNumOnes(){
    int arr[]={1,1,1};
    int n = sizeof(arr)/ sizeof(int);
    cout<<countOnesNaive(arr,n)<<endl;
    cout<<numOnes(arr,n)<<endl;
    int arr1[] = {1,1,1,0,0,0,0};
    n = sizeof(arr1)/ sizeof(int);
    cout<<countOnesNaive(arr1,n)<<endl;
    cout<<numOnes(arr1,n)<<endl;
    int arr2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    n = sizeof(arr2)/ sizeof(int);
    cout<<countOnesNaive(arr2,n)<<endl;
    cout<<numOnes(arr2,n)<<endl;
    int arr3[] = {0,0,0};
    n = sizeof(arr3)/ sizeof(int);
    cout<<countOnesNaive(arr3,n)<<endl;
    cout<<numOnes(arr3,n)<<endl;
}

//sae as above but gets leftmost element
int searchInSortedLRMost(int *arr, int start, int end, int x, bool isLeft = true){
    if (start>end)
        return -1;

    int middle = (start+end)/2;
    int nextLeftOrRight=isLeft?middle-1:middle+1;
    int endOrBeginning = isLeft?start:end-1;
    if(arr[middle]==x&&(middle==endOrBeginning||arr[nextLeftOrRight]!=x)) {
        return middle;
    }
    if(isLeft) {
        if(arr[middle]<x)
            return searchInSortedLRMost(arr,middle+1,end,x,isLeft);
        return searchInSortedLRMost(arr,start,middle-1,x,isLeft);
    }
    if(arr[middle]<=x)
        return searchInSortedLRMost(arr,middle+1,end,x,isLeft);
    return searchInSortedLRMost(arr,start,middle-1,x,isLeft);
}

void testSearchInSortedLRMost(){
    int arr[]= {0,1,1,1,2};
    int n=5;
    cout<< searchInSortedLRMost(arr, 0, n, 1, false)<<endl;
}

int findRangeInSorted(int arr[],int n,int x){
    int left = searchInSortedLRMost(arr, 0, n, x, true);
    int right = searchInSortedLRMost(arr, 0, n, x, false);
    return right-left+1;
}

void testFindRangeInSorted(){
    int arr[]= {0,1,1,1};
    int n=4;
    cout<<findRangeInSorted(arr,n,1)<<endl;

}

int main() {
    testNumOnes();
    return 0;
}