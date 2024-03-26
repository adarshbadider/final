#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Days
{
    char *dayname;
    int date;
    char *activity;
};

void create(struct Days *day)
{
    day->dayname = (char *)malloc(sizeof(char) * 20);
    day->activity = (char *)malloc(sizeof(char) * 100);

    printf("Enter the day name: ");
    scanf("%s", day->dayname);

    printf("Enter the date: ");
    scanf("%d", &day->date);

    // Consume newline character left in the buffer after scanf
    getchar();

    printf("Enter the activity for the day: ");
    fgets(day->activity, 100, stdin);
}

void read(struct Days *cal, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter details for the day %d:\n", i + 1);
        create(&cal[i]);
    }
}

void display(struct Days *cal, int size)
{
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Day %d\n", i + 1);
        printf("Dayname: %s\n", cal[i].dayname);
        printf("Date: %d\n", cal[i].date);
        printf("Activity: %s\n", cal[i].activity);
        printf("\n");
    }
}

void freeMemory(struct Days *cal, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(cal[i].dayname);
        free(cal[i].activity);
    }
}

int main()
{
    int size;
    printf("Enter the number of days in the week: ");
    scanf("%d", &size);

    struct Days *cal = (struct Days *)malloc(sizeof(struct Days) * size);

    if (cal == NULL)
    {
        printf("Memory allocation failed, exiting program\n");
        return 1;
    }

    read(cal, size);
    display(cal, size);
    freeMemory(cal, size);
    free(cal); // Freeing the memory allocated for the array

    return 0;
}
