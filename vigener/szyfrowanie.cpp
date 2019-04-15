#include "std_lib_facilities.hpp"

int main()
{

    ifstream plain;
    ofstream encrypted;
    string key, line;
    int lent, lenk;

    /*string tet1, tet2;

    tet1 = "abc";
    tet2 = "bcd";


    cout<<'a'+'b'<<"\n";
    cout<<tet1[0]+tet2[0]<<"\n";*/

    cout<<"Prosze podac klucz szyfrujacy:\n";
    cin>>key;

    lenk = key.length();


    plain.open("tekst.txt");
    encrypted.open("szyfr.txt");

    if (plain.is_open())
    {
        while ( getline (plain,line) )
        {
            lent= line.length();

            for (int i = 0; i<lent;i++)
            {
                if (i==lent-1) line[i]=line[i];
                else
                    line[i]=char(((line[i]-'a'+key[i%3]-'a')%26)+'a');
                
            }
            encrypted << line;
        }

    }








    plain.close();
    encrypted.close();


    return 0;
}

