

#include<stdio.h>
#include<conio.h>
int main(void)
{
    int n, i, j, temp;
    int arr[64];
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    for (i = 1; i < n; i++) 
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) 
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
    printf("Sorted list in ascending order:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\n", arr[i]);
    }
    getch();
}