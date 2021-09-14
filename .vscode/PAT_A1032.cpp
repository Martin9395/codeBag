#include <cstdio>
#include<stdlib.h>
const int maxn = 100010;
 
//定义链表
struct Node {
    int address, data, next;
    int flag;
} node[maxn];
 
int main() {
    //初始化
    for(int i = 0; i < maxn; i++)
        node[i].flag = 0;
    //读取数据
    int b1, b2, n;
    int address, next;
    char data;
    scanf("%d %d %d", &b1, &b2, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    //遍历链表标记特殊性质，此题不需要统计有效结
    for(int i=b1;i!=-1;i=node[i].next){
        node[i].flag=1;
    }
    int flag=-1;
    //此题不需要排序，直接进行第⑤步
    for(int i=b2;i!=-1;i=node[i].next){
        if(node[i].flag==1){
            flag=i;
            break;
        }
    }
    if(flag != -1)
        printf("%05d", flag);
    else
        printf("-1\n", flag);
    system("pause");
    return 0;
}

