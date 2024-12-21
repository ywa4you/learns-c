#include <stdio.h>

#define TABSTOP 4   /* size of a tab character */

int plc, spcs;

void puttabs();

/*  replace strings of blanks by the minimum number of tabs and blanks to
    achieve the same spacing */
int main()
{
    int c, pos;
    pos=spcs=plc=0;
    while ((c=getchar())!=EOF) {
       if (c==' ') {
           ++spcs;
           ++pos;
       }
       else if (c=='\t') {
           spcs+=TABSTOP-(pos%TABSTOP);
           pos+=TABSTOP-(pos%TABSTOP);
       }
       else if (c=='\n') {
           puttabs(plc, spcs);
           putchar(c);
           pos=plc=0;
       }
       else {
           puttabs(plc, spcs);
           putchar(c);
           plc=++pos;
       }
    }
    puttabs(plc, spcs);
    putchar(c);
    return 0;
}

/*  puttabs: put the right amount of tabs and spaces as the position of the
    last character (plc) and spaces (spcs) demand. */
void puttabs() {
    int sptots=TABSTOP-(plc%TABSTOP);
    if (sptots>spcs) {
        for (;spcs!=0;--spcs)
            putchar(' ');
    }
    else {
        putchar('\t');
        spcs-=sptots;
        while (spcs>=TABSTOP) {
            putchar('\t');
            spcs-=TABSTOP;
        }
    }
    while (spcs!=0) {
        putchar(' ');
        --spcs;
    }
}

