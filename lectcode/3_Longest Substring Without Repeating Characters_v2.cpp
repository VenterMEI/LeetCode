/*
总结：
对比跑了solution里的sliding window和Sliding Window Optimized(hash),结果一致，仍然时前者稍好一些。
这里的iterator optimized版比index optimized版速度一致，而iterator版比index版慢不少，很奇怪。
optimized版少了一个判断。
*/


/*
Runtime: 36 ms, faster than 46.73% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 11.3 MB, less than 98.54% of C++ online submissions for Longest Substring Without Repeating Characters.
*/
class Solution {
//iterator
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,string::const_iterator> letter_index;
        string::const_iterator l=s.cbegin(),r=s.cbegin();
        string::difference_type max_dist = 0;
        while(r!=s.cend()){
            if(letter_index.find(*r)!=letter_index.end() && letter_index[*r]>=l){
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


/*
Runtime: 20 ms, faster than 94.15% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 11.3 MB, less than 98.54% of C++ online submissions for Longest Substring Without Repeating Characters.
*/
class Solution {
//iterator optimized
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,string::const_iterator> letter_index;
        string::const_iterator l=s.cbegin(),r=s.cbegin();
        string::difference_type max_dist = 0;
        while(r!=s.cend()){
            if(letter_index.find(*r)!=letter_index.end()){//优化了判断带来的提升，确实这句话运行次数非常多。
                max_dist = max(max_dist,r-l);
                l = max(letter_index[*r]+1,l);
            }
            
            letter_index[*r]=r;
            ++r;            
        }
        max_dist = max(max_dist,r-l);
        return max_dist;
    }
};

/*
Runtime: 32 ms, faster than 55.92% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 10.8 MB, less than 98.87% of C++ online submissions for Longest Substring Without Repeating Characters.
*/
class Solution {
//index
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        string::size_type l = 0, r = 0;
        string::size_type max_dist = 0;
        while (r < s.size()) {
            if (hash.find(s[r]) != hash.end() && hash[s[r]] >=l) {
                max_dist = max(max_dist, r - l);
                l = hash[s[r]] + 1;
            }
            hash[s[r]] = r;
            ++r;
        }
        max_dist = max(max_dist, r - l);
        return max_dist;
    }
};

/*
Runtime: 20 ms, faster than 94.15% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 11.2 MB, less than 98.54% of C++ online submissions for Longest Substring Without Repeating Characters.
*/
class Solution {
//index optimized
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, string::size_type> hash;
        string::size_type l = 0, r = 0;
        string::size_type max_dist = 0;
        while (r < s.size()) {
            if (hash.find(s[r]) != hash.end()) {
                max_dist = max(max_dist, r - l);
                l = max(hash[s[r]] + 1,l);
            }
            hash[s[r]] = r;
            ++r;
        }
        max_dist = max(max_dist, r - l);
        return max_dist;
    }
};