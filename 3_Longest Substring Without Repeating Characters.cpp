/*
Runtime: 20 ms, faster than 97.40% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 14.8 MB, less than 79.83% of C++ online submissions for Longest Substring Without Repeating Characters.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string::const_iterator l=s.cbegin(),r=s.cbegin();
        string::difference_type max_dist = r-l;
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