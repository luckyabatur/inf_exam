#include <stdio.h>
#include <stdbool.h>

void copy(const char *dest, const char *src)
{
    FILE *f1 = fopen(src, "rb");
    FILE *f2 = fopen(dest, "wb");
    if (f1 == NULL || f2 == NULL)
    {
        perror("Opening error");
        if (f1 != NULL) fclose(f1);
        if (f2 != NULL) fclose(f2);
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
    FILE *f1 = fopen(src, "rb");
    FILE *f2 = fopen(dest, "rb");
    FILE *f3 = fopen(res, "wb");
    int buf;
    if (f1 == NULL || f2 == NULL || f3 == NULL)
    {
        perror("Opening error");
        if (f1 != NULL) fclose(f1);
        if (f2 != NULL) fclose(f2);
        if (f3 != NULL) fclose(f3);
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
    bool res = true;
    FILE *f1 = fopen(fname1, "rb");
    FILE *f2 = fopen(fname2, "rb");
    if (f1 == NULL || f2 == NULL)
    {
        perror("Opening error");
        if (f1 != NULL) fclose(f1);
        if (f2 != NULL) fclose(f2);
        return false;
    }
    int buf1, buf2;
    while ((buf1 = fgetc(f1)) != EOF && (buf2 = fgetc(f2)) != EOF)
    {
        if (buf1 != buf2)
        {
            res = false;
            break;
        }
    }
    if (buf1 != EOF || buf2 != EOF)
    {
        res = false;
    }
    fclose(f1);
    fclose(f2);
    return res;
}