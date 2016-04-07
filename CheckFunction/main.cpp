#include <iostream>
#include <cstring>

using namespace std;

class CheckFunction
{
public:
    int newFunction(string code);
};

int CheckFunction::newFunction(string code)
{
    int len = code.length();
    int i = 0;
    int dash = 0;

    while(i <= len)
    {
        switch(code[i])
        {
            case '0':
            case '6':
            case '9': dash += 6;
            break;
            case '1': dash += 2;
            break;
            case '2':
            case '3':
            case '5': dash += 5;
            break;
            case '4': dash += 4;
            break;
            case '7': dash += 3;
            break;
            case '8': dash += 7;
            break;


        }
    }
    i++;
    return dash;
}

int main()
{
    return 0;
}
