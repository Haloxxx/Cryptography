#include "std_lib_facilities.hpp"
#include <vector>
#include <cstdint>
#include <sstream>
#include <bitset>


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
    
    
    if (sReturn.length()!=8)
    {
        for(int o = 0; o<8-end;++o)
        {
            sReturn.append("0");
            cout<<"krok\n";
        }
    }
    return sReturn;
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
    string part1, part2, result;
    
    for(int i =0; i<4;++i) part1+=text[i];
    for(int i=4;i<8;i++) part2+=text[i];
    
    int dec1 = to_dec(part1), dec2 = to_dec(part2);
    
    //cout<<"dec1 = "<<dec1<<" dec2 = "<<dec2<<'\n';
    
    char p1, p2;
    
    p1=warun_do_hexa(dec1);
    p2 = warun_do_hexa(dec2);
    //cout<<"p1 = "<<p1<<" p2 = "<<p2<<'\n';
    
    result.push_back(p1);
    result.push_back(p2);
    
    return result;
    
}


//Permutations
string permutation (const string blocks, const string& perm)
{
    string result;
    string helper;
    
    helper = blocks;
    int p;
    
    for(int i = 0; i<blocks.length();++i)
    {
        p=perm[i]-'0';
        helper[p] = blocks[i];
    }
    
    return helper;
}


string pe10_na_8 (const string ten, const string& p10w8)
{
    string result;
    
    for(int i =2; i<10;++i) result+=ten[i];
    
    return permutation(result,p10w8);
    
}


string sbox1 (const string& four)
{
    int box [4][4];
    
    box[0][0]=1;
    box[0][1]=0;
    box[0][2]=3;
    box[0][3]=2;
    
    box[1][0]=3;
    box[1][1]=2;
    box[1][2]=1;
    box[1][3]=0;
    
    box[2][0]=0;
    box[2][1]=2;
    box[2][2]=1;
    box[2][3]=3;
    
    box[3][0]=3;
    box[3][1]=1;
    box[3][2]=3;
    box[3][3]=2;

    
    int row = 0, col = 0;
    
    if (four[0]=='1') row+=2;
    if (four[1]=='1') col+=2;
    if (four[2]=='1') col+=1;
    if (four[3]=='1') row+=1;

    
    string result;
    
    int val = 0;
    
    val = box[row][col];
    
    switch(val)
    {
        case 0:
            result="00";
            break;
        case 1:
            result="01";
            break;
        case 2:
            result = "10";
            break;
        case 3:
            result = "11";
            break;
        default:
            error("sth went wrong");
    }
    cout<<"Sbox1 = "<<val<<'\n';
    return result;
}

string sbox2 (const string& four)
    {
        int box [4][4];
    
        box[0][0]=0;
        box[0][1]=1;
        box[0][2]=2;
        box[0][3]=3;
    
        box[1][0]=2;
        box[1][1]=0;
        box[1][2]=1;
        box[1][3]=3;
    
        box[2][0]=3;
        box[2][1]=0;
        box[2][2]=1;
        box[2][3]=0;
    
        box[3][0]=2;
        box[3][1]=1;
        box[3][2]=0;
        box[3][3]=3;
    
    
        int row = 0, col = 0;
    
        if (four[0]=='1') row+=2;
        if (four[1]=='1') col+=2;
        if (four[2]=='1') col+=1;
        if (four[3]=='1') row+=1;
    
    
        string result;
    
        int val = 0;
    
        val = box[row][col];
    
        switch(val)
            {
                case 0:
                    result="00";
                    break;
                case 1:
                    result="01";
                    break;
                case 2:
                    result = "10";
                    break;
                case 3:
                    result = "11";
                    break;
                default:
                    error("sth went wrong");
            }
        cout<<"Sbox2 = "<<val<<'\n';
    return result;
}

string pe4na8(const string& four)
{
   const string p4w8 = "30121230";
    string result = "30121230";
    
    for(int i =0; i<8; ++i)
    {
        int u = p4w8[i]-'0';
        result[i]=four[u];
    }
    return result;
    
}


string ksorowanie(const string& text, const string& key)
{
    string result = text;
    
    for (int i =0; i<8; ++i)
    {
        if (text[i]==key[i]) result[i]='0';
        else result[i]='1';
    }
    
    return result;
}

string machinery(const string& text, const string round1)
{
    const string p4 = "3021";
    
    string part1, part2, part2_copy;
    
    for(int i =0; i<4;++i) part1+=text[i];
    for(int i=4;i<8;i++) part2+=text[i];
    
    
    //cout<<"part 1 = "<<part1<<" part2 = "<<part2<<'\n';
    
    part2_copy = part2;
    
    part2 = pe4na8(part2);
    
    //cout<<"part2 = "<<part2<<'\n';
    
    string after_xor = ksorowanie(part2, round1);
    
    //cout<<"after xor = "<<after_xor<<'\n';
    
    string next_part1, next_part2;
    
    for(int i =0; i<4;++i) next_part1+=after_xor[i];
    for(int i=4;i<8;i++) next_part2+=after_xor[i];

    //cout<<"next 1 = "<<next_part1<<" next 2 = "<<next_part2<<'\n';
    
    string s1,s2;
    
    s1 = sbox1(next_part1);
    s2 = sbox2(next_part2);
    
    //cout<<"s1 = "<<s1<<" s2 = "<<s2<<'\n';
    
    
    string s_sum;
    
    s_sum = s1 + s2;
    
    string after_p4;
    
    after_p4 = permutation(s_sum,p4);
    
    string almost_final;
    
    almost_final = ksorowanie(part1,after_p4);
    
    string result;
    
    result = almost_final + part2_copy;
    
    //cout<<"result = "<<result<<'\n';
    
    return result;
    
}



