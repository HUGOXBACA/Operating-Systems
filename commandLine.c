#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv [])
{
    int i = 0;
    double d;

    if (argc != 5)
    {
        printf ("Usage: cl arg1 arg2 arg3 9.9\n");
        return 1;
    }

    if ((d = atof (argv [4])) == 0)
    {
        printf ("ERROR: Last argument must be 9.9\n");
        return 1;
    }

    printf ("%d\n", argc);
    while (i < argc - 1)
    {
        printf ("%s\n", argv [i]);
        i ++;
    }
    printf ("%.1f\n", d);

    return 0;
}
