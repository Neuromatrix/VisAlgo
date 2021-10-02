// #include <bits\stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <climits>
#include <complex>
#include <list>
#include <map>
#include <bitset>
#include <numeric>
#include <deque>
#include <stack>
#include <cassert>
#include <queue>
#include <TXLib.h> 
using namespace std;
using ll = long long;   
using ull = unsigned long long;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
inline void solve(){
    int arr[100] ={};
    for(size_t i = 0; i < 100; i++){
        arr[i] = rand()%100;
    }
    txCreateWindow(1500,800);
    size_t j = 200, dist = 5;
    for(size_t i = 0; i < 100; i++){
        txRectangle(j,600,j+dist,arr[i]);
        j+=2*dist;
    }
}
int main(){
    prepare();
    size_t tt = 1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}