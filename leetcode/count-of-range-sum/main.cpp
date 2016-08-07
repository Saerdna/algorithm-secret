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
#define see(x) cerr<<#x<<":["<<x<<"]\n";
using namespace std;
typedef long long LL;
const int MAXN = 10000000;
struct SegTree{
    struct Node{
        Node *l, * r;
        int cnt;
        void init(){
            l = r = NULL;
            cnt = 0;
        }
    }nodePool[MAXN];
    int tot = 0;
    Node * newNode(){
        nodePool[tot].init();
        return &nodePool[tot++];
    }
    Node * build(int l, int r){
        Node *node = newNode();
        if(l == r)return node;
        int mid = (l+r)/2;
        node->l = build(l, mid);
        node->r = build(mid + 1, r);
        return node;
    }
    void insert(Node *root, int l, int r, int key, int val){
        if(l == r){
            root->cnt += val;
            return;
        }
        int mid = (l + r)/2;
        if(key<=mid){
            insert(root->l, l, mid, key, val);
        }else{
            insert(root->r, mid + 1, r, key, val);
        }
        root->cnt += val;
    }
    int query(Node *root, int l, int r, int ql, int qr){
        if(ql <= l && qr >= r){
            return root->cnt;
        }
        if(ql > r || qr < l){
            return 0;
        }
        int mid = (l + r) / 2;
        int ans = 0;
        ans += query(root->l, l, mid, ql, qr);
        ans += query(root->r, mid + 1, r, ql, qr);
        return ans;
    }
}seg;
class Solution {
public:
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        map<int, LL> sum;
        LL tmp = 0;
        vector<LL> array;
        int ret = 0;
        for(int i = 0; i < nums.size();i++){
            tmp += nums[i];
            sum[i] = tmp;
            //index[sum[i]].insert(i);
            array.push_back(sum[i]);
            array.push_back(lower + sum[i] - nums[i]);
            array.push_back(upper + sum[i] - nums[i]);
            if(lower <= nums[i] && nums[i]<= upper){
                ret ++;
            }
        }
        sort(array.begin(), array.end());
        array.erase(unique(array.begin(), array.end()), array.end());
        SegTree::Node *root = seg.build(0, array.size());
        for(int i = 0; i < nums.size(); i++){
            int idx = lower_bound(array.begin(), array.end(), sum[i]) - array.begin();
            seg.insert(root,0, array.size(), idx, 1);
        }
        LL l, r;
        for(int i = 0; i < nums.size(); i++){
            //index[sum[i]].erase(i);
            int idx = lower_bound(array.begin(), array.end(), sum[i]) - array.begin();
            seg.insert(root, 0, array.size(), idx, -1);
            l = lower + sum[i] - nums[i];
            r = upper + sum[i] - nums[i];
            int lindex = lower_bound(array.begin(), array.end(), l) - array.begin(); 
            int rindex = lower_bound(array.begin(), array.end(), r) - array.begin();
            int qret = seg.query(root, 0, array.size(), lindex, rindex);
            ret += qret;
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input;
    input.push_back(-2147483647);
    input.push_back(0);
    input.push_back(-2147483647);
    input.push_back(2147483647);
    cout<<sol.countRangeSum(input, -2, 2)<<"\n";
}
