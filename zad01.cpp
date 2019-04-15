#include "std_lib_facilities.hpp"
#include <cstdint>
/*
struct matrices
{
    vector<string> mat1;
    vector<string> mat2;
};

matrices sorting (string str1, string str2)
{
    vector<string> matrix1;
    vector<string> matrix2;
    
    for(int i =0; i<4; ++i)
    {
        string word;
        
        for (int j=0; j<4; ++j)
        {
            word+=str1[4*i+j];
        }
        //cout<<"word1 = "<<word<<'\n';
        matrix1.push_back(word);
    }
    
    for(int i =0; i<4; ++i)
    {
        string word;
        
        for (int j=0; j<4; ++j)
        {
            word+=str2[4*i+j];
        }
        //cout<<"word2 = "<<word<<'\n';
        matrix2.push_back(word);
    }
    
    
    return matrices{matrix1,matrix2};
}
*/


string to_binary(const string& text)
{
    
    string sReturn;
    bool flag = 0;
    
    for (int i =0; i < text.length (); ++i)
    {
        
        if (flag==0)
        {
            if (text[0]=='0' && text[1]=='x') i=2;
            flag=1;
        }
        
        switch (text[i])
        {
            case '0': sReturn.append ("0000"); break;
            case '1': sReturn.append ("0001"); break;
            case '2': sReturn.append ("0010"); break;
            case '3': sReturn.append ("0011"); break;
            case '4': sReturn.append ("0100"); break;
            case '5': sReturn.append ("0101"); break;
            case '6': sReturn.append ("0110"); break;
            case '7': sReturn.append ("0111"); break;
            case '8': sReturn.append ("1000"); break;
            case '9': sReturn.append ("1001"); break;
            case 'a': sReturn.append ("1010"); break;
            case 'b': sReturn.append ("1011"); break;
            case 'c': sReturn.append ("1100"); break;
            case 'd': sReturn.append ("1101"); break;
            case 'e': sReturn.append ("1110"); break;
            case 'f': sReturn.append ("1111"); break;
        }
        
    }
    
    
    int end = sReturn.length();
    
    
    if (sReturn.length()!=4)
    {
        for(int o = 0; o<4-end;++o)
        {
            sReturn.append("0");
            cout<<"krok\n";
        }
    }
    return sReturn;
}


string rewriting(string text)
{
    
    //cout<<"text = "<<text<<'\n';
    
    string result;
    int mark = -5;
    
    
    for (int i =0; i<text.size(); ++i)
    {
        if(text[i]!='0')
        {
            mark = i;
            break;
        }
    }
    
    
    if (mark!=-5)
    {
        for(int k = mark; k<text.size(); ++k) result += text[k];
    }
    
    //cout<<"result = "<<result<<'\n';
    
    cout<<"wywolanie!\n";
    return result;
}


string m_mod2(string str1, string str2)
{
    string result;
    for (int i =0; i<(str1.size()+str2.size()-1);++i) result.push_back('0');
    
    for (int i =0; i <str1.size(); ++i)
    {
        for (int j =0; j<str2.size(); ++j)
        {
            result[i+j]+=((str1[i]-'0')*(str2[j]-'0')+'0')%2;
        }
        //cout<<"m_mod2 = "<<result<<'\n';
    }
    
    
    for (int i =0; i <result.size(); ++i) result[i]=(result[i]-'0')%2+'0';
    
    if (result[0]=='0') result = rewriting(result);
   
    /*if (result.size()>(str1.size()+str2.size()))
        for (int i =0; i<result.size()-(str1.size()+str2.size());++i) result.pop_back();
    */
    return result;
}


string p_mod2(string str1, string str2)
{
    string result;
    
    if (str1>str2) result = str1;
    else result = str2;
    
    for (int i =0; i <str1.size(); ++i) ///zmiana 03.04 13:30 str1.size()
    {
        result[i]=(str1[i]+str2[i]-'0');
    }
    
    for (int i =0; i <result.size(); ++i) result[i]=(result[i]-'0')%2+'0';
    
    if (result[0]=='0') result = rewriting(result);
    
    return result;
}


