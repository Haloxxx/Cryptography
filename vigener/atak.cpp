//
//  main.cpp
//  vigener_atak
//
//  Created by Wojciech Lange on 25/02/2019.
//  Copyright © 2019 Wojciech Lange. All rights reserved.
//

#include "std_lib_facilities.hpp"
#include <vector>



ifstream encrypted;
//eofstream plain;
string line, line1;
double c_index;
vector<int> incidence(26);
int l = 2;
vector<double> indexes;
double indeks;
vector<char> column;
vector<vector<int>> i_columns;
vector<int> c_size;
vector<double> m_indexes;
double m_index;
int pomoc = 0;






int test;

int main()
{
    
    
    
    
    //plain.open("tekst.txt");
    encrypted.open("szyfr.txt");
    
    cout<<"Podaj dlugosc klucza: \n";
    
    cin>>l;
    
    
    if (encrypted.is_open())
    {
        
        while(!encrypted.eof())
        {
        getline(encrypted, line1);
        line+=line1;
        }
        
        
        /*////////////////////////////////////////////
         
         Wyznaczanie długości klucza
         
         */////////////////////////////////////////////
        
        
        
        for (int g = 0; g<l; ++g)
        {
            column.clear();
            indeks =0;
            
            //if (g==l-1) pomoc=1;
            
            for(int i =0; i<26; i++)
            {
                
                incidence[i]=0;
            }
            
        
            
            
            for (int i = g; i<line.length()-1;i+=l)
            {
                column.push_back(line[i]);
            }
        
        
        
            for (int i = 0;i<column.size();++i)
            {
                ++incidence[column[i]-97];
            }
        
            
        
                for (int i = 0;i<26;++i)
                {
                    
                    indeks += incidence[i]*(incidence[i]-1)/(double(column.size())*((double(column.size()-1))));
                
                }
        
                indexes.push_back(indeks);
                c_size.push_back(column.size());
                i_columns.push_back(incidence);
        }
        
        for (int u = 0; u<indexes.size(); ++u)
            {
                cout<<"\nindeks = "<<indexes[u]<<'\n';
            }
       
    
        
        /*////////////////////////////////////////////
         
         Wyznaczanie wzajemnych indeksów koincydencji
         
         */////////////////////////////////////////////
    
        
        for(int c = 0; c<l-1;++c)
        {
        
        for (int o = 0; o<l-1-c; ++o)
        {
            m_index = 0;
            for (int i=0; i<25; ++i)
            {
                m_index +=double(i_columns[c][i]*i_columns[c+o+1][i])/double(c_size[c]*c_size[c+o+1]);
            }
            cout<<"\nm_index = "<<m_index<<" between "<<c<<" and " <<c+o+1<<'\n';
        }
        }
        
    }
    
    
    
    //plain.close();
    encrypted.close();
    
    
    return 0;
}
