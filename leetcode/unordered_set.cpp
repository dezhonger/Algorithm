#include<cstdio>
#include<iostream>
#include<unordered_set> 
using namespace std;
int main(){
    unordered_set<int> us;
    us.insert(1);
    us.insert(2);
    us.insert(3);
    cout<<us.count(6)<<endl;
    return 0;
}