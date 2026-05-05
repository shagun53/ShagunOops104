//q1
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("NUM.TXT");
    for(int i=1;i<=200;i++) fout<<i<<" ";
    fout.close();
    return 0;
}

//q2
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("NOTES.TXT");
    char ch;
    int count=0;
    while(fin.get(ch)) if(isalpha(ch)) count++;
    cout<<count;
    fin.close();
    return 0;
}

//q3
#include <iostream>
#include <fstream>
using namespace std;
class Student {
    int id;
    char name[20];
public:
    void input(){ cin>>id>>name; }
    void display(){ cout<<id<<" "<<name; }
};
int main()
{
    Student s;
    ofstream fout("student.dat",ios::binary);
    s.input();
    fout.write((char*)&s,sizeof(s));
    fout.close();
    ifstream fin("student.dat",ios::binary);
    fin.read((char*)&s,sizeof(s));
    s.display();
    fin.close();
    return 0;
}

//q4
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("NOTES.txt");
    ofstream fout("Copy.txt");
    char ch;
    while(fin.get(ch)) fout.put(ch);
    fin.close();
    fout.close();
    return 0;
}

//q5
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    char str[100];
    cin.getline(str,100);
    cout<<strlen(str)<<endl;
    ofstream fout("string.txt");
    fout<<str;
    fout.close();
    ifstream fin("string.txt");
    fin.getline(str,100);
    cout<<str;
    fin.close();
    return 0;
}

//q6(a)
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("az.txt");
    for(char ch='A';ch<='Z';ch++) fout<<ch;
    fout.close();
    ifstream fin("az.txt");
    fin.seekg(9);
    char ch;
    fin.get(ch);
    cout<<ch;
    fin.close();
    return 0;
}

//q6(b)
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream file("az.txt",ios::in|ios::out);
    file.seekp(4);
    file.put('Z');
    file.close();
    return 0;
}

//q6(c)
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("az.txt");
    fin.seekg(0,ios::end);
    cout<<fin.tellg();
    fin.close();
    return 0;
}

//q6(d)
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("az.txt");
    fin.seekg(-1,ios::end);
    char ch;
    fin.get(ch);
    cout<<ch;
    fin.close();
    return 0;
}

//q6(e)
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("data.txt");
    fin.seekg(10);
    cout<<fin.tellg()<<endl;
    char ch;
    while(fin.get(ch)) cout<<ch;
    fin.close();
    return 0;
}

//q6(f)
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream file("data.txt",ios::out|ios::in);
    string s="HelloWorld";
    for(int i=0;i<s.length();i++) {
        file.put(s[i]);
        cout<<file.tellp()<<endl;
    }
    file.seekp(5);
    file<<"C++";
    file.close();
    return 0;
}