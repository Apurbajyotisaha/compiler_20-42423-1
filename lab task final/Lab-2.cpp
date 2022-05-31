#include <bits/stdc++.h>
using namespace std;
int main(){
ifstream infile;
infile.open("Lab-2.cpp");
//ofstream outfile;
//outfile.open("copy_in.cpp");
string line;
string allline;
while(!infile.eof()){
getline(infile,line);
//cout<<line<<endl;
allline+=line+"\n";
}
cout << allline;
//outfile<<allline;
infile.close();
//outfile.close();
return 0;
}
