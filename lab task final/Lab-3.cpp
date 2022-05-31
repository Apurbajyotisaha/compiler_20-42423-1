#include<bits/stdc++.h>
using namespace std;


string readFile(string f)// function to read from a file
{
        ifstream infile;
        infile.open("Task.cpp");

        string line;
        string s;

    while(getline(infile,line))
    {

    s+=line+"\n";// concatinate strings line by line

    }
    return s;



    }



    int main()
    {
    string s1 = readFile("Task.cpp"); //call & enter targeted file name in this function
    cout<<s1<<endl;



    return 0;
}
