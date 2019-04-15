#include "std_lib_facilities.hpp"

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
    
    
    if (sReturn.length()%4)
    {
        for(int o = 0; o<sReturn.length()%4;++o)
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
    
    //cout<<"wywolanie!\n";
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
    
    //cout<<"str1 = "<<str1<<" str2 = "<<str2<<'\n';
    
    
    for (int i =0; i <str1.size(); ++i)
    {
        result[i]=(str1[i]+str2[i]-'0');
    }
    
    //cout<<"result = "<<result<<'\n';
    
    for (int i =0; i <result.size(); ++i) result[i]=(result[i]-'0')%2+'0';
    
    //cout<<"result = "<<result<<'\n';
    
    
    //if (result[0]=='0') result = rewriting(result);
    
    return result;
}


string p_mod2_v1(string str1, string str2)
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
            poli = p_mod2_v1(poli,minus);
            
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
    //cout<<"res = "<<result<<'\n';
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
    string part1, part2, part3, part4, result;
    
    for(int i =0; i<4;++i) part1+=text[i];
    for(int i=4;i<8;i++) part2+=text[i];
    for(int i=8;i<12;i++) part3+=text[i];
    for(int i=12;i<16;i++) part4+=text[i];
    
    int dec1 = to_dec(part1), dec2 = to_dec(part2);
    int dec3 = to_dec(part3), dec4 = to_dec(part4);
    
    //cout<<"dec1 = "<<dec1<<" dec2 = "<<dec2<<'\n';
    
    char p1, p2, p3, p4;
    
    p1=warun_do_hexa(dec1);
    p2 = warun_do_hexa(dec2);
    p3=warun_do_hexa(dec3);
    p4 = warun_do_hexa(dec4);
    
    //cout<<"p1 = "<<p1<<" p2 = "<<p2<<'\n';
    
    result.push_back(p1);
    result.push_back(p2);
    result.push_back(p3);
    result.push_back(p4);
    
    return result;
    
}


string gen1(const string kp)
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
    
    
    
    
    matrices keys = sorting(kp, "0000000000000000");
    
    //cout<<"part1 = "<<keys.mat1[0]<<'\n';
    string sebix = SBox((keys.mat1[3]),s1,s2);
    keys.mat2[0] = p_mod2(keys.mat1[0], sebix);
    keys.mat2[0] = p_mod2(keys.mat2[0],"0001");
    
    keys.mat2[2] = p_mod2(keys.mat1[2],keys.mat2[0]);
    //cout<<"part1 = "<<keys.mat2[0]<<'\n';
    keys.mat2[1] = p_mod2(keys.mat1[1],keys.mat2[2]);
    
    keys.mat2[3] = p_mod2(keys.mat1[3],keys.mat2[1]);
    
    
    string result;
    for(int i =0; i<4; ++i)
        result+=keys.mat2[i];
        
    cout<<"k1 = 0x"<<to_hex(result)<<'\n';
    return result;
}


string gen2(const string k1)
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
    
    
    
    
    matrices keys = sorting(k1, "0000000000000000");
    
    //cout<<"part1 = "<<keys.mat1[0]<<'\n';
    string sebix = SBox((keys.mat1[3]),s1,s2);
    keys.mat2[0] = p_mod2(keys.mat1[0], sebix);
    keys.mat2[0] = p_mod2(keys.mat2[0],"0010");
    
    keys.mat2[2] = p_mod2(keys.mat1[2],keys.mat2[0]);
    //cout<<"part1 = "<<keys.mat2[0]<<'\n';
    keys.mat2[1] = p_mod2(keys.mat1[1],keys.mat2[2]);
    
    keys.mat2[3] = p_mod2(keys.mat1[3],keys.mat2[1]);
    
    
    string result;
    for(int i =0; i<4; ++i)
        result+=keys.mat2[i];
    
    cout<<"k2 = 0x"<<to_hex(result)<<'\n';
    return result;
}

string consolidation(vector<string> mat)
{
    string result;
    for(int i =0; i<mat.size(); ++i)
        result+=mat[i];
    
    return result;
        
}


string febox(const string& text)
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
    
    
    matrices process = sorting(text,"0000000000000000");
    
    process.mat1[0] = SBox(process.mat1[0],s1,s2);
    process.mat1[1] = SBox(process.mat1[1],s1,s2);
    process.mat1[2] = SBox(process.mat1[2],s1,s2);
    process.mat1[3] = SBox(process.mat1[3],s1,s2);
    
    string result = consolidation(process.mat1);
    
    return result;
    
}


string fdbox(const string& text)
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
    
    
    matrices process = sorting(text,"0000000000000000");
    
    process.mat1[0] = SBox(process.mat1[0],s3,s4);
    process.mat1[1] = SBox(process.mat1[1],s3,s4);
    process.mat1[2] = SBox(process.mat1[2],s3,s4);
    process.mat1[3] = SBox(process.mat1[3],s3,s4);
    
    string result = consolidation(process.mat1);
    
    return result;
    
}


