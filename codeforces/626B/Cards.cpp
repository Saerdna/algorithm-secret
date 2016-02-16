#include <cstdio>
#include <math.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

map<int, bool>vis;

int HashFunc(int sta[]){
    return sta[0]*201*201+sta[1]*201+sta[2];
}
int convert(char ch){
    switch (ch){
        case 'B':
            return 0;
        case 'G':
            return 1;
        case 'R':
            return 2;
    }
    return -1;
}
void show(int sta[]){
    for(int i = 0; i < 3; ++i){
        printf("%d--%d\n", i, sta[i]);
    }
    puts("==========");
}
void DFS(int sta[]){
    //show(sta);
    if(vis.find(HashFunc(sta)) != vis.end()){
        return;
    }
    vis[HashFunc(sta)] = true;
    for(int i = 0; i < 3; ++i){
        if(sta[i]>1){
            sta[i]--;
            DFS(sta);
            sta[i]++;
        }
        if(sta[i]>0 && sta[(i+1)%3]>0){
            sta[(i+2)%3]++;
            sta[i]--;
            sta[(i+1)%3]--;
            DFS(sta);
            sta[(i+2)%3]--;
            sta[i]++;
            sta[(i+1)%3]++;
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    char ch;
    int count[3] = {0};
    for(int i = 0 ; i < n; ++i){
        scanf(" %c", &ch);
        count[convert(ch)]++;
    }
    //show(count);
    DFS(count);
    memset(count,0, sizeof(count));
    char buff[4] = {"BGR"};
    for(int i = 0; i < 3; i++){
        count[i]++;
        if(vis.find(HashFunc(count))!=vis.end()){
            printf("%c", buff[i]);
        }
        count[i]--;
    }
    puts("");
}
