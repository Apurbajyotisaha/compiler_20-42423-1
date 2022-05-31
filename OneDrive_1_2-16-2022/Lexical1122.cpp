#include<bits/stdc++.h>
using namespace std;

string readFile(string f)
{

    ifstream infile;
    infile.open(f);

    string line;
    string s;
    while(getline(infile,line))
    {
        s+=line+'\n';
    }

    return s;
}



string removeComments(string codewithcoment)
{
    int n = codewithcoment.length();
    string res;

    // Flags to indicate that single line and multiple line comments
    // have started or not.
    bool s_cmt = false;
    bool m_cmt = false;


    // Traverse the given program
    for (int i=0; i<n; i++)
    {
        // If single line comment flag is on, then check for end of it
        if (s_cmt == true && codewithcoment[i] == '\n')
            s_cmt = false;

        // If multiple line comment is on, then check for end of it
        else if  (m_cmt == true && codewithcoment[i] == '*' && codewithcoment[i+1] == '/')
            m_cmt = false,  i++;

        // If this character is in a comment, ignore it
        else if (s_cmt || m_cmt)
            continue;

        // Check for beginning of comments and set the appropriate flags
        else if (codewithcoment[i] == '/' && codewithcoment[i+1] == '/')
            s_cmt = true, i++;
        else if (codewithcoment[i] == '/' && codewithcoment[i+1] == '*')
            m_cmt = true,  i++;

        // If current character is a non-comment character, append it to res
        else  res += codewithcoment[i];
    }
    return res;
}



int isKeyword(char buffer[]){
    int i, flag = 0;


 const vector<string> keywords{"auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union",
        "unsigned","void","volatile","while","using","include"};
    for(string keyword : keywords)
        if (keyword == buffer){
            flag = 1;
            break;
        }


    return flag;
}

int main()
{

string s1 =  readFile("in.cpp");

cout<<s1<<endl;

string ms = removeComments(s1);

cout<<ms<<endl;

    char ch, buffer[15],b[30], logical_op[] = "><";
    char math_op[]="+-*/=",numer[]=".0123456789",other[]=",;\(){}[]'':";


    int mark[1000]= {0};

    int i,j=0,kc=0,ic=0,lc=0,mc=0,nc=0,oc=0,aaa=0;

    vector < string > k;
    vector<char >id;
    vector<char>lo;
    vector<char>ma;
    vector<string>nu;
    vector<char>ot;



for(int p=0;p<ms.length();p++)
    {
        ch = ms[p];
        for(i = 0; i < 12; ++i)
        {
            if(ch == other[i])
            {
                int aa=ch;
                if(mark[aa]!=1)
                {
                    ot.push_back(ch);
                    mark[aa]=1;
                    ++oc;
                }
            }
        }

        for(i = 0; i < 5; ++i)
        {
            if(ch == math_op[i])
            {
                int aa=ch;
                if(mark[aa]!=1)
                {
                    ma.push_back(ch);
                    mark[aa]=1;
                    ++mc;
                }
            }
        }
        for(i = 0; i < 2; ++i)
        {
            if(ch == logical_op[i])
            {
                int aa=ch;
                if(mark[aa]!=1)
                {
                    lo.push_back(ch);
                    mark[aa]=1;
                    ++lc;
                }
            }

        }
        if(ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9' || ch=='.' ||ch == ' ' || ch == '\n' || ch == ';')
        {

            if(ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9' || ch=='.')b[aaa++]=ch;
            if((ch == ' ' || ch == '\n' || ch == ';') && (aaa != 0))
            {
                b[aaa] = '\0';
                aaa = 0;
                char arr[30];
                strcpy(arr,b);
                nu.push_back(arr);
                ++nc;

            }
        }


        if(isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n') && (j != 0))
        {
            buffer[j] = '\0';
            j = 0;

            if(isKeyword(buffer) == 1)
            {

                k.push_back(buffer);
                ++kc;
            }
            else
            {



                if(buffer[0]>=97 && buffer[0]<=122)
                {
                    if(mark[buffer[0]-'a']!=1)
                    {
                        id.push_back(buffer[0]);
                        ++ic;
                        mark[buffer[0]-'a']=1;
                    }

                }

            }

        }

    }

    printf("Keywords: ");

    for(int f=0; f<kc; ++f)
    {
        if(f==kc-1)
        {
            cout<<k[f]<<"\n";
        }
        else
        {
            cout<<k[f]<<", ";
        }
    }
    printf("Identifiers: ");
    for(int f=0; f<ic; ++f)
    {
        if(f==ic-1)
        {
            cout<<id[f]<<"\n";
        }
        else
        {
            cout<<id[f]<<", ";
        }
    }
    printf("Math Operators: ");
    for(int f=0; f<mc; ++f)
    {
        if(f==mc-1)
        {
            cout<<ma[f]<<"\n";
        }
        else
        {
            cout<<ma[f]<<", ";
        }
    }
    printf("Logical Operators: ");
    for(int f=0; f<lc; ++f)
    {
        if(f==lc-1)
        {
            cout<<lo[f]<<"\n";
        }
        else
        {
            cout<<lo[f]<<", ";
        }

    }
    printf("Numerical Values: ");
    for(int f=0; f<nc; ++f)
    {
        if(f==nc-1)
        {
            cout<<nu[f]<<"\n";
        }
        else
        {
            cout<<nu[f]<<", ";
        }

    }
    printf("Others: ");
    for(int f=0; f<oc; ++f)
    {
        if(f==oc-1)
        {
            cout<<ot[f]<<"\n";
        }
        else
        {
            cout<<ot[f]<<" ";
        }

    }




    return 0;
}

