#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * str, int n);
void add_word(Tree * pt, char * w);
void showwords(const Tree * pt);
void findword(const Tree * pt);

int main(int argc, char **argv)
{
    Tree lists_words;
    char ch;


    int chr;
    char temp[MAX_WORD_SZ];
    FILE * fp;
    int i = 0;
    fp = fopen("wacky.txt", "r");
    InitalizeTree(&lists_words);
    while (( chr = getc(fp)) != EOF && !TreeIsFull(&lists_words))
    {

        if (chr == ' ' || chr == '\n')
        {
            temp[i] = 0;
            i = 0;

            if (temp[0] != 0)
                add_word(&lists_words, temp);

            continue;
        }
        temp[i++] = chr;
    }

	while ((ch = menu()) != '5')
    {
        switch (ch)
        {
        case '1' :
            showwords(&lists_words);
            break;
        case '2' :
            findword(&lists_words);
            break;
        case '3' :
            DeleteAll(&lists_words);
        case '4' :
        	printf("Tree count:%d\n", TreeItemCount(&lists_words));
            break;
        case '5' :
            DeleteAll(&lists_words);
            break;
        default :
            puts("switching error.");
        }

    }


    DeleteAll(&lists_words);
    fclose(fp);
    return 0;
}

void add_word(Tree * pt, char * w)
{
    Item temp;
    strcpy(temp.word, w);
    if (TreeIsFull(pt))
        puts("Tree is full.");
    else
    {
        uppercase(temp.word);
        AddItem(&temp, pt);
    }
}

void showwords(const Tree * pt)
{
    if (TreeIsEmpty(pt))
        puts("No words.");
    else
        Traverse(pt, printitem);
}

void findword(const Tree * pt)
{
    Item  item;
    if (TreeIsEmpty(pt))
    {
        puts("No words.");
        return;
    }

    puts("Please enter the word to find:");
    s_gets(item.word, MAX_WORD_SZ);
    uppercase(item.word);
    if (!InTree(&item, pt))
    {
        printf("%s word not in the list.\n", item.word);
        return;
    }
    else
    {
        item = GetTreeNode(&item, pt);
        printf("Word %s occurred %d times in the file.\n",
               item.word, item.cnt);
    }
}

void printitem(Item item)
{
    printf("Word %-19s count: %-3d\n",
           item.word, item.cnt);
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

    puts("Enter the letter corresponding to your choice:");
    puts("1) list words");
    puts("2) search word");
    puts("3) delete all");
    puts("4) tree count");
    puts("5) quit");

    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);
        if (strchr("12345", ch) == NULL)
            puts("Please enter 1, 2, 3, 4 or 3:");
        else
            break;
    }

    if (ch == EOF)
        ch = '5';

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
