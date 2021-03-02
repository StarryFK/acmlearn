#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
#define IINF 0x3f3f3f3f //常用代表 INT 类型很大的数

vector<int> to[26];     //邻接表储存图
bool visit[26];         //DFS访问标记
bool appear[26];        //判断字母是否出现在图中
int buf[10];            //DFS状态暂存
int ans[10];            //答案
int minb=IINF;          //答案最小带宽
int cnt=0;              //计数多少个字母

//读入数据并处理存储
bool read(){
	for(int i=0; i<26; i++){                //清空邻接表
		to[i].clear();
	}
	memset(appear, 0, sizeof(appear));      //清空字母出现
	char ch=0;
	while(ch!='\n'){                        //判断是否行结尾
		ch = getchar();                     //获取第一个字母
		if(ch=='#'){
			return false;
		}
		int x = ch-'A';
		appear[x]=1;                        //记录字母出现
		getchar();                          //读取冒号

        //读取冒号后字母
		for(ch=getchar();ch>='A' && ch<='Z'; ch=getchar()){  
			int y = ch-'A';
			appear[y]=1;
			to[x].push_back(y);     //记录入邻接表
			to[y].push_back(x);
		}
	}
	return true;
}

//检查两个字母是否在图上相连
bool check(int i, int j){
	for(auto t : to[i]){
		if(t==j){
			return true;
		}
	}
	return false;
}

//计算当前排列的带宽
void calc(){
	int bid=0;
	for(int i=0; i<cnt; i++){
		for(int j=0; j<cnt; j++){
			if(i!=j && check(buf[i],buf[j])){
				bid = max(bid, abs(i-j));
			}
		}
	}

    //因为带宽相同，答案取最小字典序的排列，故用 “<”
	if(bid < minb){
		for(int i=0; i<cnt; i++){
			ans[i] = buf[i];
		}
		minb = bid;
	}
}

//顾名思义 DFS 暴力搜索答案
void dfs(int cur){
	if(cur==cnt){   //搜索深度达到字母个数
		calc();     
		return;
	}

    //否则继续下一层递归
	for(int i=0; i<26; i++){
		if(appear[i] && !visit[i]){
			buf[cur] = i;
			visit[i]=1;
			dfs(cur+1);
			visit[i]=0;
		}
	}
}

int main(){
	while(read()){
		cnt=0;
		for(int i=0; i<26; i++){    //数出现的字母个数
			if(appear[i]){
				cnt++;
			}
		}
		minb=IINF;
		dfs(0);
		for(int i=0; i<cnt; i++){
			printf("%c ", ans[i]+'A');
		}
		printf("-> %d\n", minb);
	}
}
