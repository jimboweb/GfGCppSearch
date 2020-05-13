#include <iostream>
#include <vector>
#include<cmath>
#include <iostream>
#include <fstream>

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

void testNumOnes(){
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

int leftIndexRec(int arr[], int first, int last, int elementToSearch){
    int current = (first+last)/2;
    if(first>last)
        return -1;
    if(arr[current]==elementToSearch && (current==0 || arr[current-1]!=elementToSearch))
        return current;

    if(arr[current]<elementToSearch)
        return leftIndexRec(arr,current+1,last,elementToSearch);
    return leftIndexRec(arr,first,current-1,elementToSearch);
}

int leftIndex(int sizeOfArray, int arr[], int elementToSearch){
    return leftIndexRec(arr,0,sizeOfArray,elementToSearch);

}

void testLefttIndex(){
    int arr[] = {1, 1, 2, 2, 3, 4, 5, 5, 6, 7};
    int x = 1;
    int n= sizeof(arr)/ sizeof(int);
    printf("%d\n",leftIndex(n,arr,x));
    int arr2[] = {10, 20, 20, 20, 20, 20, 20};
    x = 20;
    n= sizeof(arr2)/ sizeof(int);
    printf("%d\n",leftIndex(n,arr2,x));
}

int peakElementRec(int arr[], int start, int end,int n){
    int mid = (start+end)/2;
    if((mid==0||arr[mid-1]<=arr[mid])&&(mid==n-1||arr[mid+1]<=arr[mid]))
        return mid;
    if(mid>0&&arr[mid-1]>=arr[mid])
        return peakElementRec(arr,start,mid-1,n);
    return peakElementRec(arr,mid+1,end,n);

}

int findFloorRec(vector<long long> v, int start, int end, long long n, long long x){
    int mid = (start+end)/2;
    if(v[mid]<=x){
        if(v[mid+1]>x)
            return mid;
        return findFloorRec(v,mid+1,end,n,x);
    }
    return findFloorRec(v,start,mid-1,n,x);

}

int findFloor(vector<long long> v, long long n, long long x){
    if(v[0]>x)
        return -1;
    if(v[n-1]<x)
        return n-1;
    return findFloorRec(v,0,n,n,x);
}

void testFindFloor(){
    int n=7;
    int x=11;
    vector<long long> v({1, 2, 8, 10, 11, 12, 19});
    cout<<findFloor(v,n,x);
}

int peakElement(int arr[], int n){
    return peakElementRec(arr,0,n,n);
}

void testPeakElement(){
    int n=79;
    int arr[] ={266, 378, 567, 977, 670, 162, 135, 834, 537, 128, 907, 1000, 698, 317, 261, 840, 571, 568, 987, 487, 9, 768, 278, 967, 137, 436, 694, 38, 947, 720, 368, 213, 97, 935, 541, 118, 96, 675, 951, 632, 803, 209, 631, 852, 526, 243, 691, 448, 162, 677, 935, 170, 796, 564, 136, 932, 352, 181, 321, 298, 901, 689, 862, 997, 975, 402, 115, 70, 429, 417, 53, 583, 626, 683, 434, 503, 278, 124, 950};
    cout<<peakElement(arr,n);
}

bool findPairSum(int arr[], int n,int x){
    int lftPtr = 0;
    int rightPtr = n-1;
    while(lftPtr<rightPtr){
        if(arr[lftPtr]+arr[rightPtr]==x)
            return true;
        if(arr[lftPtr]+arr[rightPtr]>x){
            rightPtr--;
            continue;
        }
        lftPtr++;
    }
    return false;
}

void testFindPairSum(){
    int arr1[] = {2,5,8,12,30};
    int x1 = 17;
    int n1 = sizeof(arr1)/ sizeof(int);
    cout<<findPairSum(arr1,n1,x1);
}

int findPivot(int *arr, int low, int high){
    if(high<low)
        return -1;
    if(high==low)
        return low;
    int mid = (high+low)/2;
    if(mid<high&&arr[mid]>arr[mid+1])
        return mid;
    if(mid>low&&arr[mid]<arr[mid-1])
        return mid-1;
    if(arr[low]>arr[mid])
        return findPivot(arr,low,mid-1);
    return findPivot(arr,mid+1,high);
}

int testFindPivot(){
    int arr1[] = {50, 60, 5, 11, 25, 40};
    cout<<findPivot(arr1,0,6);
}

int minNumber(int arr[], int low, int high)
{
    if(high<low)
        return arr[0];
    if(high==low)
        return arr[0];
    int mid = (high+low)/2;
    if(mid<high&&arr[mid]>arr[mid+1])
        return arr[mid+1];
    if(mid>low&&arr[mid]<arr[mid-1])
        return arr[mid];
    if(arr[low]>arr[mid])
        return minNumber(arr,low,mid-1);
    return minNumber(arr,mid+1,high);

}

void testMinNumber(){
    int arr1[] = {20, 162, 462,};
    cout <<minNumber(arr1,0,3);
}

int maxStep(int *a, int n){
    int floor = a[0];
    int steps = 0;
    int maxSteps = 0;
    for(int i=1;i<n;i++){
        if(a[i]>floor){
            steps+=1;
            if(steps>maxSteps)
                maxSteps = steps;
        } else {
            steps = 0;
        }
        floor = a[i];
    }
    return maxSteps;
}


int testMaxStep(){
    int arr[] = {6, 9, 2, 7, 5, 4, 1, 9};
    int n = sizeof(arr)/ sizeof(int);
    cout << maxStep(arr,n);
}

void twoRepeated(int arr[], int n){
    bool hasOccurred[n];
    int count = 0;
    for(int i=0;i<n;i++){
        int num = arr[i];
        if(!hasOccurred[num]){
            hasOccurred[num]=true;
            continue;
        }
        printf("%d ", num);
        count++;
        if(count>=2)
            break;
    }

}

void testTwoRepeated(){
    int arr[] = {1, 2, 1, 3, 4, 3};
    int n = sizeof(arr)/ sizeof(int);
    twoRepeated(arr,n);
}



//start the functions to find repeated and print number
void findLastAndPrint(int arr[],int n, int low, int high, int repeated, int first){
    int mid = (low+high)/2;
    if(low>=n){
        printf("%d %d",repeated,n-first);
    } else if(arr[mid]==repeated+1){
        printf("%d %d",repeated,mid-first);
    } else if(arr[mid]>repeated+1){
        findLastAndPrint(arr,n,low,mid-1,repeated,first);
    } else {
        findLastAndPrint(arr,n,mid+1,high,repeated,first);
    }
}

void findFirst(int arr[], int n, int low, int high, int repeated){
    int mid = (low+high)/2;
    if(high<0){
        findLastAndPrint(arr,n,0,n-1,repeated,0);
    }else if(arr[mid]==repeated-1){
        findLastAndPrint(arr,n,0,n-1,repeated,mid+1);
    } else if(arr[mid]>repeated-1){
        findFirst(arr,n,low,mid-1,repeated);
    } else {
        findFirst(arr,n,mid+1,high,repeated);
    }
}

void findRepeated(int arr[], int n, int low, int high){
    int mid = (low+high)/2;
    if((mid!=0 && arr[mid-1]==arr[mid]) || (mid!=n-1 && arr[mid+1]==arr[mid])){
        findFirst(arr,n,0,n-1,arr[mid]);
    } else if(arr[mid]==mid+arr[0]){
        findRepeated(arr,n,mid+1,high);
    } else {
        findRepeated(arr,n,low,mid-1);
    }
}


void findRepeatedInConsec(int arr[], int n){
    findRepeated(arr,n,0,n-1);
}
//end the functions to find repeated and print number



void testRepeatedInConsecutive(){
    int arr[] = {1, 2, 3, 4, 5, 5, 6};
    int n = sizeof(arr)/ sizeof(int);
    findRepeatedInConsec(arr,n);
}

int medianOfSortedArraysNaive(int *arr1, int *arr2, int n1, int n2){
    vector<int> v;
    for(int i=0;i<n1;i++){
       v.push_back(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        v.push_back(arr2[i]);
    }
    sort(v.begin(),v.end());
    int middle = (n1+n2)/2;
    if((n1+n2)%2==0){
        return floor((v[middle]+v[middle-1])/2);
    } else {
        return v[middle];
    }
}

int medianOfSortedArrays(int *arr1, int *arr2, int n1, int n2){
    int begin = 0, end = n1;
    while(begin <= end){
        int i1 = (begin + end) / 2;
        int i2 = (n1+n2+1)/2-i1;
        int min1 = i1==n1?INT_MAX:arr1[i1];
        int max1 = i1==0?INT_MIN:arr1[i1-1];
        int min2 = i2==n2?INT_MAX:arr2[i2];
        int max2 = i2 == 0?INT_MIN:arr2[i2-1];

        if(max1<=min2 && max2<=min1){
            if((n1+n2)%2==0){
                return floor(((double) max(max1,max2)+min(min1,min2))/2);
            } else {
                return (double) max(max1,max2);
            }
        } else if(max1>min2){
            end = i1 - 1;
        } else {
            begin= i1 + 1;
        }
    }
}

void testMedianOfSortedArrays(){
//    int arr1[] = {10,20,30,40,50};
//    int arr2[] = {5,15,25,35,45,55,65,75,85};
//    int n1 = sizeof(arr1)/sizeof(int);
//    int n2 = sizeof(arr2)/sizeof(int);
//    printf("naive: %d\n",medianOfSortedArraysNaive(arr1,arr2,n1,n2));
//    printf("efficient: %d\n",medianOfSortedArrays(arr1,arr2,n1,n2));
    ofstream logFile;
    logFile.open ("/Users/jimstewart/Git/GfGCppSearch/median_log.txt");
    int trials =50;
    for(int i=0;i<trials;i++){
        int n1 = (int)floor(rand()%10)+2;
        int n2 = (int)floor(rand()%10)+2;
        int arr1[n1],arr2[n2];
        for(int j=0;j<n1;j++)
            arr1[j]=rand()%100;
        for(int j=0;j<n2;j++)
            arr2[j]=rand()%100;
        sort(arr1,arr1+n1);
        sort(arr2,arr2+n2);
        int naive = medianOfSortedArraysNaive(arr1,arr2,n1,n2);
        int efficient = medianOfSortedArrays(arr1,arr2,n1,n2);
        if(naive!=efficient) {
            printf("naive and efficient don't match, logging\n");
            logFile<<"Failed on trial "<< i<<endl;
            logFile<<"n1 = " << n1 << " n2 = "<< n2<<endl;
            logFile<<"arr1: "<<endl;
            for(int j=0;j<n1;j++)
                logFile<<arr1[j]<<" ";
            logFile<<endl;
            logFile<<"arr2: "<<endl;
            for(int j=0;j<n2;j++)
                logFile<<arr2[j]<<" ";
            logFile<<endl;
            logFile<<"naive got "<<naive<<" efficient got "<<efficient<<endl<<endl<<endl;
        } else {
            printf("medians match\n");
        }
    }
    logFile.close();
}


int findMajority(int a[], int size){
    int res = 0, count = 1;
    for(int i=1; i < size; i++){
        if(a[res] == a[i]){
            count++;
        } else {
            count--;
        }
        if(count==0){
            res=i;
            count = 1;
        }
    }
    count = 0;
    for(int i=0; i < size; i++){
        if(a[res] == a[i]){
            count++;
        }
    }
    if(count <= size / 2)
        res=-1;
    return res;
}

int testFindMajority(){
    int n;
    int arr1[] = {15};
    n = sizeof(arr1)/sizeof(n);
    cout<<findMajority(arr1,n)<<endl;
    int arr2[] = {6,6,3,3,3,6,6};
    n = sizeof(arr2)/sizeof(n);
    cout<<findMajority(arr2,n)<<endl;
}

vector<int> subarraySumNaive(int arr[], int n, int s){
    int start = 0, end;
    vector<int> res;
    while(start < n){
        end = start;
        int sum = 0;
        while(end<n){
            sum+=arr[end];
            if(sum==s){
                res.push_back(start+1);
                res.push_back(end+1);
                return res;
            }
            end++;
        }
        start++;
    }
    res.push_back(-1);
    return res;
}




// Function to find the subarray with given sum k
// arr: input array
// n: size of array
void subarraySum(int arr[], int n, int s){
    int start = 0, end;
    while(start < n){
        end = start;
        int sum = 0;
        while(sum<s){
            sum+=arr[end];
            if(sum==s){
                printf("%d %d",start+1,end+1);
                return;
            }
            if(end==n){
                printf("%d",-1);
                return;
            }
            end++;
        }
        start++;
    }
    printf("%d",-1);
}

int countOccurrence(int *arr, int n, int k) {
    int start = 0, rtrn = 0, count, current, end;
    std::sort (arr,arr+n);
    while(start<n-n/k){
        current = arr[start];
        end = start+1;
        count = 0;
        while(arr[end]==current){
            count++;
            if(count==n/k)
                rtrn++;
            end++;
        }
        start=end;
    }
    return rtrn;
}

void testCountOccurrence(){
    int arr1[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = sizeof(arr1)/ sizeof(arr1[0]);
    int k = 4;
    cout<<countOccurrence(arr1, n, k)<<endl;
    int arr2[] = {2, 3, 3, 2};
    int n2 = sizeof(arr2)/ sizeof(arr2[0]);
    int k2 = 3;
    cout<<countOccurrence(arr2, n2, k2)<<endl;
}

int maxWaterNaive(int *height, int n){
    int maxWater = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int water = min(height[i], height[j]) * (j - i - 1);
            maxWater=water>maxWater?water:maxWater;
        }
    }
    return maxWater;
}

void testMaxWater(){
    int arr1[] = {2, 6, 7, 4, 6, 5};
    int n1 = sizeof(arr1)/ sizeof(arr1[0]);
    cout << maxWaterNaive(arr1, n1);
}

vector<int> mergeSorted(int *arr1, int *arr2, int n1, int n2){
    int ptr1 = 0, ptr2=0;
    vector<int> rtrn;
    while(ptr1<n1&&ptr2<n2){
        if(arr1[ptr1]<arr2[ptr2]){
            rtrn.push_back(arr1[ptr1++]);
        } else {
            rtrn.push_back(arr2[ptr2++]);
        }
    }
    while(ptr1<n1){
        rtrn.push_back(arr1[ptr1++]);
    }
    while(ptr2<n2){
        rtrn.push_back(arr2[ptr2++]);
    }
    return rtrn;
}

int main() {
    testMaxWater();
    return 0;
}