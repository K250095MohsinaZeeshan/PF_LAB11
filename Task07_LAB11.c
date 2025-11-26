#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

typedef struct {
    char luckyColor[20];
    int luckyNumber;
    char advice[100];
} ZodiacForecast;

typedef struct {
    char name[50];
    int day, month;
    char zodiac[20];
    ZodiacForecast forecast;
} User;

void assignZodiac(User *u) 
{
    int day = u->day, month = u->month;

    if((month == 3 && day >= 21) || (month == 4 && day <= 19))
        strcpy(u->zodiac, "Aries");
    else if((month == 4 && day >= 20) || (month == 5 && day <= 20))
        strcpy(u->zodiac, "Taurus");
    else if((month == 5 && day >= 21) || (month == 6 && day <= 20))
        strcpy(u->zodiac, "Gemini");
    else if((month == 6 && day >= 21) || (month == 7 && day <= 22))
        strcpy(u->zodiac, "Cancer");
    else if((month == 7 && day >= 23) || (month == 8 && day <= 22))
        strcpy(u->zodiac, "Leo");
    else if((month == 8 && day >= 23) || (month == 9 && day <= 22))
        strcpy(u->zodiac, "Virgo");
    else if((month == 9 && day >= 23) || (month == 10 && day <= 22))
        strcpy(u->zodiac, "Libra");
    else if((month == 10 && day >= 23) || (month == 11 && day <= 21))
        strcpy(u->zodiac, "Scorpio");
    else if((month == 11 && day >= 22) || (month == 12 && day <= 21))
        strcpy(u->zodiac, "Sagittarius");
    else if((month == 12 && day >= 22) || (month == 1 && day <= 19))
        strcpy(u->zodiac, "Capricorn");
    else if((month == 1 && day >= 20) || (month == 2 && day <= 18))
        strcpy(u->zodiac, "Aquarius");
    else if((month == 2 && day >= 19) || (month == 3 && day <= 20))
        strcpy(u->zodiac, "Pisces");
}
void displayHoroscope(User *u) 
{
    printf("\n--- HOROSCOPE FOR %s ---\n", u->name);
    printf("Zodiac Sign: %s\n", u->zodiac);
    printf("Lucky Color: %s\n", u->forecast.luckyColor);
    printf("Lucky Number: %d\n", u->forecast.luckyNumber);
    printf("Advice: %s\n", u->forecast.advice);
}

void updateForecast(ZodiacForecast *forecast, char color[], int number, char advice[]) 
{
    strcpy(forecast->luckyColor, color);
    forecast->luckyNumber = number;
    strcpy(forecast->advice, advice);
}

int main() {
    User users[MAX_USERS];
    int n, i;
    printf("ASTROLOGY APP\n");
    printf("_____________\n");
    printf("\nEnter number of users: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\n--- Enter details for user %d ---\n", i + 1);

        printf("Enter name: ");
        scanf("%s", users[i].name);

        printf("Enter birth day (1-31): ");
        scanf("%d", &users[i].day);

        printf("Enter birth month (1-12): ");
        scanf("%d", &users[i].month);

        assignZodiac(&users[i]);

        printf("Enter lucky color: ");
        scanf("%s", users[i].forecast.luckyColor);

        printf("Enter lucky number: ");
        scanf("%d", &users[i].forecast.luckyNumber);

        getchar(); 

        printf("Enter advice: ");
        fgets(users[i].forecast.advice, sizeof(users[i].forecast.advice), stdin);
        users[i].forecast.advice[strcspn(users[i].forecast.advice, "\n")] = '\0';
    }
    printf("____________________________________\n");
    printf("\n\n--- DISPLAYING ALL HOROSCOPES ---\n");
    for(i = 0; i < n; i++) {
        displayHoroscope(&users[i]);
    }

    return 0;
}

