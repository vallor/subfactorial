#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
#include "format_longnum.h"

#define MAX_STR 4096

int main()
{
int n=0;
char result[MAX_STR] = {0};
mpz_t a, b, c, d, e, i;
mpz_inits(a,b,c,d,e,i,NULL);
mpz_set_ui(a,1); // a = 1

mpz_set_ui(i,2);

for (n=0;n<51;n++)
    {
    if (n == 0) { puts("0:1"); continue; }
    if (n == 1) { puts("1:0"); continue; }

    mpz_set_ui(i,n);
    mpz_add(d,a,b);
    mpz_sub_ui(e,i,1);
    mpz_mul(c,e,d);
    mpz_set(a,b);
    mpz_set(b,c);

    if(mpz_get_str(result,10,c) == NULL)
        {
        perror("mpz_get_str");
        return EXIT_FAILURE;
        }
//  gmp_printf("%d:%'Zd\n", n, c);

/*    printf("n:%d\nstrlen(result):%ld\n%s\n%s\n",
            n,
            strlen(result),
            result,
            format_longnum(result)
            ); */
    printf("%d:%s\n",n,format_longnum(result));
    }
return EXIT_SUCCESS;
}
