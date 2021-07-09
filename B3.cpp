#include<iostream>
#include<fstream>
using namespace std;

fstream out("output.txt",ios::out);
int a[1000][1000];
int m, n;
int s;
void input()
{
    fstream in ("Input.txt",ios::in);
    in >> m >> n;
    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= n ; j ++)
        {
            in>>a[i][j];
        }
    }
    in.close();
}

int main()
{
    input();
    a[0][0] = 1;
    for(int i = 1; i <= m + 1 ; i ++)
    {
        a[i][0] = 1;
        a[i][n+1] = 1;
    }

    for(int i = 1; i <= n + 1; i ++)
    {
        a[0][i] = 1;
        a[m+1][i] = 1;
    }
    for(int i = 1; i <= m ; i ++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j]== 1)
            {
                if(a[i][j-1] == 0) s ++;
                if(a[i-1][j] == 0) s ++;
                if(a[i+1][j] == 0) s ++;
                if(a[i][j+1] == 0) s++;
            }
        }
    }
    cout<<s<<endl;
    for(int i = 0; i <= m  + 1; i ++)
    {
        for(int j = 0; j <= n ;j ++)
        {
            if(a[i][j]) cout<<'x';
            else cout<<'0';
        }
        cout<<endl;
    }
}
