//#include "std_lib_facilities.hpp"
#include <vector>
#include "iostream"
#include <cmath>


using namespace std;

struct result
{
    int number_i;
    int number_j;
    int size;
};



result machinery(int bound, int n, int m)
{
    
    vector<int> set(bound);

    for(int a = 0; a<bound; ++a) set[a]=2+a;
    //for(int b = 0; b<set.size(); ++b) cout<<set[b]<<" ";
    //cout<<"\n\n";
    //cout<<"utworzono\n";

    int a = 0;
    
    while(set[a]<=sqrt(set[set.size()-1]))
    {
        for(int b = 0; b<set.size(); ++b)
        {
            if(b!=a)
            {
                if(set[b]%set[a]==0) set.erase(set.begin()+b);
            }
        }
        ++a;

        //if(a%10000) cout<<"krok\n";
    }

    result res;

    res.number_i = set[n];
    res.number_j = set[m];
    res.size = set.size();

    return res;
}


int bound_calcutation(int i)
{
    int res;

    if(i<=10) res=30;
    else if (i<=100) res=541;
    else if (i<=1000) res=7919;
    else if (i<=10000) res=104729;
    else if (i<=100000) res=1299709;
    //else if (i<=200000) res = 3899127;
    else if (i<=200000) res = 2100000;

    return res;
}

int main()
{
    int i = 0, j = 0;
    // wczytywanie i i j z klawiatury
    cout<<"i: ";
    cin>>i;
    cout<<"j: ";
    cin>>j;

    
    int bound_i = bound_calcutation(i);
    int bound_j = bound_calcutation(j);
    int bound = 0;

    if (bound_i>=bound_j) bound = bound_i;
    else bound = bound_j;
    //cout<<"bound = "<<bound<<'\n';

    result res = machinery(bound,i-1, j-1);

    cout<<res.number_i<<'\n';
    cout<<res.number_j<<'\n';
}