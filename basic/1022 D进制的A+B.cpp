#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int getMaxWeight( long long c, int d)
{
    int i = 0;
    while((d-1) * pow(d,i) < c)
        i++;
    return i;
}
int main()
{
    long long a, b, c;
    int d;
    cin >> a >> b >> d;
    c = a + b;
    int w = getMaxWeight(c, d);
    string result;
    for(w; w >= 0; w--)
    {
        int coef = 0;
        for(coef; coef <= d; coef++)
        {
            if((coef+1)*pow(d,w) > c)
                break;
        }
        c -= coef*pow(d,w);
        result += to_string(coef);
    }
    if(result[0] == '0' && result.size() > 1)
        result.erase(0,1);
    cout << result << endl;
}
