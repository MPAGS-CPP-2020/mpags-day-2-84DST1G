// Standard Library includes
#include "CaesarCipher.hpp"

std::string runCaesarWordSalad(std::string in, int key, bool encrypt)
{
    std::string out {""};

    for (int i = 0; i < in.size(); i++)
    {
        int num = in[i] - 65;

        if (encrypt)
        {
            num += key;
        }
        else
        {
            num -= key;
        }

        while (num > 24)
        {
            num -= 25;
        }
        while (num < 0)
        {
            num += 25;
        }

        num += 65;

        out += (char)num;
        
    }

    return out;
}