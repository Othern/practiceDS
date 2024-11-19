#include<stdio.h>

void hanoi(int n, char start, char temp, char end)
{
    if (n > 0)
    {
        hanoi(n - 1, start, end, temp);
        printf("盤子%d 從柱子%c 移到柱子%c\n", n, start, end);
        hanoi(n - 1, temp, start, end);
    }
}
int main()
{
    int n = 3;
    hanoi(n, 'B', 'C', 'A');
    return 0;
}