int main()
{
    const string key = "1100000011";
    const string perm0 = "30246175";
    const string perm_cross = "45670123";
    const string perm_inverse = "15203746";
    const string p10 = "6204193875";
    const string sl1 = "40123";
    const string p10w8 = "13502476";
    const string sl2 = "34012";
    
    
    
    vector<string> text;
    vector<string> binary;
    
    
    
    //for (string temp; cin>>temp; ) text.push_back(temp);
    string temp;
    cin>>temp;
    
    string prefix;
    prefix+=temp[0];
    prefix+=temp[1];
    
    bool pref = false;
    if (prefix=="0x") pref = true;
    
    
    for(int y = 0; y<temp.length(); )
    {
        if (pref==true)
        {
            y=2;
            pref = false;
        }
        
        
        string slowo = "";
        slowo += temp[y];
        if (y<temp.length())
        {
            ++y;
            slowo += temp[y];
        }
        ++y;
        
        text.push_back(slowo);
    }
    
    
    for (int i = 0; i<text.size();++i) cout<<text[i]<<" ";
    
    
    //for (int i = 0; i<text.size();++i) cout<<to_binary(text[i])<<'\n';
    for (int i = 0; i<text.size();++i) binary.push_back(to_binary(text[i]));
        
    
    
    
    ///////////////////////////////////////////////////////////////////
    /////////////////////Generacja kluczy/////////////////////////////
    //////////////////////////////////////////////////////////////////
    
    string kp_10 = permutation(key,p10);
    
    string k00, k01;
    
    for(int i = 0; i<5;++i) k00+=kp_10[i];
    for (int i = 5; i<10;++i) k01+=kp_10[i];
    
    string sk00, sk01;
    
    sk00 = permutation(k00,sl1);
    sk01 = permutation(k01,sl1);
    
    string sl_sum;
    
    sl_sum = sk00+sk01;
    
    string round1;
    round1 = pe10_na_8(sl_sum,p10w8);
    cout<<"round1 = "<<round1<<'\n';
    
    string sl20 = permutation(sk00,sl2);
    string sl21 = permutation(sk01,sl2);
    
    
    string sl_sum2;
    sl_sum2 = sl20+sl21;
    
    string round2;
    round2 = pe10_na_8(sl_sum2,p10w8);
    
    cout<<"round2 = "<<round2<<'\n';
    
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////
    
    string output;
    
    ////////
    for(int b = 0; b<binary.size(); ++b)
    ///////
    {
    
    string word = permutation(binary[b],perm0);
    
    string text_m;
    text_m = machinery(word,round1);
    
    //cout<<"po pierwszej rundzie = 0b"<<text_m<<'\n';
    cout<<"po pierwszej rundzie = 0x"<<to_hex(text_m)<<'\n';
    
    
    string copy = "0000";
    for(int i = 0; i<4;++i) copy[i]=text_m[i];
    for(int i = 0; i<4;++i) text_m[i]=text_m[i+4];
    for(int i = 4; i<8;++i) text_m[i]=copy[i-4];
    
    //cout<<"copy = "<<copy<<'\n';
    
    cout<<"\n\n\n\n\n";
    string text_f = machinery(text_m,round2);
    //cout<<"po drugiej rundzie = 0b"<<text_f<<'\n';
    cout<<"po drugiej rundzie = 0x"<<to_hex(text_f)<<'\n';
    
    string shifrogram;
    shifrogram = permutation(text_f,perm_inverse);
    
        output+=to_hex(shifrogram);
    }
        
    /*
    cout<<"szyfrogram = 0b"<<shifrogram<<'\n';
    cout<<"szyfrogram = 0x"<<to_hex(shifrogram)<<'\n';
    */
    
    
    cout<<"szyfrogram = 0x"<<output<<'\n';
    
    
    cout<<"\n\n\n\n";
    
    
    vector<string> text2;
    vector<string> binary2;
    
    
    for(int y = 0; y<output.length(); )
    {
        
        string slowo = "";
        slowo += output[y];
        if (y<output.length())
        {
            ++y;
            slowo += output[y];
        }
        ++y;
        
        text2.push_back(slowo);
    }
    
    
    for (int i = 0; i<text2.size();++i) binary2.push_back(to_binary(text2[i]));
    
    
    
    string decrypted;
    
    for(int b = 0; b<binary2.size(); ++b)
        ///////
    {
        
        string word = permutation(binary2[b],perm0);
        
        string text_m;
        text_m = machinery(word,round2);
        
        //cout<<"po pierwszej rundzie = 0b"<<text_m<<'\n';
        cout<<"po pierwszej rundzie = 0x"<<to_hex(text_m)<<'\n';
        
        
        string copy = "0000";
        for(int i = 0; i<4;++i) copy[i]=text_m[i];
        for(int i = 0; i<4;++i) text_m[i]=text_m[i+4];
        for(int i = 4; i<8;++i) text_m[i]=copy[i-4];
        
        //cout<<"copy = "<<copy<<'\n';
        
        cout<<"\n\n\n\n\n";
        string text_f = machinery(text_m,round1);
        //cout<<"po drugiej rundzie = 0b"<<text_f<<'\n';
        cout<<"po drugiej rundzie = 0x"<<to_hex(text_f)<<'\n';
        
        string shifrogram;
        shifrogram = permutation(text_f,perm_inverse);
        
        decrypted+=to_hex(shifrogram);
    }
    
    
    
    cout<<"\n\n\n\n";
    cout<<"///////////////////////////////\n";
    cout<<"szyfrogram: 0x"<<output<<'\n';
    cout<<"zdeszyfrowane: 0x"<<decrypted<<'\n';
    
    
    
    return 0;
}
