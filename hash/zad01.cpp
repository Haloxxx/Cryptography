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

    return sorted;
}


bool p_check(int n)
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

bool g_check(int g, int q, int p)
{
    if(power_modulo(g,q,p)!=1) return false;
    

    for(int i = 2; i<q; ++i)
    {
        if(power_modulo(g,i,p)==1) return false;
    }

    return true;
}

bool input_check(int p, int g, int k, int r, int q)
{
    //bool flag = 1;

    if(p_check(p)==0) { cout<<"p nie jest liczbą pierwszą!\n"; return false;}
    if(g_check(g, q, p)==0) { cout<<"g nie spełnia warunkow!\n"; return false;}
    if(k>=q) { cout<<"k<q nie zachodzi!\n";   return false;}
    if(r>=q) { cout<<"r<q nie zachodzi!\n"; return false; }

    return true;
}


int jha(const string m, int p, int q)
{
    char znak;
    int sp = 0;
    int n1 = 0;
    int n2 = 0;

    for(int i =0; i<m.length(); ++i)
    {
        if(m[i]==32) sp++;
        else if ((m[i]>='a' && m[i]<='z')||(m[i]>='A' && m[i]<='Z'))
        {
         
        switch(m[i])
        {
         case 32: ++sp; break;
         case 'a':
         case 'e':
         case 'i':
         case 'u':
         case 'o':
         case 'A':
         case 'E':
         case 'I':
         case 'U':
         case 'O': ++n1; break; 
        default : ++n2;
        };

        }

    }
    //cout<<"n1 = "<<n1<<" n2 = "<<n2<<" sp = "<<sp<<'\n';

    int upper = 7*n1-3*n2+sp*sp;

    //cout<<"q = "<<q<<" upper = "<<upper<<" p = "<<p<<'\n';

    int i =1;

    if(upper<0)
    {
        
        while(true)
        {
            if((i*q)%p==1) {upper *= -1; q = i; break; } 
            //cout<<"krok\n";
            ++i;
        }
    }
    //cout<<"i = "<<i<<'\n';

    //cout<<"upper2 = "<<upper<<'\n';

    return power_modulo(q,upper,p);

}




int main()
{
    int p = 8831, g = 6275, k = 700, r = 500;
    // wczytywanie p, g, k, r z klawiatury
    cout<<"p: ";
    cin>>p;
    cout<<"g: ";
    cin>>g;
    cout<<"k: ";
    cin>>k;
    cout<<"r: ";
    cin>>r;

    ifstream text {"tekst_dlugi.txt"};

    if(!text) error("File error!");

    string m, part;

    //text>>m;

    while(!text.eof())
    {
        getline(text, part);
        m+=part;
    }
    //cout<<"m = "<<m<<'\n';


    int q =0;

    vector<int> qi = dzielniki(p-1);

    for(int i = 0; i<qi.size(); ++i)
    {
        //cout<<"q[i] = "<<qi[i]<<'\n';
        if(q<=qi[i]) q=qi[i];
    } 

    //cout<<"q = "<<q<<'\n';

    if(input_check(p,g,k,r,q)==false) return 1;

    int jeha = jha(m,p,q);
    cout<<"JHA = "<<jeha<<'\n';


    int gk = power_modulo(g,k,p);

    cout<<"PRK = ("<<gk<<","<<g<<","<<p<<","<<q<<")\n";

    int x = gk % q;

    int r1 = 0;

    int i =1;

    while(true)
    {
        if((i*r)%q==1) {r1 = i; break; } 
        //cout<<"krok\n";
        ++i;
    }

    //cout<<"r = "<<r<<" r1 = "<<r1<<'\n';

    int y = (r1*(jeha + k*x))%q;

    cout<<"s = ("<<x<<','<<y<<")\n";

}