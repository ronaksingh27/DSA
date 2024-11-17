#include <bits/stdc++.h>
using namespace std;


// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid , int right )
{
    vector<int> L,R;
    int n1 = mid - left + 1;//mid ele left subarray mei hai
    int n2 = right - mid;

    for(int i = 0 ; i < n1 ; i++ )
    {
        L.push_back(arr[left + i]);
    }
    for(int i = 0 ; i < n2 ; i++ )
    {
        R.push_back(arr[mid + 1 + i]);
    }

    int k = left;
    int i = 0 , j = 0;
    while( i < n1 && j < n2 )
    {
        if( L[i] <= R[j] )
        {
            arr[k] = L[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = R[j];
            k++;
            j++;
        }
    }

    while( i < n1 )
    {
        arr[k] = L[i];
        k++;
        i++;
    }

    while( j < n2 )
    {
        arr[k] = R[j];
        k++;
        j++;
    }

}

void mergeSort(vector<int>& arr , int left, int right )
{
    if( left >= right ) return ;

    int mid = left + (right-left)/2;

    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}


void printVector(vector<int>& a)
{
    for( auto &it : a )
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

// Driver code
int main()
{
    vector<int> arr = { 12, 11, 11, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    printVector(arr);

    mergeSort(arr, 0, n - 1);

    // for( int i = 0; i < n ; i++ ) cout<<cnt[i]<<" ";

    cout << "\nSorted vector is \n";
    printVector(arr);
    return 0;
}