#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class ABBA{
    public:
        string canObtain(string initial, string target){
            while(target != initial){
                if(target.size() <= initial.size()){
                    return "Impossible";
                }
                if(target[target.size() - 1] == 'A'){
                    target.pop_back();
                }else{
                    target.pop_back();
                    reverse(target.begin(), target.end());
                }
            }
            return "Possible";
        }
};
int main(){
    ABBA obj;
}
