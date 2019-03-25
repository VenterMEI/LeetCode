/*
Runtime: 76 ms, faster than 52.28% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 13.3 MB, less than 52.53% of C++ online submissions for Longest Palindromic Substring.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        //odd number
        for(string::const_iterator cps=s.cbegin();cps!=s.cend();++cps){
            string::const_iterator l=cps,r=cps;
            while(true){
                if(*l==*r){
                    if(l==s.cbegin() or r==s.cend()-1){
                        --l;++r; 
                        break;
                    }
                    --l;++r; 
                }else{
                    break;
                }
            }
            if(ret.length()<r-l-1){
                ret = string(l+1,r);
            }
            
        }
        
        //even number
        for(string::const_iterator cps=s.cbegin();cps!=s.cend();++cps){
            string::const_iterator l=cps,r=cps+1;
            while(true){
                if(*l==*r){
                    if(l==s.cbegin() or r==s.cend()-1){
                        --l;++r;
                        break;
                    }
                    --l;++r;   
                }else{
                    break;
                }
            }
            if(ret.length()<r-l-1){
                ret = string(l+1,r);
            }
            
        }
        return ret;
    }
};