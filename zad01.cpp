#include "std_lib_facilities.hpp"

//uwzględnić a <=1
string to_bin(int a)
{
    //cout<<'\n';
    
    string result;
    int part_result = a;
    
    int remainder = 0;
    
    remainder = part_result%2;
    
    if(remainder) part_result-=1;
    
    
    int big = part_result;
    
    
    result+="00";
    
    int top = 2;
    
    while (big>top)
    {
        top*=2;
        result+='0';
    }
    
    
    int l_top = top;
    
    int i =0;
    
    while (big>1)
    {
        int top = 2;
        
        while (big>top)
        {
            top*=2;
        }
        
        
        if (big<=top)
        {
            if (i==0)
            {
                result.pop_back();
            }
          
            
            
            if(big<top) top/=2;
        }
        
        if (i!=0)
        {
            int j = 0;
            
            while((l_top/top)>2)
            {
                
            
                ++j;
                
                l_top/=2;
                
            }
            i+=j;
        }
        

        result[i]='1';
    
        big = big - top;
        
        l_top = top;
        
        ++i;
    
    }
    
    if (remainder) result[result.size()-1]='1';
        
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
    
    cout<<"b_bin = "<<b_bin<<'\n';
    
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
    
    for(int i =0; i<rems.size(); ++i)
        cout<<rems[i]<<" ";
    
    cout<<"\n\n\n";
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
