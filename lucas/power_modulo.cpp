#include "std_lib_facilities.hpp"

//uwzględnić a <=1
string to_bin(int a)
{
    char jedynka = '0';
    int power2 = 0;
    string result = "0";


    if(a%2) 
    {
        jedynka = '1';
        power2 = a-1;
    }
    else { power2 = a; }

    int helper = 2;

    while(power2>=helper)
    {
            helper *= 2;
            result += '0';
    }

    int i = 0;

    while(power2>1)
    {
        helper = 2;
        /*int*/ i = 1;
        
        while(power2>helper)
        {
            helper *= 2;
            i+=1;
        }
        if(power2<helper)
        {
            helper/=2;
            --i;
        }

        result[result.size()-1-i]='1';

        power2 -= helper;
    }


    result[result.size()-1] = jedynka;


    return result;
}


int main()
{
    int a = 0,b = 0,c = 0;
    
    
    cout<<"a: ";
    cin>>a;
    
    cout<<"b: ";
    cin>>b;
    
    cout<<"c: ";
    cin>>c;

    /*
    a = 4;
    b = 21;
    c = 7;
    */
    
    string b_bin = to_bin(b);
    
    //cout<<"b_bin = "<<b_bin<<'\n';
    
    int base = int(pow(a,1))%c;

    //cout<<"base = "<<base<<'\n';
    
    int result = 1;
    vector<int> rems;
    
    rems.push_back(int(pow(a,1))%c);
    
    for(int i =0; i<b_bin.size()-1; ++i)
    {
        
        int rem = int(pow(rems[i],2))%c;
        
        rems.push_back(rem);
    }
    
    //for(int i =0; i<rems.size(); ++i)
      //  cout<<rems[i]<<" ";
    
    //cout<<"\n\n\n";
    for(int i = 0; i<b_bin.size(); ++i)
    {
        if (b_bin[b_bin.size()-1-i]-'0'!=0)
        {
            result *= rems[i];
            result%=c;
        }
    }
    result%=c;
    
    cout<<"result = "<<result<<'\n';
    
}
