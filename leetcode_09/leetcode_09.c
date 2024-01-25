#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int isPalindrome(int x);

int main()
{
    srand(time(NULL));

    int signal, temp_x;
    for (int idx = 0; idx < 100; idx++)
    {
        temp_x = rand() % 1000;
        signal = isPalindrome(temp_x);
        if (signal == 1)
        {
            printf("the num %d is Palindrom\n", temp_x);
        }
    }
}

int isPalindrome(int x)
{
    if (x < 0)
        return 0;
    int temp = x;
    int reverseX = 0;
    while (temp)
    {
        for (int idx = 0; idx < 9; idx++)
        {
            if ((0x7fffffff - reverseX / (idx + 1)) < reverseX)
                return 0;
            reverseX += reverseX / (idx + 1);
        }
        reverseX += temp % 10;
        temp = temp / 10;
    }
    if (x == reverseX)
    {
        return 1;
    }
    return 0;
}