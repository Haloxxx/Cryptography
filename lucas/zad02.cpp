#include "std_lib_facilities.hpp"

int test;



struct results
{
    int result_1;
    int result_2;
    
    
};

struct mega_res
{
    results _1res;
    results _2res;
    
    bool flag = 0;
};


results loop(int d)
{
    int x = sqrt(d);
    double d_sqrt = sqrt(d);
    double d_to_int = x;
    
    
    if (d_sqrt!=d_to_int)
    {
        ++x;
    }
    
    
    while(x<((d+1)/2))
    {
        int y_2 = 0;
    
        y_2 = pow(x,2)-d;

        cout<<"y^2 = "<<y_2<<'\n';
    
        int y = sqrt(y_2);
        double y_2_sqrt = sqrt(y_2);
        double y_to_int = y;
    
        results object;
    /*
        cout<<"y_2_sqrt = "<<y_2_sqrt<<'\n';
        cout<<"y_to_int = "<<y_to_int<<
*/
        if(y_2>0 && y_2_sqrt==y_to_int)
        {
            object.result_1 = x+y;
            object.result_2 = x-y;
            
            mega_res one_res;
            
            one_res._1res = object;
            one_res.flag = 0;
            
            //return one_res;
            /*cout<<"pierwszy warun\n";
            cout<<object.result_1<<'\n';
            cout<<object.result_2<<'\n';
            */
            return object;
        }
        else
        {
            ++x;

            results object2;
            results object3;
        
            int d_prim = x+y;
            int d_dwa_primy = x-y;
            //cout<<"wywolanie od d'\n";
            object2 = loop(d_prim);
            //cout<<"wywolanie od d''\n";
            object3 = loop(d_dwa_primy);
            
            mega_res bi_res;
            
            bi_res._1res = object2;
            bi_res._2res = object3;
            bi_res.flag = 1;
            /*
            cout<<"drugi warun\n";
            cout<<object2.result_1<<'\n';
            cout<<object2.result_2<<'\n';
            
            cout<<object3.result_1<<'\n';
            cout<<object3.result_2<<'\n';
            */
            
            return object2;
            
        }
    }
    
}



int main()
{
    vector<int> krotnosci;
    vector<int> dzielniki;
    dzielniki.push_back(2);

    int a =0;
    /*
    cout<<"a: ";
    cin>>a;
    */
    
    a = 78;
    
    int d = a;
    
    int k =0;
    
    while (!(d%2))
    {
        d/=2;
        ++k;
    }
    krotnosci.push_back(k);

    //cout<<"2^("<<k<<")*"<<d<<'\n';
    /*
    int x = sqrt(d);
    double d_sqrt = sqrt(d);
    double d_to_int = x;
    
    
    if (d_sqrt!=d_to_int)
    {
        ++x;
    }
    */
    //cout<<"x = "<<x<<" "<<'\n';
    
    cout<<"d = "<<d<<'\n';

    loop(d);
    
    
    
}
