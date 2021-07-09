#include<iostream>

using namespace std;

int main()
{
    string s ;
    cin>>s;
    string res;
    s += "$";
    char cmp = s[0];
    int k = 1;
    for(int i = 1; i < s.size(); i ++)
    {
        if(s[i] ==cmp) k ++;
        else{
            if(k > 1) res += to_string(k) + cmp;
            else res += cmp;
            cmp = s[i];
            k = 1;
        }

    }
    cout<<res;
}
