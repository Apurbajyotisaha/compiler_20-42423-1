#include<bits/stdc++.h>
using namespace std;



bool isID(const string &str)
{
    if(isdigit(str[0]))
        return false;
    int counter = 0;
    if(str[0] == '_')
        counter++;

    for(; counter < str.size(); counter++)
        if(!(isalnum(str[counter])))
            return false;

    return true;
}

bool isComment(const string &str)
{
    return str == "/*" || str == "//";
}

bool isDigit(const string &str)
{
    return all_of(str.begin(), str.end(), ::isdigit);
}

bool isString(const string &str)
{
    return str[0] == '"' && str[str.size()-1] == '"';
}

bool isBool(const string &str)
{
    return str == "true" || str == "false";
}

bool isLiteral(const string &str)
{
    return isDigit(str) || isString(str) || isBool(str);
}

bool isKeyword(const string &str)
{
    const vector<string> keywords{"auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union",
        "unsigned","void","volatile","while"};
    for(const auto& keyword : keywords)
        if (keyword == str)
            return true;

    return false;
}

bool isStatement(const string &str)
{
    const vector<string> statements{"for", "while"};
    for(const auto& statement : statements)
        if (statement == str)
            return true;

    return false;
}

bool isOperator(const string &str)
{
    const vector<string> operators{"<", ">", "<=", ">=", "*", "+", "-", "/", "=", "-=", "*=", "+=", "/=", "++", "--", "=="};
    for(const auto& op : operators)
        if (op == str)
            return true;

    return false;
}

bool isSeparator(const string &str)
{
    const vector<string> Separators{"{", "}", ",", "(", ")", ";"};
    for(const auto& separate : Separators)
        if (separate == str)
            return true;

    return false;
}

bool isNotLegal(const string &str)
{
    return str == " " || str == "\n";
}

void printRoleOfToken(const string& token)
{
    if(isOperator(token))
        cout << "(operator, " << token << ")";
    else if(isSeparator(token))
        cout << "(separator, " << token << ")";
    else if(isKeyword(token))
        cout << "(keyword, " << token << ")";
    else if(isStatement(token))
        cout << "(statement, " << token << ")";
    else if(isLiteral(token))
        cout << "(literal, " << token << ")";
    else if(isID(token))
        cout << "(identifier, " << token << ")";
    else if(isComment(token))
        cout << "(comment, " << token << ")";
   // else
        //throw std::runtime_error("Invalid token: " + token);
}

void lexicalAnalyze(const string &nameOfFile)
{
    char ch;
   string buffer;
    fstream file(nameOfFile, fstream::in);

    if (!file.is_open())
    {
        cout << "error while opening the file\n";
        exit(0);
    }

    bool miltiCm = false, singleCm = false;
    while (file >> std::noskipws >> ch)
    {
        if(singleCm || miltiCm)
        {
            if(singleCm && ch == '\n')
                singleCm = false;

            if(miltiCm && ch == '*')
            {
                file >> ch;
                if(ch == EOF)
                    break;

                if(ch == '/')
                    miltiCm = false;
            }
            continue;
        }

        if(ch == '/')
        {
            std::string comm(1, ch);
            file >> ch;
            if(ch == EOF)
            {
                printRoleOfToken(comm);
                break;
            }

            if(ch == '*')
            {
                miltiCm = true;
                comm += ch;
            }
            else if(ch == '/')
            {
                singleCm = true;
                comm += ch;
            }
            if(miltiCm || singleCm)
            {
                printRoleOfToken(comm);
                continue;
            }
        }

        if(isNotLegal(std::string(1, ch)))
        {
            if(!buffer.empty())
            {
                printRoleOfToken(buffer);
                buffer = "";
            }
            continue;
        }

        if(isOperator(std::string(1, ch)) && !isOperator(buffer))
        {
            if(!buffer.empty())
            {
                printRoleOfToken(buffer);
                buffer = "";
            }
        }

        if(!isOperator(std::string(1, ch)) && isOperator(buffer))
        {
            printRoleOfToken(buffer);
            buffer = "";
        }

        if(isSeparator(std::string(1, ch)))
        {
            if(!buffer.empty())
            {
                printRoleOfToken(buffer);
                buffer = "";
            }
            if(isSeparator(std::string(1, ch)))
            {
                printRoleOfToken(std::string(1, ch));
                continue;
            }
        }
        buffer += ch;
    }
    file.close();
}

int main()
{

    lexicalAnalyze("in.cpp");

return 0;
}
