// leetcode url- https://leetcode.com/problems/reverse-pairs/

class Solution {
public:
    int res = 0;

    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return res;
    }
    void merge(vector<int> & arr, int l1, int r1, int l2, int r2)
    {
        vector<int> temp;
        int start = l1, end = r2;
        // cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
        while(l1 <= r1 && l2 <= r2)
        {
           
            if(arr[l1] > arr[l2])
            {
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

    void countPairs(vector<int> & arr, int l1, int r1, int l2, int r2)
    {
        for(int i=l1;i<=r1;i++)
        {
            while(l2 <= r2 && arr[i] > 2LL* arr[l2])
            {
                res = res + (r1 - i + 1);
                l2++;
            } 
            
        }
        // return res;
    }

    void mergeSort(vector<int>& arr, int start, int end)
    {
        if(start >= end) return;

        int mid = (start + end)/2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        countPairs(arr, start, mid, mid+1, end);
        merge(arr, start, mid, mid+1, end);
    }

};
