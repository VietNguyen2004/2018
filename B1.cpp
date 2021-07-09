#include<iostream>
using namespace std;

int main()
{
    string s = "";
    int k;
    string goc ;
    cin>>goc;
    cin>>k;
    // lower
    for(char x: goc)
    {
        if(x >='a' && x <= 'z')//lower
        {
            if(x + k > 'z'){
                k-= 'z' - x -1;
                s += ('a' + k);
            }
            else{
                s += x + k;
            }
        }
        else{//upper
            if(x + k > 'Z'){
                k-= 'Z' - x -1;
                s += ('A' + k);
            }
            else{
                s += x + k;
            }
        }
    }
    cout<<s;
}
