/*
Runtime: 12 ms, faster than 99.84% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 10.5 MB, less than 98.92% of C++ online submissions for Longest Substring Without Repeating Characters.
*/

/*
总结：
vector代替unordered_map,不用维护红黑树。
*/

class Solution {

public:
    int lengthOfLongestSubstring(string s) {
        vector<string::const_iterator> letter_index(128); //默认初始化，但string::iterator的空怎么表示。
        string::const_iterator l=s.cbegin(),r=s.cbegin();
        string::difference_type max_dist = 0;
        while(r!=s.cend()){
            if(letter_index[*r] >= l){  //不用map后，这里可以直接索引。
                max_dist = max(max_dist,r-l);
                l = letter_index[*r]+1;
            }
            letter_index[*r]=r;
            ++r;            
        }
        max_dist = max(max_dist,r-l);
        return max_dist;
    }
};
