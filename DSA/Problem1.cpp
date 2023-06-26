#include<iostream>
#include<unordered_map>

using namespace std;


/*Given a string which consists of lowercase or uppercase letters,
find the length of the longest palindromes that can be built with those
letters. Letters are case sensitive*/

string inputString(){
    string strInput;
    cin>>strInput;
    return strInput;
}

int main(){
    
    int ans;
    string str = inputString();
    int n=str.size();
        unordered_map<char,int> m;
        for(char c:str) m[c]++;
        if(m.size()==1)
            ans = n;
            
        int oddCount=0;
        for(auto i :m){
            if(i.second%2==1) oddCount++;
        }
        if(oddCount>1)
            ans = n-oddCount+1;
        else 
            ans = n;
        
    std::cout << ans << std::endl;
            
    
    return 0;
}