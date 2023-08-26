#include <bits/stdc++.h>
#define ll long long
using namespace std;

//소수 판정
bool isPrime(ll x) {
    if(x == 1) return false;
    
    for(ll i=3; i*i<=x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

//10진수 -> k진수 변환
vector<int> convert(int n, int k) {
    vector<int> v;
    while(n != 0) {
        v.push_back(n % k);
        n /= k;
    }
    
    reverse(v.begin(), v.end());
    return v;
}

int calc(vector<int> num) {
    int cnt = 0;
    string s = "";
    
    for(int i=0; i<num.size(); i++) {
        if(num[i] != 0) {
            s += ('0' + num[i]);
            continue;
        }
        
        if(s.empty()) continue;
        
        if(isPrime(stoll(s))) {
            cnt += 1;
        }
        s = "";
    }
    
    if(!s.empty() && isPrime(stoll(s))) {
        cnt += 1;
    }   
    
    return cnt;
}

int solution(int n, int k) {
    vector<int> num = convert(n, k);
    
    //k진수 변환 후에 조건에 맞는 소수의 개수 반환
    return calc(num);
}
