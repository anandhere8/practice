#include <iostream>

int8_t a[10][62];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < 2*n-1; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < s.size(); ++j)
        {
            if (s[j] >= '0' && s[j] <= '9') a[j][s[j]-'0'] ^= 1;
            if (s[j] >= 'a' && s[j] <= 'z') a[j][(s[j]-'a')+10] ^= 1;
            if (s[j] >= 'A' && s[j] <= 'Z') a[j][(s[j]-'A')+36] ^= 1;
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 62; ++j)
        {
            if (a[i][j])
            {
                if (j < 10) std::cout << j;
                else if (j < 36) std::cout << char('a'+(j-10));
                else std::cout << char('A'+(j-36));
            }
        }
    }
}
