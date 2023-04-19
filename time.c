#include <stdio.h>
#include <time.h>

int main()
{
    int hours;
    int minutes; 
    int seconds;
    int array[5][3]; // i - строки; j - столбцы
    int min;
    int buffer;
    FILE *read;
    FILE *write;
    write = fopen("output.txt", "w");
    read = fopen("input.txt", "r");
    for(int j = 0; j < 5; j++)
    {
        fscanf(read, "%d %d %d", &hours, &minutes, &seconds);
        array[0][j] = hours;
        array[1][j+1] = minutes;
        array[2][j+2] = seconds;
    }
    for(int j = 0; j < 4; j++)
    {
        min = j;
        for(int i = j+1; i < 4; i++)
        {
            if(array[0][j] < array[0][i])
            {
                min = i;
                buffer = array[0][j];
                array[0][j] = array[0][min];
                array[0][min] = buffer;
                buffer = array[1][j];
                array[1][j] = array[1][min];
                array[1][min] = buffer;
                buffer = array[2][j];
                array[2][j] = array[2][min];
                array[2][min] = buffer;
            }
            else if(array[1][j] < array[1][i])
            {
                min = i;
                buffer = array[0][j];
                array[0][j] = array[0][min];
                array[0][min] = buffer;
                buffer = array[1][j];
                array[1][j] = array[1][min];
                array[1][min] = buffer;
                buffer = array[2][j];
                array[2][j] = array[2][min];
                array[2][min] = buffer;
            }
            else if(array[2][j] < array[2][i])
            {
                min = i;
                buffer = array[0][j];
                array[0][j] = array[0][min];
                array[0][min] = buffer;
                buffer = array[1][j];
                array[1][j] = array[1][min];
                array[1][min] = buffer;
                buffer = array[2][j];
                array[2][j] = array[2][min];
                array[2][min] = buffer;
            }
        }
    }
    for(int j = 0; j < 5; j++)
    {
        fprintf(write, "%d %d %d\n", array[0][j], array[1][j+1], array[2][j+2]);
    }
    fclose(read);
    fclose(write);
}