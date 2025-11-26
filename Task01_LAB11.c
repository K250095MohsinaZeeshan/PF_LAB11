#include <stdio.h>
#include <string.h>

#define MAX_GIFTS 100

typedef struct {
    char name[50];
    char type[50];
    float price;
    int quantity;
} Gift;
void inputGifts(Gift gifts[], int n) {
	int i;
    for(i = 0; i < n; i++) {
        printf("\nEnter details for the gift %d:\n", i + 1);
        printf("Name of gift: ");
        scanf("%s", gifts[i].name);
        printf("Type of gift: ");
        scanf("%s", gifts[i].type);
        printf("Price of the gift: ");
        scanf("%f", &gifts[i].price);
        printf("Quantity of gifts: ");
        scanf("%d", &gifts[i].quantity);
    }
}

void findExpensiveGifts(Gift gifts[], int n, float limit) {
    printf("\nGifts priced above %.2f:\n", limit);

    int i,found = 0;
    for(i = 0; i < n; i++) {
        if(gifts[i].price > limit) {
            printf("%s (%s) - $%.2f\n",
                   gifts[i].name,
                   gifts[i].type,
                   gifts[i].price);
            found = 1;
        }
    }

    if(!found) 
        printf("\nNo gifts found above this price.\n");
}

void findHighQuantityGifts(Gift gifts[], int n, int limit) {
	int i;
    printf("\nGifts with quantity above %d:\n", limit);
    int found = 0;
    for(i = 0; i < n; i++) {
        if(gifts[i].quantity > limit) {
            printf("%s (%s) - %d\n",
                   gifts[i].name,
                   gifts[i].type,
                   gifts[i].quantity);
            found = 1;
        }
    }
    if(!found)
        printf("\nNo gifts found above this quantity.\n");
}
int main() {
    Gift gifts[MAX_GIFTS];
    int n;
    float priceLimit;
    int quantityLimit;

    printf("GIFTS DISTRIBUTION SYSTEM\n");
    printf("_________________________\n");
    printf("\nEnter number of gifts: ");
    scanf("%d", &n);

    inputGifts(gifts, n);

    printf("\nEnter price limit: ");
    scanf("%f", &priceLimit);
    findExpensiveGifts(gifts, n, priceLimit);

    printf("\nEnter quantity limit: ");
    scanf("%d", &quantityLimit);
    findHighQuantityGifts(gifts, n, quantityLimit);

    return 0;
}

