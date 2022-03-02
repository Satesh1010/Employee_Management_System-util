#include"main.c"
void flush()
{
    int a;
    while ((a = getchar()) != '\n' && a != EOF);
}