string multiplication(string str1, string str2)
{
    string result;
    
    const string red_pol = "10011";
    
    string helper = "0000000";
    string minus;
    string poli = m_mod2(str1, str2);
    bool flag = false;
    
    
    
    
    for (int i = 0; i<poli.size(); ++i) minus+='0';
    
    
    if (poli.size()<red_pol.size()) result = poli;
    
    else
    {
        int counter = 0;
        while(poli.size()>=red_pol.size()/*counter<2*/)
        {
            
            helper[helper.size()-(poli.size()-red_pol.size())-1]='1';
            if (helper[0]=='0') helper = rewriting(helper);
            //cout<<"helper bflag = "<<helper<<'\n';
            if (flag!=false)
            {
                string helper2;
                for(int i =1; i <helper.size(); ++i)
                {
                    helper2+=helper[i];
                }
                helper = helper2;
            }
            
            
            minus = m_mod2(helper,red_pol);
            poli = p_mod2(poli,minus);
            
            ++counter;
            flag = true;
            /*cout<<"minus = "<<minus<<'\n';
            cout<<"poli = "<<poli<<" "<<poli.size()<<'\n';
            cout<<"helper = "<<helper<<'\n';*/
        }
        //cout<<"minus = "<<minus<<'\n';
        result = poli;
    }
    
    int mimi = 4 - result.size();
    
    if (result.size()<4)
    {
        string uuu = "0000";
        
        for(int i = 4 - result.size(); i <4; ++i)
        {
           uuu[i]=result[i-mimi];
        }
        result = uuu;
    }
    cout<<"res = "<<result<<'\n';
    return result;
}

string SBox(string text, const vector<string>& s1, const vector<string>& s2)
{
    int pos=-5;
    
    for (int i =0; i<s1.size(); ++i)
        if (s1[i]==text) pos=i;
    
    return s2[pos];
}

int to_dec(const string& text)
{
    int result = 0;
    
    for(int i =0; i<4;++i)
    {
        if (text[i]=='1')
        {
            result+=pow(2,3-i);
        }
    }
    return result;
    
}

char warun_do_hexa(int dec)
{
    char result = 0;
    if (dec>=0 && dec<=9) result = dec + '0';
    else
    {
        dec-=10;
        switch(dec)
        {
            case 0:
                result = 'a';
                break;
            case 1:
                result = 'b';
                break;
            case 2:
                result = 'c';
                break;
            case 3:
                result = 'd';
                break;
            case 4:
                result = 'e';
                break;
            case 5:
                result = 'f';
                break;
            default:
                error("Something went wrong!");
        }
    }
    
    return result;
}

string to_hex(const string& text)
{
    string part1, result;
    
    part1=text;
    
    int dec1 = to_dec(part1);
    
    //cout<<"dec1 = "<<dec1<<" dec2 = "<<dec2<<'\n';
    
    char p1;
    
    p1=warun_do_hexa(dec1);
    //cout<<"p1 = "<<p1<<" p2 = "<<p2<<'\n';
    
    result.push_back(p1);
    
    return result;
    
}


int main()
{
    
    //SBoxE
    vector<string> s1 = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
    vector<string> s2 = {"1110","0100","1101","0001","0010","1111","1011","1000","0011","1010","0110","1100","0101","1001","0000","0111"};
    
    
    //SBoxD
    vector<string> s3 = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
    
    vector<string> s4 = {"1110","0011","0100","1000","0001","1100","1010","1111","0111","1101","1001","0110","1011","0010","0000","0101"};
    
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    //cout<<p_mod2(multiplication("0011","0011"),multiplication("0010","1111"))<<'\n';
    cout<<multiplication("0011","0000")<<'\n';
    /*cout<<multiplication("0010","0001")<<'\n';*/
    
    
    string text1, text2;
    
    cin>>text1;
    cin>>text2;
    
    string prefix1;
    prefix1+=text1[0];
    prefix1+=text2[1];
    
    bool pref = false;
    if (prefix1=="0x") pref = true;
    
    string prefix2;
    prefix2+=text2[0];
    prefix2+=text2[1];
    
    bool pref2 = false;
    if (prefix2=="0x") pref2 = true;
    
    
    if(pref == true)
    {
        string text_h1;
        for(int i =2; i <text1.size(); ++i)
        {
            text_h1+=text1[i];
        }
        text1 = text_h1;
    }
    
    if(pref2 == true)
    {
        string text_h2;
        for(int i =2; i <text2.size(); ++i)
        {
            text_h2+=text2[i];
        }
        text2 = text_h2;
    }
    
    //cout<<"text1 = "<<text1<<" text 2 = "<<text2<<'\n';
    
    string val1, val2;
    
    val1 = to_binary(text1);
    val2 = to_binary(text2);
    
    string multi = multiplication(val1,val2);
    
    cout<<"multiplication = "<</*to_hex(*/multi/*)*/<<'\n';
    
    string s = SBox(multi,s1,s2);
    cout<<"SboxE = 0x"<<to_hex(s)<<'\n';
    
    string m = SBox(s,s3,s4);
    cout<<"SboxD = 0x"<<to_hex(m)<<'\n';
    
    //cout<<"addi = "<<p_mod2("100101","100110")<<'\n';
    //cout<<"multi = "<<m_mod2("100","10011")<<'\n';
    
}
