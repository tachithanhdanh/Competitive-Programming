#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

#define ll long long
#define endl "\n"

using namespace std;

int array_for_sorting[1024],n,cnt=0,minindex=0;
bool have_done=false;

void bubble_sort(){
    for (int i=0;i<n;++i){
        have_done=true;
        for (int j=1;j<n;++j){
            if (array_for_sorting[j]<array_for_sorting[j-1]){
                swap(array_for_sorting[j],array_for_sorting[j-1]);
                have_done=false;
            }
            ++cnt;
        }
        if (have_done) break;
    }
    return;
}

void selection_sort(){ 
    for (int i=0;i<n-1;++i){
        minindex=i;
        for (int j=i+1;j<n;++j){
            if (array_for_sorting[minindex]>array_for_sorting[j]) {
                minindex=j;
            }
            ++cnt;
        }
        swap(array_for_sorting[i],array_for_sorting[minindex]);
    }
}

void quick_sort(int a[],int left,int right){
    int i=left,j=right,pivot=a[(left+right)/2];
    while(i<=j){
        while (a[i]<pivot){
            ++i; ++cnt;
        }
        while (a[j]>pivot){
            --j; ++cnt;
        }
        if (i<=j){
            swap(a[i],a[j]);
            ++i; --j; ++cnt;
        }
    }
    if (left < j) quick_sort(a, left, j);
    if (i < right) quick_sort(a, i, right);
    return;
}

void insertion_sort(){
    
    for (int i=0;i<n;++i){
        /*key=array_for_sorting[i];
        j=i; --j;
        while (j>-1 && key<array_for_sorting[j]){
            array_for_sorting[j+1]=array_for_sorting[j];
            --j; ++cnt;
        }
        array_for_sorting[++j]=key; */
        int j=i+1; //++cnt;
        while (j&&array_for_sorting[j]<array_for_sorting[j-1]){
            swap(array_for_sorting[j],array_for_sorting[j-1]);
            --j; ++cnt;
        }
    }
    return;
}

void print_number(){
    cout << "Array size (n): "<<n << endl;
    cout << "Number of operations = " << cnt << endl;
    for (int i=1;i<n+1;++i) {
            cout << array_for_sorting[i-1] << " ";
            if (i%32==0) cout << endl;
    }
    }

int main(){
    freopen("INPUT.TXT","r",stdin); //Used for normal sort
    //freopen("RANDOM_INPUT.TXT","r",stdin);
    //freopen("ANOTHER_RANDOM_INPUT.TXT","r",stdin);
    //freopen("SORTED_ARRAY.TXT","r",stdin); //test the time complexity in best case
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0;i<n;++i) cin >> array_for_sorting[i];
    //bubble_sort(); freopen("BUBBLE_SORT.TXT","w",stdout);
    //insertion_sort(); freopen("INSERTION_SORT.TXT","w",stdout);
    //quick_sort(array_for_sorting,0,n-1); freopen("QUICK_SORT.TXT","w",stdout);
    //selection_sort(); freopen("SELECTION_SORT.TXT","w",stdout);
    //print_number();
    return 0;
}
