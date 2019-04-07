/*
Runtime: 120 ms, faster than 5.28% of C++ online submissions for Median of Two Sorted Arrays.
Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Median of Two Sorted Arrays.
*/

/*
note
可以在程序开始的地方判断nums1和nums2的长度，确保nums1不比nums2短，简化后续的程序。
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::size_type total = nums1.size()+nums2.size(),p1=0,p2=0;
        vector<int>::size_type count = 0,end = total%2 ? total/2+1:total/2;
        bool is_nums1;
        
        while(count<end){
            if(p1<nums1.size() && p2<nums2.size()){
                if(nums1[p1]>nums2[p2]){
                    p2++;
                    is_nums1=false;
                }else{
                    p1++;
                    is_nums1=true;
                }
            }else if(p1<nums1.size()){
                p1++;
                is_nums1=true;
            }else if(p2<nums2.size()){
                p2++;
                is_nums1=false;
            }
            count++;
            cout<<count<<" "<<(is_nums1?nums1[p1-1]:nums2[p2-1])<<endl;
        }
        
        if(total%2){
            return is_nums1?nums1[p1-1]:nums2[p2-1];
        }else{
            if(p1<nums1.size() && p2<nums2.size()){
                return ((is_nums1?nums1[p1-1]:nums2[p2-1]) + min(nums1[p1],nums2[p2]))/2.0;
            }else if(p1<nums1.size()){
                return ((is_nums1?nums1[p1-1]:nums2[p2-1]) + nums1[p1])/2.0;
            }else if(p2<nums2.size()){
                return ((is_nums1?nums1[p1-1]:nums2[p2-1]) + nums2[p2])/2.0;
            }
        }
        return 0.0; //不必要的代码。
    }
};