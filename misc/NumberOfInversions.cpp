// codingninjas url: https://www.naukri.com/code360/problems/number-of-inversions_6840276?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM
// Using merge sort algo
int res = 0;
void merge(vector<int> & arr, int l1, int r1, int l2, int r2)
{
    vector<int> temp;
    int start = l1, end = r2;
    while(l1 <= r1 && l2 <= r2)
    {
        if(arr[l1] > arr[l2])
        {
            res = res + (r1-l1+1);
            temp.push_back(arr[l2++]);
        }
        else
        {
            temp.push_back(arr[l1++]);
        }
    }

    while(l1 <= r1)
    {
        temp.push_back(arr[l1++]);
    }

    while(l2 <= r2)
    {
        temp.push_back(arr[l2++]);
    }

    for(int i=start,j=0; i<=end;i++,j++)
    {
        arr[i] = temp[j];
    }
}
void mergeSort(vector<int>& arr, int start, int end)
{
    if(start >= end) return;

    int mid = (end + start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, mid, mid+1, end);
}


int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.


    mergeSort( a, 0, n-1);

    return res;
    
}


