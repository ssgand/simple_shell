#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    size_t i = 1;
    char *buf = NULL;

    printf("$ ");
    getline(&buf, &i, stdin);
    printf("%s%ld\n", buf, i);

    free(buf);
    return (0);
}
