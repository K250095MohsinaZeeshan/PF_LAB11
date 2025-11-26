#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    char category[50];
    int quantity;
} Item;

int main() {
    Item inventory[MAX_ITEMS];
    Item *ptr;
    int n, i;
    char category[50];
    int minimumQuantity;

    printf("INVENTORY MANAGEMENT\n");
    printf("____________________\n");
    printf("\nEnter number of items: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter the name of item %d: ", i+1);
        scanf("%s", &inventory[i].name);
         printf("Enter the category of item %d: ", i+1);
        scanf("%s", &inventory[i].category);
         printf("Enter the available quantity of item %d: ", i+1);
        scanf("%s", &inventory[i].quantity);
    }
    printf("________________________________\n");

    printf("\nEnter category to search: ");
    scanf("%s", category);
    printf("\nEnter minimum quantity: ");
    scanf("%d", &minimumQuantity);
 
    ptr = inventory;
    for(i = 0; i < n; i++, ptr++) {
        if(strcmp(ptr->category, category) == 0 && ptr->quantity >= minimumQuantity) {
            printf("Item: %s, Category: %s, Quantity: %d\n", ptr->name, ptr->category, ptr->quantity);
        }
    }

    return 0;
}

