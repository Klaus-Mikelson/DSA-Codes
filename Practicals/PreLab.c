#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct store
{
    char pname[20];
    char pcode[10];
    char cat[10];
    char price[8];
};

struct store *itemadd(struct store *item, int *stock)
{

    FILE *file;

    file = fopen("Items.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return item;
    }

    printf("Item name\n");
    scanf("%s", &item->pname);
    printf("Item code\n");
    scanf("%s", &item->pcode);
    printf("Item Price\n");
    scanf("%s", &item->price);
    printf("Category\n");
    scanf("%s", &item->cat);

    fseek(file, 0, SEEK_CUR);

    fprintf(file, "%s %s %s %s\n", item->pname, item->pcode, item->price, item->cat);

    *stock += 1;
    printf("Item added successfully\n");
    item++;
    fclose(file);
    return item;
}

void itemsearch(struct store *item)
{
    FILE *file;

    file = fopen("Items.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char code[20];
    int found = 0;

    printf("Enter Item Code\n");
    scanf("%s", code);

    printf("Fetching Data................\n");
    while (fscanf(file, "%s %s %s %s\n", item->pname, item->pcode, item->price, item->cat) != EOF)
    {
        if (strcmp(item->pcode, code) == 0)
        {
            printf("Item with matching details Found\n");

            printf("\nItem's Detail\n");
            printf("Code: %s\n", item->pcode);
            printf("Name: %s\n", item->pname);
            printf("Category: %s\n", item->cat);
            printf("Price: %s\n\n", item->price);

            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Item Not Found.\n");
    }
    fclose(file);
}

void displayitem(struct store *item)
{
    FILE *file;

    file = fopen("Items.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char code[20];

    printf("Enter Category\n");
    scanf("%s", code);

    printf("Fetching Data................\n");
    while (fscanf(file, "%s %s %s %s\n", item->pname, item->pcode, item->price, item->cat) != EOF)
    {
        if (strcmp(item->cat, code) == 0)
        {

            printf("\nItem's Detail\n");
            printf("Code: %s\n", item->pcode);
            printf("Name: %s\n", item->pname);
            printf("Category: %s\n", item->cat);
            printf("Price: %s\n\n", item->price);
        }
    }

    fclose(file);
}

void updatestock(struct store *item, int *stock)
{
    FILE *file;
    FILE *tempfile;
    int found = 0;
    char code[20];

    printf("Enter Item ID or pcode to delete\n");
    scanf("%s", code);

    file = fopen("Items.txt", "r");
    tempfile = fopen("temp.txt", "w");
    if (file == NULL || tempfile == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Fetching Data................\n");
    while (fscanf(file, "%s %s %s %s\n", item->pname, item->pcode, item->price, item->cat) != EOF)
    {
        if (strcmp(item->pcode, code) == 0)
        {
            found = 1;
            (*stock)--;
        }
        else
        {
            fprintf(tempfile, "%s %s %s %s\n", item->pname, item->pcode, item->price, item->cat);
        }
    }
    fclose(file);
    fclose(tempfile);

    remove("Items.txt");
    rename("temp.txt", "Items.txt");

    if (found)
    {
        printf("Item deleted successfully\n");
    }
    else
    {
        printf("Item with code %s not found\n", code);
    }
}

void main()
{

    struct store *item, *start;
    item = (struct store *)malloc(sizeof(struct store));
    int stock = 0;
    printf("-------------------------Store management-------------------------------\n\n");
    printf("\t\t1)Add items to inventory\n"
           "\t\t2)Search item\n"
           "\t\t3)Display items with category\n"
           "\t\t4)Update the inventory\n"
           "\t\t5)exit\n");
    int ch;
    char ans = 'y';
    char e;
    while (ans == 'y')
    {
        printf("Enter Choice ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            item = itemadd(item, &stock);
            break;
        case 2:
            itemsearch(item);
            break;
        case 3:
            displayitem(item);
            break;
        case 4:
            updatestock(item, &stock);
            break;
        case 5:
            ans = 'n';
            break;
        default:
            printf("Invalid Option.Pls enter correct\n");
        }
    }
    printf("Exting Program\n");
    printf("---------------------------------------------------------------------------");
}