/*
 * count the number with O(n) time O(1) memory
 * problem Url: http://weibo.com/1915548291/A6NGzcLqy
 *
 */
#include <cstdio>
#include <cstring>
#include <ctime>
#include <assert.h>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    srand(time(0));
    int n;
    int array[100];
    scanf("%d", &n);
    assert(n > 0 && n < 100);
    for (int i = 1; i <= n; ++i) {
        array[i] = (rand() % n) + 1; 
        //scanf("%d", &array[i]);
        printf("%d ", array[i]);
    }
    puts("");
    for (int i = 1; i <= n; ++i) {
        if (array[i] < 0) continue;
        bool succ = false;
        while (succ == false) {
            if (array[i] == i) {
                array[i] = -1;
                succ = true;
            } else if (array[i] < i) {
                array[array[i]] -= 1;
                array[i] = 0;
                succ = true;
            } else if (array[i] > i) {
                if (array[array[i]] == array[i]) {
                    array[array[i]] = -2;
                    array[i] = 0;
                    succ = true;
                } else if (array[array[i]] < 0) {
                    array[array[i]] -= 1;
                    array[i] = 0;
                    succ = true;
                } else {
                    swap(array[i], array[array[i]]);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("number:%d\ttimes:%d\n", i, abs(array[i]));
    }
}
