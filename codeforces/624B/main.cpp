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
int main(){
    int n;
    scanf("%d", &n);
    int arr[30];
    for(int i = 0; i < n; i ++){
        scanf("%d", &arr[i]);
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        while(true){
            if(arr[i] == 0)break;
            bool succ = true;
            for(int j = 0; j < i; j++){
                if(arr[i] == arr[j]){
                    arr[i]--;
                    succ = false;
                    break;
                }
            }
            if(succ)break;
        }
        ans += arr[i];
    }
    printf("%I64d\n", ans);
}
