#include "std_lib_facilities.hpp"

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
    int i = 0;
    cin>>i;
    cout<<to_bin(i)<<'\n';
}