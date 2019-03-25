/*
Runtime: 40 ms, faster than 26.77% of C++ online submissions for ZigZag Conversion.
Memory Usage: 19.3 MB, less than 31.48% of C++ online submissions for ZigZag Conversion.
*/
class Solution {
public:
    int index2pos(int numRows,int i){
        if(i>=numRows)
            i=2*numRows-i-2;
        return i;
    }

    string convert(string s, int numRows) {
        vector<string> vs(numRows,"");
        int divisor = max(2*numRows - 2,1);
        string ret;
        for(string::size_type i=0;i<s.size();i++){
            vs[index2pos(numRows,i%divisor)]+=s[i];
        }
        for(string s : vs){
            ret += s;
        }
        return ret;
    }
    

};