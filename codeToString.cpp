#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string,char> mp;
    ifstream code;
    string temp,temp2;
    code.open("morseCode.txt");
    for(int i=0 ; i<26 ; i++){
        getline(code,temp);
        mp[temp]='a'+i;
    }
    for(int i=26 ; i<36 ; i++){
        getline(code,temp);
        mp[temp]='0'+i;
    }
    code.close();
    cout<<"Enter a code to convert to string :\n";
    getline(cin,temp);
    int n=temp.size();
    string ans="";
    for(int i=0 ; i<n ; i++){
        if(temp[i]=='0'&&temp[i+1]=='0'){
            ans+=mp[temp2];
            if(temp[i+5]=='0'){
                ans+=' ';
                i+=6;
            }else{
                i+=2;
            }
            temp2.clear();
            continue;
        }
        temp2+=temp[i];
    }
    ans+=mp[temp2];
    cout<<ans;
    return 0;
}