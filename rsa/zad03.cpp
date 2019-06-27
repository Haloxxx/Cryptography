#include "iostream"
#include <vector>
#include <cmath>

struct result
{
    int number_i;
    int number_j;
    int size;
};



result machinery(int bound, int n, int m)
{
    
    std::vector<int> set(bound);

    for(int a = 0; a<bound; ++a) set[a]=2+a;
    //for(int b = 0; b<set.size(); ++b) cout<<set[b]<<" ";
    //cout<<"\n\n";
    

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
    else if (i<=200000) res = 3899127;

    return res;
}


struct eucli_res
{
    int NWD = 0;
    int x = 0;
    int y = 0;

    std::vector<int> x_v;
    std::vector<int> y_v;

};


eucli_res euclides(int a, int b)
{

    std::vector<int> r{a};
    r.push_back(b);
    std::vector<int> q;

    std::vector<int> x {1}, y;


    int j =1;

    while(r[j]!=0)
    {
        ++j;
        q.push_back(r[j-2]/r[j-1]);
        if(j==2) y.push_back(-q[0]);
        if(j==3)
        {
            x.push_back(-x[0]*q[1]);
            y.push_back(1-y[0]*q[1]);
        }
        r.push_back(r[j-2]-r[j-1]*q[j-2]);

        if(j>3)
        {
            x.push_back(x[j-4]-x[j-3]*q[j-2]);
            y.push_back(y[j-4]-y[j-3]*q[j-2]);
        }
    }
    
    eucli_res result;

    /*for(int i =0; i<x.size(); ++i)
    {
        cout<<x[i]<<" "<<y[i]<<'\n';
    }*/


    result.NWD = r[j-1];
    result.x = x[j-3];
    result.y = y[j-3];
    result.x_v = x;
    result.y_v = y;


    return result;
}



int main()
{

    //Generacja dwoch (duzych) liczb pierwszych p oraz q (sitem Eratostenesa)
    int i = 0, j = 0;
    // wczytywanie i i j z klawiatury
    std::cout<<"i: ";
    std::cin>>i;
    std::cout<<"j: ";
    std::cin>>j;

    int e = 0;
    std::cout<<"e: ";
    std::cin>>e;

    /*i = 237;
    j = 426;
    e = 1703;
*/
    
    int bound = 0;
    if(i>j) {bound = bound_calcutation(i);}
    else {bound = bound_calcutation(j);}
    result eratostenes = machinery(bound, i-1, j-1);

    int p = eratostenes.number_i;
    int q = eratostenes.number_j;
    


    //Wyznaczenie liczb n = p*q oraz m = (p-1)(q-1)
    int n = p*q;
    int m = (p-1)*(q-1);

    //Wyznaczenie liczby dodatniej d odwrotnej do e

    int d = 0;

    eucli_res x_and_y = euclides(e,m);
    if(x_and_y.x>0) {d = x_and_y.x;}
    else
    {
        int a = e, b = m;
        int x = x_and_y.x;
        int y = x_and_y.y;
        

        //std::cout<<"d = "<<(x+26*b)*a+(y-26*a)*b<<'\n';

        while(x<0)
        {
            x += m;
            y -= e;
        }

        d = x;
       
    }

    
    
    //Wypisanie kluczy
    std::cout<<"Klucz publiczny – ("<<n<<","<<e<<")\n";
    std::cout<<"Klucz prywatny – ("<<n<<","<<d<<")\n";


}