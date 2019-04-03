/*
Runtime: 12 ms, faster than 99.84% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Longest Substring Without Repeating Characters.
*/

/*
总结：
subsequence 可以不连续 & substring 连续
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string::const_iterator l=s.cbegin(),r=s.cbegin();
        string::difference_type max_dist = 0;
        while(r!=s.cend()){
            int is_same = 0;
            auto l_copy = l;
            for(;l_copy!=r;l_copy++){
                if(*l_copy==*r){
                    is_same = 1;
                    break;
                }    
            }
            
            if(is_same){
                max_dist = max(max_dist,r-l);
                l=l_copy+1;
            }        
            r++;
        }
        max_dist = max(max_dist,r-l);
        return max_dist;
    }
};