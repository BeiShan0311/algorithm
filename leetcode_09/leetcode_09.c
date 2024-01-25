#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define NUM_TEN 10
int isPalindrome(int x);
int isPalindrome2(int x);

int main()
{
    srand(time(NULL));

    int signal, temp_x;
    for (int idx = 0; idx < 100; idx++)
    {
        temp_x = rand() % 1000;
        signal = isPalindrome2(temp_x);
        if (signal == 1)
        {
            printf("the num %d is Palindrom\n", temp_x);
        }
    }
}

int isPalindrome2(int x)
{
    if (x < 0)
        return 0;
    int temp = x;
    int location = 0;
    // 计算数字的位数
    while (temp)
    {
        temp /= 10;
        location++;
    }
    if (location == 1)
        return 1;
    int reverseX = x % 10;
    temp = x / 10;
    for (int idx = 1; idx < location / 2; idx++)
    {
        reverseX *= 10;
        reverseX += temp % 10;
        temp /= 10;
    }
    temp = 1;
    for (int idx = 0; idx < (location + 1) / 2; idx++)
    {
        temp *= 10;
    }
    x = x / temp;
    if (x == reverseX)
        return 1;
    return 0;

    // int temp = x / 10;
    // int reverseX = x % 10;
    // while (temp)
    // {
    //     reverseX *= 2;
    //     for (int idx = 0; idx < NUM_TEN / 2 - 1; idx++)
    //     {
    //         if ((0x7fffffff - reverseX / ((idx + 1) * 2) * 2) < reverseX)
    //             return 0;
    //         reverseX += reverseX / ((idx + 1) * 2) * 2;
    //     }
    //     reverseX += temp % NUM_TEN;
    //     temp /= NUM_TEN;
    // }
    // if (!(x ^ reverseX))
    // {
    //     return 1;
    // }
    // return 0;
}

// 方法一
int isPalindrome(int x)
{
    if (x < 0)
        return 0;
    int temp = x / 10;
    int reverseX = x % 10;
    while (temp)
    {
        reverseX *= 2;
        for (int idx = 0; idx < NUM_TEN / 2 - 1; idx++)
        {
            if ((0x7fffffff - reverseX / ((idx + 1) * 2) * 2) < reverseX)
                return 0;
            reverseX += reverseX / ((idx + 1) * 2) * 2;
        }
        reverseX += temp % NUM_TEN;
        temp /= NUM_TEN;
    }
    if (!(x ^ reverseX))
    {
        return 1;
    }
    return 0;
}