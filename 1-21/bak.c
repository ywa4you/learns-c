#include <stdio.h>

#define TABSTOP 4   /* size of a tab character */

void puttabs(int pos, int spcs);

/*  replace strings of blanks by the minimum number of tabs and blanks to
    achieve the same spacing */
int main()
{
    int c, pos, spcs;
    pos=spcs=0;
    while ((c=getchar())!='\0') {
       if (c==' ') {
           ++spcs;
           ++pos;
       }
       else if (c=='\t') {
           pos+=TABSTOP-(pos%TABSTOP);
           spcs+=TABSTOP-(pos%TABSTOP);
       }
       else {
           puttabs(pos, spcs);
           putchar(c);
           spcs=0;
           ++pos;
       }
    }
    puttabs(pos, spcs);
    putchar(c);
    return 0;
}

/*  puttabs: put the right amount of tabs and spaces as the position (pos) and
    spaces (spcs) demand. */
void puttabs(int pos, int spcs) {
    if ((TABSTOP-pos%TABSTOP)>spcs) {
        for (;spcs>0;spcs--)
            putchar(' ');
    }
    else {
        while (spcs/TABSTOP!=0) {
            putchar('\t');
            spcs-=TABSTOP;
        }
    }
    while (spcs!=0) {
        putchar(' ');
        --spcs;
}

