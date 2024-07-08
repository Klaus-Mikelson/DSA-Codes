#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct store
{
    char pname[20];
    char pcode[10];
    char cat[10];
    char price[8];
    char stock[100];
};

struct store *itemadd(struct store *item)
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
    printf("Quantity\n");
    scanf("%s", &item->stock);

    fseek(file, 0, SEEK_CUR);

    fprintf(file, "%s %s %s %s %s\n", item->pname, item->pcode, item->price, item->cat,item->stock);

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
    while (fscanf(file, "%s %s %s %s %s\n", item->pname, item->pcode, item->price, item->cat,item->stock) != EOF)
    {
        if (strcmp(item->pcode, code) == 0)
        {
            printf("Item with matching details Found\n");

            printf("\nItem's Detail\n");
            printf("Code: %s\n", item->pcode);
            printf("Name: %s\n", item->pname);
            printf("Category: %s\n", item->cat);
            printf("Price: %s\n", item->price);
            printf("Stocks Quantity %s\n\n", item->stock);

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


    printf("Fetching Data................\n");
    while (fscanf(file, "%s %s %s %s %s\n", item->pname, item->pcode, item->price, item->cat,item->stock) != EOF)
    {
            printf("\nItem's Detail\n");
            printf("Code: %s\n", item->pcode);
            printf("Name: %s\n", item->pname);
            printf("Category: %s\n", item->cat);
            printf("Price: %s\n", item->price);
            printf("Stocks Quantity %s\n\n", item->stock);

    }

    fclose(file);
}

void updatestock(struct store *item) {
    FILE *file, *tempfile;
    char code[20];
    char cho[20];
    int found = 0;


    file = fopen("Items.txt", "r");
    tempfile = fopen("TempItems.txt", "w");

    if (file == NULL||tempfile == NULL) {
        printf("Error opening file!\n");
    }else{

    printf("Enter Item ID or pcode\n");
    scanf("%s", code);
    
    printf("Enter New quantity\n");
    scanf("%s", cho);

    printf("Fetching Data................\n");

    // Read each line from the original file
    while (fscanf(file, "%s %s %s %s %s\n", item->pname, item->pcode, item->price, item->cat, item->stock) != EOF) {
        if (strcmp(item->pcode, code) == 0) {

            strcpy(item->stock, cho);

            printf("Invenotry Updated\n");
            printf("Name: %s\n", item->pname);
            printf("Stocks Quantity: %s\n", item->stock);
            found = 1;
        }
        // Write the (possibly updated) item to the temporary file
        fprintf(tempfile, "%s %s %s %s %s\n", item->pname, item->pcode, item->price, item->cat, item->stock);
    }
    }

    fclose(file);
    fclose(tempfile);

    if (found) {
        remove("Items.txt");
        rename("TempItems.txt", "Items.txt");
    } else {
        printf("Item with code %s not found\n", code);
        remove("TempItems.txt");
    }

}

int main()
{

    struct store *item, *start;
    item = (struct store *)malloc(sizeof(struct store));
    int stock = 0;
    start=item;
    printf("-------------------------Store management-------------------------------\n\n");
    printf("\t\t1)Add items to inventory\n"
           "\t\t2)Search items\n"
           "\t\t3)Display items\n"
           "\t\t4)Update the inventory\n"
           "\t\t5)exit\n");
    int ch;
    char ans = 'y';
    while (ans == 'y')
    {
        printf("Enter Choice ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            item = itemadd(item);
            break;
        case 2:
            itemsearch(start);
            break;
        case 3:
            displayitem(start);
            break;
        case 4:
            updatestock(start);
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
    
    return 0;
}