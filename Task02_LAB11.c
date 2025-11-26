#include <stdio.h>

void countdown(int days) 
{
    if(days < 0) 
	return;
    printf("%d\n", days);
    countdown(days - 1);
}
int main() 
{
    int events, i, days;
    printf("EVENT MANAGEMENT\n");
    printf("________________\n");
    printf("\nEnter number of events: ");
    scanf("%d", &events);

    for(i = 0; i < events; i++) 
	{
        printf("\nEnter the number of days remaining for the event %d: ", i+1);
        scanf("%d", &days);
        printf("\nCountdown for event %d:\n", i+1);
        countdown(days);
        printf("\n");
    }
    return 0;
}

