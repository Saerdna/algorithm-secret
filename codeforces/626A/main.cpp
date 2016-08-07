#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;
bool gao(char *s, char*t){
    int V = 0, H = 0;
    for(char *p = s; p != t; p++){
        if(*p == 'D'){
            V ++;
        } else if(*p == 'U'){
            V --;
        }else if(*p =='L'){
            H++;
        }else if(*p =='R'){
            H--;
        }
    }
    return (H==0&&V==0);
}
int main(){
    int n;
    scanf("%d", &n);
    char cmd[1024];
    scanf(" %s", cmd);
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if((j - i) % 2 == 0)continue;
            ans += gao(cmd + i, cmd + j + 1); 
        }
    }
    printf("%d\n",ans);
}
