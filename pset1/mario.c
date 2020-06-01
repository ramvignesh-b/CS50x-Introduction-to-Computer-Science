#include <cs50.h>
#include <stdio.h>

void print_space(int i)
{
    int j;
    for(j=0; j<i; j++)
    {
        printf(" ");
    }
}

void print_hash(int i)
{
    int k;
    for(k=0; k<i; k++)
    {
        printf("#");
    }
}

int main(void) 
{

    int height, i;

    do 
    {
        printf("Height: ");
        scanf("%d", &height);
    } 
    while (height < 1 || height > 8);


   for(i=1; i<=height; i++)
   {
       print_space(height-i);
       print_hash(i);
       printf("  ");
       print_hash(i);
       printf("\n");
   }

}
