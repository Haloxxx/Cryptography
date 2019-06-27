#include "std_lib_facilities.hpp"

vector<int> t_dziel;

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


int power_modulo(int a, int b, int c)
{
    string b_bin = to_bin(b);
    
    //cout<<"b_bin = "<<b_bin<<'\n';
    
    int base = int(pow(a,1))%c;
    
    int result = 1;
    
    vector<int> rems;
    
    rems.push_back(int(pow(a,1))%c);
    
    for(int i =0; i<b_bin.size()-1; ++i)
    {
        
        int rem = int(pow(rems[i],2))%c;
        
        rems.push_back(rem);
    }
    
    
    for(int i = 0; i<b_bin.size(); ++i)
    {
        if (b_bin[b_bin.size()-1-i]-'0'!=0)
        {
            result *= rems[i];
            result%=c;
        }
    }
    result%=c;

    return result;
}


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

/*
    while(x<((d+1)/2))
    {
        int y_2 = 0;
    
        y_2 = pow(x,2)-d;
    
        int y = sqrt(y_2);
        double y_2_sqrt = sqrt(y_2);
        double y_to_int = y;

        if(y_2>0 && y_2_sqrt==y_to_int)
        {
            result.result_1 = x+y;
            result.result_2 = x-y;

            return result;
        }
        else
        {
            ++x;
        }
    }*/

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

vector<int> dzielniki(int a)
{
    vector<int> krotnosci;
    vector<int> dzielniki;
    //dzielniki.push_back(2);

    /*int a =0;
    
    cout<<"a: ";
    cin>>a;*/
    
    //a = 78;
    //a = 5148;
    //a=39;
    //a = 25740;
    //a = 390;
    //a = 1170;
    //a = 5850;
    //a= 6318;
    //a=3822;
    //a=9438;

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
    //cout<<"\nk = "<<k<<'\n';

    //cout<<"d = "<<d<<'\n';

    rec_res result;
    rec_res result1, result2;



    if(d==1)
    {
        if(a==1)
        {
            cout<<"a = 1\n";
            return dzielniki;
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
    
    //cout<<"r1 = "<<result.result_1<<'\n';
    //cout<<"r2 = "<<result.result_2<<'\n';

    rec_res oracle1 = recursive(result.result_1);
    rec_res s1 = recursive(result.result_1);

    rec_res oracle3 = recursive(result.result_1);
    rec_res s3 = recursive(result.result_1);
    
    /*oracle1 = result;
    s1 = result;
    oracle3 = result;
    s3 = result;*/

    int c1 = 0, c3 = 0;

    while(oracle1.result_1!=-1 && oracle3.result_1!=-1)
    {
        int copy = oracle1.result_1;
        oracle1 = recursive(oracle1.result_1);
        bool flag1 = 0;

        //cout<<"o1 = "<<oracle1.result_1<<" "<<oracle1.result_2<<'\n';

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

        else if (flag3 == 0 /*&& war1==0*/)
        {
            //bool war1 =0;
            //if(c1==c3 && c1==0) war1 = 1;
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

        //cout<<"o1 = "<<oracle2.result_1<<" "<<oracle2.result_2<<'\n';

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
    }}}

/*
    cout<<"dzielniki:\n";
    for(int i =0; i<dzielniki.size(); ++i)
        cout<<dzielniki[i]<<" ";

    cout<<'\n';
*/
    //cout<<"c1 = "<<c1<<" c3 = "<<c3<<'\n';


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


    /*cout<<"dzielniki:\n";
    for(int i =0; i<dzielniki.size(); ++i)
        cout<<dzielniki[i]<<" ";
*/
    //cout<<"\nk = "<<k<<'\n';
    if(dzielniki[0]==2) ilek[0]=k;

    vector<int> sorted = bubblesort(dzielniki);

    /*cout<<"\nkrotnosci:\n";
    for(int i =0; i<ilek.size(); ++i)
        cout<<ilek[i]<<" ";
*/

    int final_size = 0;
    for(int i =0; i<ilek.size(); ++i)
    {
        if(ilek[i]!=0) ++final_size;
    }

    vector<int> final_vector(final_size);
    //cout<<"finalsize = "<<final_size<<'\n';
    
    int j=0;
    for(int i=0; i<final_size;++i)
    {
        final_vector[i]=sorted[j];

        ++j;

        while(j<final_size && sorted[j]==sorted[j-1]) ++j;

        if(sorted[i]==2) j=1;
    }

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

    /*cout<<"\ndzielniki:\n";
    for(int i =0; i<sorted.size(); ++i)
        cout<<sorted[i]<<" ";
*/
    /*cout<<"\ndzielniki:\n";
    for(int i =0; i<final_vector.size(); ++i)
        cout<<final_vector[i]<<" ";
*/
    /*cout<<"\nkrotnosci:\n";
    for(int i =0; i<ilek.size(); ++i)
        cout<<ilek[i]<<" ";
*/
    /*cout<<"\nkrotnosci:\n";
    for(int i =0; i<lastkrotnosci.size(); ++i)
        cout<<lastkrotnosci[i]<<" ";

    cout<<'\n';*/

    return final_vector;
}


bool n_check(int n)
{
    ifstream ist {"plik.txt"};

    if(!ist) error("File error!");

    int size = 5000;

    vector<int> tab(size);
    int primal = 0;

    for(int i =0; i<size; ++i)
    {
        ist>>primal;
        tab[i]=primal;
    }

    //cout<<"dupa = "<<tab[3999]<<'\n';

    int xl = 0;
    int xr = size;
    int xm = 0;
    int test;
    int xp = 0;;

    xm=(xl+xr)/2;

    while(true)
    {
        if(tab[xm]==n) return true;

        if (tab[xm]<n)
            xl=xm;
        else xr=xm;

        xm=(xl+xr)/2;
        
        if (tab[xm]==true) return true;
        if (xm==xp) break;
        xp = xm;
    }

    return false;
}


bool r_check(int r, int n)
{
    vector<int> n_mniej_jeden = dzielniki(n-1);

    
    int step2 = 0;

    bool flag = 0;

   
    
    for(int i=0; i<n_mniej_jeden.size(); ++i)
    {
        int upper = (n-1)/n_mniej_jeden[i];
        step2 = power_modulo(r,upper,n);

        if (step2==1) return false;
    }

    return true;
}


int main()
{
     int n = 37813, r = 36410, k = 6739, j = 34310, t = 300;
    // wczytywanie n, r, k, j, t z klawiatury
    cout<<"n: ";
    cin>>n;
    cout<<"r: ";
    cin>>r;
    cout<<"k: ";
    cin>>k;
    cout<<"j: ";
    cin>>j;
    cout<<"t: ";
    cin>>t;

    
    if(n_check(n)==false) cout<<"n nie jest liczbą pierwszą!\n";
    else if(r<=1 || r>=n-1) cout<<"r nie mieści się w przedzial 1 < r < n-1!\n";
    else if(r_check(r, n)==false) cout<<"r nie jest pierwiastkiem pierwotnym!\n";
    else if(k<=1 || k>=n-1) cout<<"k nie mieści się w przedziale 1 < k < n-1!\n";
    else if(t>=n) cout<<"t nie moze być większe od n!\n";
    else
    {

    int a = power_modulo(r,k,n);

    cout<<"Klucz publiczny: ("<<n<<","<<r<<","<<a<<")\n";

    int c1 = power_modulo(r,j,n);
    int c2 = (t*power_modulo(a,j,n))%n;

    cout<<"Szyfrogram: ("<<c1<<','<<c2<<")\n";


    }
}