#include <stdio.h>
#include <string.h>
#include <ctype.h>

int dfa1 = 0;
// machine 1

// state Q(initial)
void start(char c)
{

    if (c == 'a')
    {

        dfa1 = 1;
    }

    else if (c == 'b')
    {

        dfa1 = 3;
    }

    else
    {

        dfa1 = -1;
    }
}

// state Q1

void state1(char c)
{

    if (c == 'a')
    {

        dfa1 = 2;
    }

    else if (c == 'b')
    {

        dfa1 = 4;
    }

    else
    {

        dfa1 = -1;
    }
}

// state Q2

void state2(char c)
{

    if (c == 'b')
    {

        dfa1 = 3;
    }

    else if (c == 'a')
    {

        dfa1 = 1;
    }

    else
    {

        dfa1 = -1;
    }
}

// state Q3

void state3(char c)
{

    if (c == 'b')
    {

        dfa1 = 3;
    }

    else if (c == 'a')
    {

        dfa1 = 4;
    }

    else
    {

        dfa1 = -1;
    }
}

// state Q4

void state4(char c)
{

    dfa1 = -1;
}

int isAccepted(char str[])
{

    int i;
    int len = strlen(str);
    puts(str);

    for (i = 0; i < len; i++)
    {

        if (dfa1 == 0)

            start(str[i]);

        else if (dfa1 == 1)

            state1(str[i]);

        else if (dfa1 == 2)

            state2(str[i]);

        else if (dfa1 == 3)

            state3(str[i]);

        else if (dfa1 == 4)

            state4(str[i]);

        else

            return 0;
    }

    if (dfa1 == 3)

        return 1;

    else

        return 0;
}

int machine_1(char str[])
{
    if (isAccepted(str))

        return 1;
    else

        return 0;
}

// machine 2

int dfa2 = 0;

// state Q(intial)

void start2(char c)
{
    if (c == 'a')
    {
        dfa2 = 1;
    }
    else
    {
        dfa2 = -1;
    }
}

// state Q1

void state_1(char c)
{

    if (c == 'b')
    {

        dfa2 = 2;
    }
    else
    {

        dfa2 = -1;
    }
}

// final state Q(final)

void final_s(char c)
{
    if (c == 'a' || c == 'b')
    {
        dfa2 = 2;
    }

    else
    {
        dfa2 = -1;
    }
}

int isChecked(char str[])
{
    int i;
    int len = strlen(str);
    puts(str);

    for (i = 0; i < len; i++)
    {
        if (dfa2 == 0)
        {
            start2(str[i]);
        }
        else if (dfa2 == 1)
        {
            state_1(str[i]);
        }
        else if (dfa2 == 2)
        {
            final_s(str[i]);
        }
        else
        {
            return 0;
        }
    }

    // printf("dfa2 = %d\n", dfa2);

    if (dfa2 == 2)
    {

        return 1;
    }

    else
    {

        return 0;
    }
}

int machine_2(char str[])
{
    if (isChecked(str))

        return 1;
    else

        return 0;
}

// machine 3 (email validator)

int dfa3 = 0;

void Astate(char c)
{
    if (!(isdigit(c)))
    {

        dfa3 = 1;
    }
    else
    {
        dfa3 = -1;
    }
    printf("Astate:%d\n", dfa3);
}

void Bstate(char c)
{
    if (c == '@')
    {
        dfa3 = 2;
        // printf("@ is taken\n");
    }
    else if (!(isdigit(c)))
    {
        dfa3 = 1;
    }
    else
    {
        dfa3 = -1;
    }
    printf("Bstate:%d\n", dfa3);
}

void Cstate(char c)
{
    if (isalnum(c))
    {
        dfa3 = 3;
    }
    else
    {
        dfa3 = -1;
    }
    printf("Cstate:%d\n", dfa3);
}

void Dstate(char c)
{
    if (c == '.')
    {
        dfa3 = 4;
    }
    else
    {
        dfa3 = 2;
    }
    printf("Dstate:%d\n", dfa3);
}

void Estate1(char c)
{
    if (c == ' ')
    {
        dfa3 = 2;
    }
    else if (c == 'c')
    {
        dfa3 = 5;
    }
    else
    {
        dfa3 = -1;
    }
    printf("Estate1:%d\n", dfa3);
}
void Estate2(char c)
{
    if (c == 'o')
    {
        dfa3 = 6;
    }
    else
    {
        dfa3 = -1;
    }
    printf("Estate2:%d\n", dfa3);
}
void Estate3(char c)
{
    if (c == 'm')
    {
        dfa3 = 7;
    }
    else
    {
        dfa3 = -1;
    }
    printf("Estate3:%d\n", dfa3);
}

int isValid(char str[])
{

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (dfa3 == 0)
        {
            Astate(str[i]);
        }
        else if (dfa3 == 1)
        {
            Bstate(str[i]);
        }
        else if (dfa3 == 2)
        {
            Cstate(str[i]);
        }
        else if (dfa3 == 3)
        {
            Dstate(str[i]);
        }
        else if (dfa3 == 4)
        {
            Estate1(str[i]);
        }
        else if (dfa3 == 5)
        {
            Estate2(str[i]);
        }
        else if (dfa3 == 6)
        {
            Estate3(str[i]);
        }
        else if (dfa3 == 7)
        {
            break;
        }
        else
        {
            return 0;
        }
    }
    printf("dfa3 = %d\n", dfa3);

    if (dfa3 == 7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int machine_3(char str[])
{

    if (isValid(str))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    printf("******  There are 3 machines which are takes input as follows   ******\n");
    printf("\n--> 1] machine 1:\n");

    printf("string is valid for:\n");

    printf("\nL = { a^n b^m | n mod 2 == 0 , m >= 1 }\n");

    printf("\nexample : L = { 'aab','aaaabb'...}\n");
    printf("\n");

    printf("--> 2] machine 2:\n");

    printf("string is valid for:\n");

    printf("\nL = { ab.a^m b^n| m >= 0 , n >= 0 }\n");

    printf("\nexample : L = { 'ab','aba','abb','abab',abba'...}\n");
    printf("\n");

    printf("--> 3] machine:\n");

    printf("email validation DFA:\n");

    printf("enter here string:\n");
    char str[100];
    // fgets(str,100,stdin);
    gets(str);

    int option;
    printf("which machine you want to test\n1]machine 1\n2]machine 2\n3]email validation\n");
    scanf("%d", &option);

    if (option == 1)
    {
        int a = machine_1(str);
        if (a == 1)
        {
            printf("\n   Valid String --> Accepted \n");
        }
        else
        {
            printf("\n   Invalid String --> Rejected \n");
        }
    }
    else if (option == 2)
    {
        int b = machine_2(str);
        if (b == 1)
        {
            printf("\n   Valid String --> Accepted \n");
        }
        else
        {
            printf("\n   Invalid String --> Rejected \n");
        }
    }
    else
    {
        int c = machine_3(str);

        if (c == 1)
        {
            printf("\n   Valid Email --> Accepted \n");
        }
        else
        {
            printf("\n   Invalid Email --> Rejected \n");
        }
    }

    printf("\n \n \n \n \n \n");
}