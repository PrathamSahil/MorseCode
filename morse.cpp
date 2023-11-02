#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

void s2c(){
    string arr[36];
    ifstream code;
    string temp;
    code.open("morseCode.txt");
    for(int i=0 ; i<36 ; i++){
        getline(code,temp);
        arr[i]=temp;
    }
    code.close();
    cout<<"Enter a string to convert to morse code :\n";
    getline(cin>>ws,temp);
    int n=temp.size();
    string ans="";
    for(int i=0 ; i<n ; i++){
        if('A'<=temp[i]&&'Z'>=temp[i]) temp[i]=temp[i]+'a'-'A';
        if('a'<=temp[i]&&'z'>=temp[i]){
            ans+=arr[temp[i]-'a'];
            ans+="000";
        }else if(temp[i]==' '){
            ans+="0000";
        }else{
            ans+=arr[temp[i]-'0'+26];
            ans+="000";
        }
    }
    ans=ans.substr(0,ans.size()-3);
    cout<<ans;
    return;
}

void c2s(){
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
    getline(cin>>ws,temp);
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
    return;
}

int main(){
    cout<<"Welcome to Morse Writer and Interpreter\n\n";
    cout<<"Enter 0 to convert message to morse code or 1 to interpret a morse coded message : ";
    int x;
    cin>>x;
    if(x==0) {
        s2c();
    }else if(x==1) {
        c2s();
    }else {
        cout<<"fuck you!!";
    }
    return 0;
}