/*
Runtime: 16 ms, faster than 97.38% of C++ online submissions for String to Integer (atoi).
Memory Usage: 14.5 MB, less than 74.09% of C++ online submissions for String to Integer (atoi).
*/
class Solution {
public:
    int myAtoi(string str) {
        bool is_positive = true;
        //str = "-91283472332";
        long long num = 0;
        
        //space in front
        string::size_type skip_space = str.find_first_not_of(' ');
        if(skip_space == string::npos){
            return 0;
        }
        string::const_iterator pc = str.cbegin()+skip_space;    

        //+/-
        if(*pc=='-'){
            is_positive = false;
            ++pc;
        }else if(*pc=='+'){
            ++pc;
        }else if(*pc<'0' or '9'<*pc ){
            return 0;
        }
        
        while('0'<=*pc and *pc<='9'){
            num = num*10+*pc-'0';
            //cout<<num<<" "<<*pc<<endl;
            if(num>INT32_MAX){
                return is_positive?INT32_MAX:INT32_MIN;
            }
            ++pc;
        }
        
        return is_positive? num : -num;
    }
};