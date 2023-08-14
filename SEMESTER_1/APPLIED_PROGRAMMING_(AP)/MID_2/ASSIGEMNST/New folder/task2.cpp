#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s, word = "";
    stack<string> stc;
    getline(cin, s); // take the entire sentence as input
    for (int i = 0; i <= s.length(); i++)
    {
        if (s[i] == ' ' or s[i] == '\0') /*if it is end of string or a blank space the push the word to the stack*/
        {
            stc.push(word);
            word = "";
        }
        else if (isalnum(s[i])) /*this ensures that only alphanumeric characters are taken as part of words*/
        {
            word = word + s[i];
        }
    }
    int sz = stc.size();
    while (!stc.empty())
    {
        if (sz == stc.size())
            stc.top()[0] -= 32; // First letter of first should be capital
        if (stc.size() == 1)
            stc.top()[0] += 32;
        cout << stc.top() << " ";
        stc.pop();
    }
}