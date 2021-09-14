#include <cstdio>
const int maxn = 10010;

struct Node{
    char data;//数据域
    int next;//指针域
    bool flag;//节点是否在第一条链表中出现  
} node[maxn];

int main()
{
    for (int i = 0; i < maxn;i++){
        node[i].flag = false;//默认均没有出现 -> 数据全是第二条链表的
    }
    int num, s1, s2; //s1,s2分别代表两条链表的首地址
    int address, next;//节点地址与后继地址
    char data;//存放数据
    //printf("请输入两条链表的首地址和num数目:");
    scanf("%d %d %d",&s1,&s2,&num);
    //printf("循环输入node节点的信息：");
    for (int i = 0; i < num; i++){
        scanf("%d %c %d", &address,&data,&next);
        node[address].data = data;
        node[address].next = next;
    }
    int pointer;
    for (pointer = s1; pointer != -1; pointer = node[pointer].next){
        node[pointer].flag = true;//枚举第一条链表的所有节点，令其出现次数为1
    }
    for (pointer = s2; pointer != -1; pointer = node[pointer].next){
        if(node[pointer].flag == true) break;
    }
    

        return 0;
}