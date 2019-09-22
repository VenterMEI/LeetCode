/*
dp
每次s的有效范围+1.
有哨兵减少了边界判断快不少，但是多了一点点的空间开销。
*/

/*
Runtime: 4 ms, faster than 96.01% of C++ online submissions for Longest Valid Parentheses.
Memory Usage: 9.8 MB, less than 10.71% of C++ online submissions for Longest Valid Parentheses.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
	s=' '+s;
	vector<int> dp(s.size());
	int ret=0;
	for(int i=0;i<s.size();++i){
		if(s[i]!=')'){
			continue;
		}
		if(s[i-1]=='('){
			dp[i]=dp[i-2]+2;
		}
		if(s[i-1]==')' && s[i-dp[i-1]-1]=='('){
			dp[i]=dp[i-dp[i-1]-2]+dp[i-1]+2;
		}
		if(ret<dp[i]){
			ret=dp[i];
		}
	}
	return ret;
    }
};


/*
Runtime: 4 ms, faster than 96.01% of C++ online submissions for Longest Valid Parentheses.
Memory Usage: 9.4 MB, less than 85.71% of C++ online submissions for Longest Valid Parentheses.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
    vector<int> dp(s.size());
    int ret=0;
    if(s.size()>=2 && s[0]=='(' && s[1]==')'){
        dp[1]=2;
        ret=2;
    }
    for(int i=2;i<s.size();++i){
        if(s[i]!=')'){
            continue;
        }
        if(s[i-1]=='('){
            dp[i]=dp[i-2]+2;
        }
        if(s[i-1]==')' && i-dp[i-1]>=1 && s[i-dp[i-1]-1]=='('){
            dp[i]=(i-dp[i-1]>=2?dp[i-dp[i-1]-2]:0)+dp[i-1]+2;
        }
        if(ret<dp[i]){
            ret=dp[i];
        }
    }
    return ret;
    }
};