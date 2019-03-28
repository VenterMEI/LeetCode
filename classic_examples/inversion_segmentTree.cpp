/*
    算法说明:
    代码主要是把握线段树的思想为主,目前不支持输入重复数字.如果想接受重复,参考逆序三元组的去重操作.
    segment tree维护的是当前的数字出现的次数.tree[1]表示的是最小数出现的次数...
    我是逆着求的,每加入一个数,通过区间查询找出因此出现了多少个顺序对(包括重复数字).
    然后单点更新,将这个数加入到segment tree中.
*/
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Node{
    int val,pos;
    bool operator <(const Node b){
        return this->val<b.val;
    }
};
Node *origin_list;
int input_length,*tree,*new_list;


void update_point(int l,int r,int now_tree_index,int change_segment_pos){
    //change value就是1.
    //l/r对线段而言,tree_index指完全二叉树的node,segment_pos也是对线段而言
    if(l==r){
        ++tree[now_tree_index];
        return ;
    }
    int mid = (l+r)/2;
    if(change_segment_pos<=mid){
        update_point(l,mid,2*now_tree_index,change_segment_pos);
    }else{
        update_point(mid+1,r,2*now_tree_index+1,change_segment_pos);
    }
    tree[now_tree_index]= tree[now_tree_index*2]+tree[now_tree_index*2+1];
}

int qurey(int l,int r,int ql,int qr,int now_tree_index){
    if(ql<=l && qr>=r){
        return tree[now_tree_index];
    }
    int mid = (l+r)/2,sum = 0;
    if(mid>=ql){
        sum += qurey(l,mid,ql,qr,now_tree_index*2);
    }
    if(mid+1<=qr){
        sum += qurey(mid,r,ql,qr,now_tree_index*2+1);
    }
    return sum;

}


int main(){
    cin>>input_length;
    origin_list = new Node[input_length+1];
    new_list= new int[input_length+1];
    tree =new int[4*input_length+1];
    for(int i=0;i<=4*input_length;i++){
        tree[i]=0;
    }
    for(int i=1,val;i<=input_length;i++){
        cin>>val;
        origin_list[i].val=val;
        origin_list[i].pos=i;
    }
    sort(origin_list+1,origin_list+1+input_length);

    for(int i=1;i<=input_length;++i){
        new_list[ origin_list[i].pos ] = i;
    }

    cout<<"离散化 ";
    for(int i=1;i<=input_length;i++){
        cout<<new_list[i]<<" ";
    }
    cout<<endl;

    int _ans = 0;
    for(int i=1;i<=input_length;i++){
        _ans += qurey(1,input_length,1,new_list[i],1);   //_ans记录所有顺序对,包括邻接并重复的数对
        update_point(1,input_length,1,new_list[i]);
    }
    cout<<(input_length)*(input_length-1)/2-_ans<<endl;

}