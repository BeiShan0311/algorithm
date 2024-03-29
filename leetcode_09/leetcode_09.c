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
        temp_x = rand() % 10000;
        signal = isPalindrome2(temp_x);
        if (signal == 1)
        {
            printf("the num %d is Palindrom\n", temp_x);
        }
    }
    // if (isPalindrome2(121) == 1)
    //     printf("the num %d is Palindrom\n", temp_x);
}

int isPalindrome2(int x)
{
#if 0
    if (x < 0)
    {
        return 0;
    }
    if (x < 10)
    {
        return 1;
    }
    int temp = x;
    int location = 0;
    // 计算数字的位数

    
    while (temp)
    {
        temp /= 10;
        location++;
    }
    int reverseX = x % 10;
    temp = x / 10;
    for (int idx = 1; idx < location / 2; idx++)
    {
        reverseX *= 10;
        reverseX += temp % 10;
        temp /= 10;
    }
    printf("temp:%d\tx:%d\n", temp, x);
    temp = 1;
    for (int idx = 0; idx < (location + 1) / 2; idx++)
    {
        temp *= 10;
    }
    x = x / temp;
    if (x ^ reverseX)
        return 0;
#elif 0
    // 方法二 求解一半逆序数进行比对
    if (x < 0)
    {
        return 0;
    }
    if (x < 10)
    {
        return 1;
    }
    int temp = x;
    int location = 0;
    // 计算数字的位数
    while (temp)
    {
        temp /= 10;
        location++;
    }
    // 到这里，x可变，用temp代替reverseX，x替换temp,替换上述算法
    temp = x % 10;
    x = x / 10;
    for (int idx = 1; idx < location / 2; idx++)
    {
        temp *= 10;
        temp += x % 10;
        x /= 10;
    }
    printf("temp:%d\tx:%d\t", temp, x);
    if (location % 2)
        x /= 10;
    if (x ^ temp)
        return 0;
#elif 0
    // 尝试使用两次循环解决
    if (x < 0)
    {
        return 0;
    }
    if (x < 10)
    {
        return 1;
    }
    int temp = x;
    // 记录x左侧和右侧
    int posleft = 1, posright = 10;
    // 计算数字的位数
    while (temp)
    {
        temp /= 10;
        if (temp)
            posleft *= 10;
    }
    for (; posleft >= posright;)
    {
        if (x / posleft % 10 ^ (x % posright) / (posright / 10))
            return 0;
        posleft /= 10;
        posright *= 10;
    }
#else
    // 官方题解
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return 0;
    }
    if (x < 10)
    {
        return 1;
    }
    int reverseX = x % 10;
    x /= 10;
    while (x > reverseX)
    {
        reverseX *= 10;
        reverseX += x % 10;
        x /= 10;
    }

    return x == reverseX || x == reverseX / 10;
#endif
    return 1;
}

// 方法一 暴力解法
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