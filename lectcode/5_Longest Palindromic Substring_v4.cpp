/*
Runtime: 8 ms, faster than 97.54% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 10 MB, less than 64.55% of C++ online submissions for Longest Palindromic Substring.
*/

/*
note
Manacher‘s Algorithm
参考 https://blog.csdn.net/happyrocking/article/details/82622881
算法的三个亮点：
1.填充字符统一奇偶
2.两侧设置哨兵代替检查越界
3.利用回文的对称性为radius[i]预设一个起点。

注意"="运算符会额外产生元素创建开销。 ss+="miao"; vs ss=ss+"miao";
其它几个版本也存在这种情况，导致运行时间很长，并不是代码本身的问题。
*/

class Solution {
public:
    string longestPalindrome(string s) {
        /*if(!s.size()){
            return s;      //虽然两侧哨兵，但实际上不需要额外判断
        }*/
        string ss;
        for(char c:s){
            /*
            将这两段代码改为ss=ss+"#"+c;时，结果为96ms，142MB。
            将代码改为ss=ss+"#";ss=ss+c;时，结果为168ms,274MB。
            原因应该是string重载了+=操作符。而每使用一次"="就涉及一次string的创建。
            */
            ss+="#";
            ss+=c;    //1
        }
        ss="@"+ss+"#^";     //2
        
        int right_margin = 0,center=0;
        vector<int> radius(ss.size(),0);
        
        for(int i=1;i<ss.size()-1;i++){
            if(i<right_margin){
                radius[i]=min(right_margin-i,radius[2*center-i]);    //3
            }
            while(ss[i+radius[i]+1]==ss[i-radius[i]-1]){
                ++radius[i];
            }
            
            if(radius[i]+i>right_margin){
                center=i;
                right_margin = i+radius[i];
            }
        }
        
        int max_index = max_element(radius.begin(),radius.end())-radius.begin();
        return s.substr((max_index-1-radius[max_index])/2,radius[max_index]);         
    }
};