#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void sortActivities(int n, int s[], int f[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (f[j] < f[min_index])
            {
                min_index = j;
            }
        }
        swap(&f[min_index], &f[i]);
        swap(&s[min_index], &s[i]);
    }
}
void findMaxActivities(int n, int s[], int f[])
{
    sortActivities(n, s, f);
    printf("Selected activities:\n");
    int i = 0;
    printf("Activity 1 (Start: %d, Finish: %d)\n", s[i], f[i]);
    for (int j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            printf("Activity %d (Start: %d, Finish: %d)\n", j + 1, s[j], f[j]);
            i = j;
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    int s[n], f[n];
    printf("Enter the start times of the activities:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    printf("Enter the finish times of the activities:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &f[i]);
    }
    findMaxActivities(n, s, f);
    return 0;
}
