#include <stdio.h>
#include <string.h>
#include <cs50.h>

float ile_lit(string s);
float ile_zd(string x);
float ile_wr(string x);

int main(void)
{
    string tx = get_string("Text: ");
    float index = (ile_lit(tx) / ile_wr(tx)) * 5.88 - ((ile_zd(tx) / ile_wr(tx)) * 29.6) - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15.5)
    {
        printf("Grade 16+\n");
    }

    printf("Grade %.0f\n", index);
    return 0;

}

// liczenie liter w stringu *** counting letters in a string
float ile_lit(string x)
{
    float l = 0;
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if ((x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z'))
        {
            l = l + 1;
        }
    }
    return l;
}

// liczenie zdan w stringu *** counting sentences in a string
float ile_zd(string x)
{
    float l = 0;
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if ((x[i] == '.') || (x[i] == '?') || (x[i] == '!'))
        {
            l = l + 1;
        }
    }
    return l;
}

// liczenie wyrazow w stringu *** counting words in a string
float ile_wr(string x)
{
    float l = 1;
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (x[i] == ' ')
        {
            l = l + 1;
        }
    }
    return l;
}
