#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//#define STRLEN_MAX 4096

char * format_longnum(const char in[])
{
char * cursor_in = in;
char * cursor_out;
char * result;
int len_in = strlen(in);
int len_out = len_in*2; // should be enough

int end_flag = 0;
if((result = (char *) calloc(len_out,1))==NULL)
    {
    perror("calloc");
    exit(EXIT_FAILURE);
    }

cursor_out = &result[len_out-2];
cursor_in = &in[len_in-1];

while(cursor_in != in)
    {
    for(int i=0;i<3;i++)
        {
        *cursor_out = *cursor_in;
        if(cursor_in == in)
            {
            end_flag=1;
            break;
            }
        cursor_out--;
        cursor_in--;
        }

        if(end_flag)
            {
            *cursor_out = *cursor_in;
            return(cursor_out);
            }
            else
            {
            *cursor_out = ',';
            cursor_out--;
            }
    }

*cursor_out = *cursor_in;
return(cursor_out);
}
