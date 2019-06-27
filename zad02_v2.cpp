#include "std_lib_facilities.hpp"

vector<int> t_dziel;


struct rec_res
{
    int result_1 = -1;
    int result_2 = -1;
    int y = -1;
};

struct s2_res
{
    int x;
    bool flag= 0;
};

struct l_res
{
    int res_1 = -1;
    int res_2 = -1;
};


s2_res step2(int d)
{
    s2_res result;
    int x = sqrt(d);
    double d_sqrt = sqrt(d);
    double d_to_int = x;
    
    
    if (d_sqrt!=d_to_int)
    {
        ++x;
        result.x=x;
        result.flag=0;
    }
    else
    {
        bool fl=1;
        result.x = x;
        result.flag=fl;
    }
    t_dziel.push_back(x);    

    return result;
}

l_res loop(int x, int d)

{
    l_res result;

    while(x<((d+1)/2))
        {
            int y_2 = 0;
    
            y_2 = pow(x,2)-d;
    
            int y = sqrt(y_2);
            double y_2_sqrt = sqrt(y_2);
            double y_to_int = y;

            if(y_2>0 && y_2_sqrt==y_to_int)
            {
                result.res_1 = x+y;
                result.res_2 = x-y;

                return result;
            }
            else
            {
                ++x;
            }
        }


}


rec_res recursive(int d)
{
    rec_res result;


    s2_res s2;
    s2 = step2(d);

    int x = s2.x;

    if(s2.flag==1)
    {
        result.result_1 = s2.x;
        result.result_2 = s2.x;

        t_dziel.push_back(s2.x);

        return result;
    }

    l_res l;
    l = loop(x, d);
    result.result_1 = l.res_1;
    result.result_2 = l.res_2;

    t_dziel.push_back(l.res_1);
    t_dziel.push_back(l.res_2);
    return result;



}


vector<int> bubblesort(vector<int> A)
{
    int n = A.size();

    do
    {
        for(int i =0; i<n-1;i++)
        {
            if (A[i]>A[i+1]) swap(A[i],A[i+1]);
        }
        n=n-1;
    } while(n>1);

    return A;
}

int main()
{
    vector<int> krotnosci;
    vector<int> dzielniki;
    

    int a =0;
    
    cout<<"a: ";
    cin>>a;
    
    

    int d = a;
    
    int k =0;
    
    while (!(d%2))
    {
        d/=2;
        ++k;
    }

    if(k>0)
    {
        dzielniki.push_back(2);
        krotnosci.push_back(k);
    }
    

    rec_res result;
    rec_res result1, result2;

    if(d==1)
    {
        if(a==1)
        {
            cout<<"a = 1\n";
            return 0;
        }
    } 
    else{
    result = recursive(d);
    
    if(a==1 || a==2) 
    {
        cout<<"v = "<<a<<'\n';
        dzielniki.push_back(a);
    }
    else{
    if(result.result_1==-1) dzielniki.push_back(d);

    else
    {
        
    
    

    if(recursive(result.result_1).result_1==-1) dzielniki.push_back(result.result_1);
    if(recursive(result.result_2).result_1==-1) dzielniki.push_back(result.result_2);


    rec_res oracle1 = recursive(result.result_1);
    rec_res s1 = recursive(result.result_1);

    rec_res oracle3 = recursive(result.result_1);
    rec_res s3 = recursive(result.result_1);
 

    int c1 = 0, c3 = 0;

    while(oracle1.result_1!=-1 && oracle3.result_1!=-1)
    {
        int copy = oracle1.result_1;
        oracle1 = recursive(oracle1.result_1);
        bool flag1 = 0;

   

        if(oracle1.result_1!=-1)
        {
            s1 = recursive(copy);
            ++c1;
        }
        else if (flag1 == 0)
        {
            dzielniki.push_back(s1.result_1);
            dzielniki.push_back(s1.result_2);
            flag1 = 1;
        }


        int copy3 = oracle3.result_2;
        oracle3 = recursive(oracle3.result_2);
        bool flag3 = 0;

        if(oracle3.result_2!=-1)
        {
            s3 = recursive(copy3);
            ++c3;
        }

        else if (flag3 == 0 )
        {
            
            if(c1==c3 && c1==0) c1=0;
            else{
            dzielniki.push_back(s3.result_1);
            dzielniki.push_back(s3.result_2);
            flag3 = 1;
            }
        }

    }

    rec_res oracle2 = recursive(result.result_2);
    rec_res s2 = recursive(result.result_2);

    rec_res oracle4 = recursive(result.result_2);
    rec_res s4 = recursive(result.result_2);

    int c2 = 0, c4 = 0;

    while(oracle2.result_1!=-1 && oracle4.result_1!=-1)
    {
        int copy = oracle2.result_1;
        oracle2 = recursive(oracle2.result_1);
        bool flag2 = 0;

        if(oracle2.result_1!=-1)
        {
            s2 = recursive(copy);
            ++c2;
        }
        else if (flag2 == 0)
        {
            
            dzielniki.push_back(s2.result_1);
            dzielniki.push_back(s2.result_2);
        }


        int copy4 = oracle4.result_2;
        oracle4 = recursive(oracle4.result_2);
        bool flag4 = 0;

        if(oracle4.result_2!=-1)
        {
            s4 = recursive(copy4);
            ++c4;
        }
        else if (flag4 == 0)
        {
            if(c2==c4 && c2==0) c2=0;
            else{
            dzielniki.push_back(s4.result_1);
            dzielniki.push_back(s4.result_2);
            flag4 = 1;}
        }

    }
    }
    }}

    int max = 0;
    for(int i =0; i<dzielniki.size(); ++i)
        if(dzielniki[i]>max) max=dzielniki[i];

    vector<int> ilek(max);

    for(int i =0; i<dzielniki.size(); ++i)
    {
        int helper;

        helper = recursive(dzielniki[i]).result_1;
        if(helper != -1) 
        {
        dzielniki[i]=helper;
        ++ilek[dzielniki[i]-1];
        }
    }

    for(int i =0; i<dzielniki.size(); ++i)
    {
        if(dzielniki[i]!=2)
            ++ilek[dzielniki[i]-1];
    }

    if(dzielniki[0]==2) ilek[0]=k;


    vector<int> sorted = bubblesort(dzielniki);


    int final_size = 0;
    for(int i =0; i<ilek.size(); ++i)
    {
        if(ilek[i]!=0) ++final_size;
    }

    vector<int> final_vector(final_size);
    


    int j=0;
   

    for(int i=0; i<final_size;++i)
    {
        final_vector[i]=sorted[j];

        ++j;

        while(j<final_size && sorted[j]==sorted[j-1]) ++j;

        if(sorted[i]==2) j=1;
    }


    cout<<"dzielniki_test:\n";
    for(int i =0; i<final_vector.size(); ++i)
        cout<<final_vector[i]<<" ";


    vector<int> lastkrotnosci(final_size);
    int u =0;
    for(int i =0; i<ilek.size(); ++i)
    {
        if(ilek[i]!=0) 
        {
            lastkrotnosci[u]=ilek[i];
            ++u;
        }
    }
    cout<<"\ndzielniki:\n";
    for(int i =0; i<final_vector.size(); ++i)
        cout<<final_vector[i]<<" ";



    cout<<"\nkrotnosci:\n";
    for(int i =0; i<lastkrotnosci.size(); ++i)
        cout<<lastkrotnosci[i]<<" ";

    cout<<'\n';
}
