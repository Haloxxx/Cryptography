#include "std_lib_facilities.hpp"


struct eucli_res
{
    int NWD = 0;
    int x = 0;
    int y = 0;

};


eucli_res euclides(int a, int b)
{

    vector<int> r{a};
    r.push_back(b);
    vector<int> q;

    vector<int> x {1}, y;


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


    return result;
}



int main()
{
    int a = 1920, b = 162;
    // wczytywanie a i b z klawiatury
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;


    eucli_res result = euclides(a,b);
    cout<<"NWD = "<<result.NWD<<" x = "<<result.x<<" y = "<<result.y<<"\n";

}