string zetka(const string& text)
{
    matrices process = sorting(text,"0000000000000000");
    
    string copy = process.mat1[2];
    
    process.mat1[2] = process.mat1[3];
    process.mat1[3] = copy;
    
    string result = consolidation(process.mat1);
    
    return result;
}


string machinery(const string& text)
{
    matrices process = sorting("0011001000100011",text);
    vector<string> pre_result;
    /*
    for(int i = 0; i<4; ++i)
    {
        pre_result.push_back(multiplication(process.mat1[i],process.mat2[i]));
    }
    */
    pre_result.push_back(p_mod2(multiplication(process.mat1[0],process.mat2[0]),multiplication(process.mat1[1],process.mat2[2])));
    pre_result.push_back(p_mod2(multiplication(process.mat1[0],process.mat2[1]),multiplication(process.mat1[1],process.mat2[3])));
    pre_result.push_back(p_mod2(multiplication(process.mat1[2],process.mat2[0]),multiplication(process.mat1[3],process.mat2[2])));
    pre_result.push_back(p_mod2(multiplication(process.mat1[2],process.mat2[1]),multiplication(process.mat1[3],process.mat2[3])));
    
    
    
    string result;
    result = consolidation(pre_result);
    
    return result;
    
}



int main()
{
    string key;
    string text;
    
    
    cin>>key;
    cin>>text;
    /*
    key = "0xfff";
    text = "0xfff";
    */
    /////////////////////////////////////////////////////////////////////
    /////////////////////////////////////Prefix1/////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    
    string prefix;
    prefix+=key[0];
    prefix+=key[1];
    
    bool pref = false;
    if (prefix=="0x") pref = true;
    
    if(pref == true)
    {
        string key_h;
        for(int i =2; i <key.size(); ++i)
        {
            key_h+=key[i];
        }
        key = key_h;
    }
    
    //////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////Prefix2/////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    
    string prefix2;
    prefix2+=text[0];
    prefix2+=text[1];
    
    bool pref2 = false;
    if (prefix2=="0x") pref2 = true;
    
    if(pref2 == true)
    {
        string text_h;
        for(int i =2; i <text.size(); ++i)
        {
            text_h+=text[i];
        }
        text = text_h;
    }
    
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    
    
    key = to_binary(key);
    int end = key.length();
    
    if (key.length()<16)
        for(int i =0; i<16-end; ++i) key+='0';
    
    
    string k1 = gen1(key);
    string k2 = gen2(k1);
    
    
    text = to_binary(text);
    int end2 = text.length();

    
    if (text.length()%16)
    {
        for(int i =0; i<16-end2%16; ++i)
        {
            text+='0';
        }
    }
    
    vector<string> v_text;
    //v_text.push_back(text);
    
    
    for(int i =0; i<(text.length()/16); ++i)
    {
        string text1;
        
        for(int j = 0; j<16; ++j)
        {
            text1+=text[16*i+j];
        }
        
        v_text.push_back(text1);
    
        
    }
    

    
    for(int i = 0; i<v_text.size(); ++i)
    {
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK1/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = p_mod2(key,v_text[i]);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK2/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = febox(v_text[i]);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK3/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = zetka(v_text[i]);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK4/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = machinery(v_text[i]);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK5/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = p_mod2(v_text[i],k1);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK6////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = febox(v_text[i]);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK7////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = zetka(v_text[i]);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK8////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = p_mod2(v_text[i],k2);
        
        //roboczy.push_back(v_text[i]);
    }
    string szyfrogram;
    
    //for(int i = 0; i<v_text.size(); ++i) cout<<"v_text po = "<<v_text[i]<<'\n';
    
    for(int i = 0; i<v_text.size(); ++i) szyfrogram+=to_hex(v_text[i]);
    //for(int i = 0; i<v_text.size(); ++i) szyfrogram+=v_text[i];
    //cout<<"szyfrogram = 0x"<<to_hex(szyfrogram)<<'\n';
    cout<<"szyfrogram = 0x"<<szyfrogram<<'\n';
    
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KONIEC SZYFROWANIA////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    
    
    
    
    
    int i = 0;
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////DESZYFROWANIE////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    
    for(int i = 0; i<v_text.size(); ++i)
    {
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK1/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = p_mod2(v_text[i],k2);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK2/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = zetka(v_text[i]);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK3/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = fdbox(v_text[i]);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK4/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = p_mod2(v_text[i],k1);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK5/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = machinery(v_text[i]);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK6/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = zetka(v_text[i]);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK7/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = fdbox(v_text[i]);
    
    //////////////////////////////////////////////////////////////////
    /////////////////////////////////KROK8/////////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    v_text[i] = p_mod2(key,v_text[i]);
        
    }
    string plain;
    for(int i = 0; i<v_text.size(); ++i) plain+=to_hex(v_text[i]);
    cout<<"odszyfrowany tekst = 0x"<<plain<<'\n';
    
    
}
