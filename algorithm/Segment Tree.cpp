/*
[1]浅谈线段树 https://www.cnblogs.com/TheRoadToTheGold/p/6254255.html
[2]基于DFS的线段树空间优化 http://www.cppblog.com/MatoNo1/archive/2015/05/05/195857.html

总结 
线段树的函数实现:建树,单点查询,单点修改,区间查询,区间修改
维护区间信息,最重要的是支持区间修改.[1]的线段树基于完全二叉树,[2]的线段树基于DFS.

要点难点
1.要点:线段树的表示:左孩子的索引,右孩子索引,判断线段上位置x的元素在树的左侧还是右侧.
[1]中使用完全二叉树,必须将node_index=0的结点做哨兵,左孩子的索引为2*tree.node_index,右孩子的索引为2*tree.node_index+1;mid = (tree.l+tree.r)/2(下取整),左孩子的线段区间为[tree.l,mid],右孩子的线段区间为[mid+1,tree.r] 
[2]中使用DFS,可以看到DFS的叶子的node_index仍然和实际的数组一一对应.左孩子:tree.node_index+1,右孩子:tree.node_index+tree.left_child.size+1;mid及左右孩子的线段区间同上.
其中tree.size=(mid-l+1)*2-1=(mid-l)*2+1,原因,从边来看,(树枝-树叶)*2=树枝+树叶-1
注意:node_index对应[1]中红字,线段区间对应[1]中蓝字
2.难点:为什么[1]中线段树结构体要开4倍空间.
当线段长度为2^n+4时,构成这个线段树的满二叉树就需要2*2^n-1.另外还多4个元素,为了全都能索引,至少还要2^n+2,即3*2^n+1.
参考[2]中的线段长为6的图,图中只索引到11是因为4,5和9,10之间需要填充2个叶子来实现索引.
更形式化为2^n+m时,当n足够大,当m=4,需要3*2^n;当m=8时,需要3.5*2^n...即,需要4倍空间.
由于[2]不需要填充4,5和9,10之间的2个叶子,所以,其所需要的空间就是2*2^n+m,即,需要2倍空间.
3.要点:简介线段树的函数实现
建树,单点查询,单点修改很简单
区间查询的ans是一个private对象,查询涉及的每个叶子都必须将tree.w加给ans.
4.要点&难点:理解区间修改的逻辑
首先,区间修改每次只能同加同减相同的数.
其次,弄懂了tree.f和down函数也就弄懂了区间修改的逻辑.
先说down函数的触发时机:当前树对应的线段区间[tree.l-tree.r]全落在了要修改区间&&tree.f!=0
在当前树对应的线段区间[tree.l-tree.r]全落在了要修改区间的时候,触发惰性特性,对tree.f赋有效值,函数通过这部分结束递归.
tree.f的含义,tree.f的所有子孙节点都处于待更新状态,tree的所有叶子节点都少加1个f.
tree.f等价于就是down函数的前4行,即左右孩子.f+=tree.f,左右孩子.w+=左右孩子对应线段长度*tree.f.

实践:
1.[1]中末尾列的题目
mark
2.求逆序对
见classic_examples的inversion_segmentTree.cpp
*/

//代码见[1]
#include<cstdio>
using namespace std;
int n,p,a,b,m,x,y,ans;
struct node
{
    int l,r,w,f;
}tree[400001];

inline void build(int k,int ll,int rr)//建树 
{
    tree[k].l=ll,tree[k].r=rr;
    if(tree[k].l==tree[k].r)
    {
        scanf("%d",&tree[k].w);
        return;
    }
    int m=(ll+rr)/2;
    build(k*2,ll,m);
    build(k*2+1,m+1,rr);
    tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
inline void down(int k)//标记下传 
{
    tree[k*2].f+=tree[k].f;
    tree[k*2+1].f+=tree[k].f;
    tree[k*2].w+=tree[k].f*(tree[k*2].r-tree[k*2].l+1);
    tree[k*2+1].w+=tree[k].f*(tree[k*2+1].r-tree[k*2+1].l+1);
    tree[k].f=0;
}
inline void ask_point(int k)//单点查询
{
    if(tree[k].l==tree[k].r)
    {
        ans=tree[k].w;
        return ;
    }
    if(tree[k].f) down(k);
    int m=(tree[k].l+tree[k].r)/2;
    if(x<=m) ask_point(k*2);
    else ask_point(k*2+1);
}
inline void change_point(int k)//单点修改 
{
    if(tree[k].l==tree[k].r)
    {
        tree[k].w+=y;
        return;
    }
    if(tree[k].f) down(k);
    int m=(tree[k].l+tree[k].r)/2;
    if(x<=m) change_point(k*2);
    else change_point(k*2+1);
    tree[k].w=tree[k*2].w+tree[k*2+1].w; 
}
inline void ask_interval(int k)//区间查询 
{
    if(tree[k].l>=a&&tree[k].r<=b) 
    {
        ans+=tree[k].w;
        return;
    }
    if(tree[k].f) down(k);
    int m=(tree[k].l+tree[k].r)/2;
    if(a<=m) ask_interval(k*2);
    if(b>m) ask_interval(k*2+1);
}
inline void change_interval(int k)//区间修改 
{
    if(tree[k].l>=a&&tree[k].r<=b)
    {
        tree[k].w+=(tree[k].r-tree[k].l+1)*y;
        tree[k].f+=y;
        return;
    }
    if(tree[k].f) down(k);
    int m=(tree[k].l+tree[k].r)/2;
    if(a<=m) change_interval(k*2);
    if(b>m) change_interval(k*2+1);
    tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
int main()
{
    scanf("%d",&n);//n个节点 
    build(1,1,n);//建树 
    scanf("%d",&m);//m种操作 
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&p);
        ans=0;
        if(p==1)
        {
            scanf("%d",&x);
            ask_point(1);//单点查询,输出第x个数 
            printf("%d",ans);
        } 
        else if(p==2)
        {
            scanf("%d%d",&x,&y);
            change_point(1);//单点修改 
        }
        else if(p==3)
        {
            scanf("%d%d",&a,&b);//区间查询 
            ask_interval(1);
            printf("%d\n",ans);
        }
        else
        {
             scanf("%d%d%d",&a,&b,&y);//区间修改 
             change_interval(1);
        }
    }
}