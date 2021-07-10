#include<iostream>
#include<fstream>
using namespace std;

struct tram
{
    int time ;
    int count ;
};

tram a[1000];
int n;
int vechile;
int res;
void quickSort(int l , int r)
{
    int i = l ;
    int j = r;
    while(i < j)
    {
        int m = (l + r) /2 ;
        while(a[i].time < a[m].time)
            i ++;
        while(a[j].time > a[m].time)
            j --;
        if(i <= j)
            swap(a[i++], a[j--]);
    }
    if(j > l ) quickSort(l,j);
    if(i < r) quickSort(i,r);
}

void input()
{
    fstream in("THUPHI.INP", ios::in);
    in >> n >> vechile;
    for(int i = 1; i <= n; i ++)
    {
        in >>a[i].time;
        a[i].count = 0;
    }
    in.close();
    quickSort(1,n);
}

void solve()
{

   while(vechile > 0)
   {
        for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j < i ; j++)
        {
            while((a[i].count + 1 )  * a[i].time > (a[j].count + 1) * a[j].time)
            {
                if(vechile > 0) {
                    a[j].count ++;
                    vechile --;
                }
                else return ;
            }
        }
        if(vechile > 0) {
            a[i].count ++;
            vechile --;
        }
        else return ;
        }
   }
}
int dem()
{
    int res = 0;
    for(int i = 1; i <= n ; i ++)
    {
        res = max(res,a[i].time * a[i].count);
    }
    return res;
}
void output()
{
    fstream out("THUPHI .OUT", ios::out);
    out<<res;
    out.close();
}
int main()
{
    input();
    solve();
    res = dem();
    output();
    return 0;
}
