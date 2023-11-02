#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
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
    getline(cin,temp);
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
    return 0;
}