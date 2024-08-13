#include <stdio.h>
#include <stdbool.h>

void copy(const char *dest, const char *src)
{
    FILE *f1 = fopen(src, "r");
    FILE *f2 = fopen(dest, "w");
    if (f1 == NULL || f2 == NULL)
    {
        return;
    }
    int buf;
    while ((buf = fgetc(f1)) != EOF)
    {
        fputc(buf, f2);
    }
    fclose(f1);
    fclose(f2);
}

void fcat(const char *res, const char *dest, const char *src)
{
    FILE *f1 = fopen(src, "r");
    FILE *f2 = fopen(dest, "r");
    FILE *f3 = fopen(res, "w");
    int buf;
    if (f1 == NULL || f2 == NULL || f3 == NULL)
    {
        return;
    }
    while ((buf = fgetc(f2)) != EOF)
    {
        fputc(buf, f3);
    }
    while ((buf = fgetc(f1)) != EOF)
    {
        fputc(buf, f3);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

bool eq(const char *fname1, const char *fname2)
{
    FILE *f1 = fopen(fname1, "r");
    FILE *f2 = fopen(fname2, "r");
    int buf1, buf2;
    while ((buf1 = fgetc(f1)) != EOF & (buf2 = fgetc(f2)) != EOF)
    {
        if (buf1 != buf2)
        {
            return false;
        }
    }
    if (buf1 != EOF || buf2 != EOF)
    {
        return false;
    }
    return true;
}


