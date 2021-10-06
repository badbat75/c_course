//to use strcpy_s and strcat_s you need to use LIB_EXT from stdlib
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Please enter your name: ");
    char name[40];
    //Last char array must be null (\0) so we must read only 40-1 chars
    scanf("%39s", &name);
 
    char msg[57];
    /* strcpy_s strcat_s are secured strcpy and strcat functions but not implemented in GNU C
    strcpy_s(msg, sizeof(msg), "Nice to meet you, ");
    strcat_s(msg, sizeof(msg), name);
    strcat_s(msg, sizeof(msg), "!\n");
    */
    strcpy(msg, "Nice to meet you, ");
    strcat(msg, name);
    strcat(msg, "!\n"); 
    //it is possible to use put to write a variable to console without formatting it
    puts(msg);

    int len = strlen(msg);
    int size = sizeof(msg);

    printf("The message length is %d and size is %d\n", len, size);

    return 0;
}