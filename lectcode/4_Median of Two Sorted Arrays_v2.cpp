/*
Runtime: 24 ms, faster than 99.32% of C++ online submissions for Median of Two Sorted Arrays.
Memory Usage: 9.7 MB, less than 99.28% of C++ online submissions for Median of Two Sorted Arrays.
*/

/*
note
          left_part          |        right_part
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
                B[j−1]≤A[i] and A[i−1]≤B[j]
这个代码几乎是对solution的默写，代码设计的巧妙之处见注释。
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size()){
            vector<int> tmp=nums1;nums1=nums2;nums2=tmp;    //开局交换nums1和nums2，确保nums1最短。
        }
        vector<int>::size_type half=(nums1.size()+nums2.size()+1)/2, max_1=nums1.size(),min_1=0;    //当half=(3+2+1)/2=3时，左侧3个右侧2个，所以直接return max_left.
        
        while(true){
            vector<int>::size_type p1=(max_1+min_1)/2,p2=half-p1;
            if(p1<max_1 && nums1[p1]<nums2[p2-1]){ 
                min_1 = p1+1;
            }else if(p1>min_1 && nums1[p1-1]>nums2[p2]){
                max_1=p1-1;
            }else{
                //这样计算return算简便了，p1和p2下标是否有效是始终要检验。
                int medianleft;
                if(p1==0){
                    medianleft=nums2[p2-1];
                }else if(p2==0){
                    medianleft=nums1[p1-1];
                }else{
                    medianleft=max(nums1[p1-1],nums2[p2-1]);
                }
                if((nums1.size()+nums2.size())%2){
                    return medianleft;
                }

                int medianright;
                if(p1==nums1.size()){
                    medianright=nums2[p2];
                }else if(p2==nums2.size()){
                    medianright=nums1[p1];
                }else{
                    medianright=min(nums1[p1],nums2[p2]);
                }
                return (medianleft+medianright)/2.0;
		    }
        }
        return 0.0;
    }
};