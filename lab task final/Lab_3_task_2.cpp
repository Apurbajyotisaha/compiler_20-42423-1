
#include <bits/stdc++.h>
using namespace std;



string readFile(string f)// function to read from a file
{
ifstream infile;
infile.open("Task.cpp");



string line;
string allLine;



while(getline(infile,line)){



allLine+=line+"\n";// concatinate strings line by line
}
return allLine;



}




string removeComments(string prgm)
{
int n = prgm.length();
string res;



// Flags to indicate that single line and multiple line comments
// have started or not.
bool s_cmt = false;
bool m_cmt = false;




// Traverse the given program
for (int i=0; i<n; i++)
{
// If single line comment flag is on, then check for end of it
if (s_cmt == true && prgm[i] == '\n')
s_cmt = false;



// If multiple line comment is on, then check for end of it
else if (m_cmt == true && prgm[i] == '*' && prgm[i+1] == '/')
m_cmt = false, i++;



// If this character is in a comment, ignore it
else if (s_cmt || m_cmt)
continue;



// Check for beginning of comments and set the appropriate flags
else if (prgm[i] == '/' && prgm[i+1] == '/')
s_cmt = true, i++;
else if (prgm[i] == '/' && prgm[i+1] == '*')
m_cmt = true, i++;



// If current character is a non-comment character, append it to res
else res += prgm[i];
}
return res;
}
int countoperrator( string kk)
{
    int countoperator(string ff)
    {
        int c=0;
        int n=ff.length();
        for ()
    }
}


int main()
{ string s2= readFile("Task.cpp");
cout<<"The targeted file with comments.......>"<<endl;
cout<<s2<<endl;



cout<<"Comments Removed from the targeted file.......>"<<endl;
string commentRemoved = removeComments(s2);
cout<<commentRemoved<<endl;



return 0;
}
