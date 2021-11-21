#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * str, int n);

int main(int argc, char **argv)
{
    Tree pets;
    char ch;

    InitalizeTree(&pets);
    while ((ch = menu()) != 'q')
    {
        switch (ch)
        {
        case 'a' :
            addpet(&pets);
            break;
        case 'l' :
            showpets(&pets);
            break;
        case 'f' :
            findpet(&pets);
            break;
        case 'd' :
            droppet(&pets);
            break;
        case 'n' :
            printf("%d pets in the club.\n", TreeItemCount(&pets));
            break;
        default :
            puts("switching error.");
        }

    }

    DeleteAll(&pets);

    return 0;
}

void showpets(const Tree * pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries.");
    else
        Traverse(pt, printitem);
}

void printitem(Item item)
{
    printf("Pet %-19s Kind: %-19s\n",
           item.petname, item.petkind);
}

void findpet(const Tree * pt)
{
    Item item;
    if (TreeIsEmpty(pt))
    {
        puts("No entries.");
        return;
    }

    puts("Please enter the name of pet to find:");
    s_gets(item.petname, MAX_PET_NAME);
    puts("Enter the kind of pet:");
    s_gets(item.petkind, MAX_PET_KIND);
    uppercase(item.petname);
    uppercase(item.petkind);
    printf("%s the %s ", item.petname, item.petkind);
    if (InTree(&item, pt))
        puts("is a member.");
    else
        puts("is not member.");
}

void droppet(Tree * pt)
{
    Item temp;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;
    }

    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, MAX_PET_NAME);
    puts("Please enter pet kind:");
    s_gets(temp.petkind, MAX_PET_KIND);
    uppercase(temp.petkind);
    uppercase(temp.petname);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (DeleteItem(&temp, pt))
        puts("is dropped from the club");
    else
        puts("is not a member.");
}

void addpet(Tree * pt)
{
    Item temp;

    if (TreeIsFull(pt))
        puts("No room in the club.");
    else
    {
        puts("Enter name of the pet:");
        s_gets(temp.petname, MAX_PET_NAME);
        puts("Enter pet kind:");
        s_gets(temp.petkind, MAX_PET_KIND);
        uppercase(temp.petkind);
        uppercase(temp.petname);
        AddItem(&temp, pt);
    }
}

void uppercase(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

char menu(void)
{
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet\t\tl) show list of pets");
    puts("n) number of pets\tf) find pets");
    puts("d) delete a pet\t        q) quit");

    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);
        if (strchr("alnfdq", ch) == NULL)
            puts("Please enter a,l,n,f,d or q:");
        else
            break;
    }

    if (ch == EOF)
        ch = 'q';

    return ch;
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(str, n, stdin);

    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
        {
            *find = 0;
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}
