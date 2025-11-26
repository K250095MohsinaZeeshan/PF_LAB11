#include <stdio.h>

#define MAX_TEAMS 100
#define MAX_ROUNDS 50

int sumScores(int scores[], int n) {
    if(n == 0) return 0;
    return scores[n-1] + sumScores(scores, n-1);
}

int main() {
    int teams, rounds, i, j, threshold;
    printf("TEAMS SCORES RECORDER\n");
    printf("_____________________\n");
    printf("\nEnter number of teams: ");
    scanf("%d", &teams);
    printf("Enter number of rounds: ");
    scanf("%d", &rounds);
    printf("______________________\n");

    int scores[MAX_TEAMS][MAX_ROUNDS];

    for(i = 0; i < teams; i++) {
        printf("\nEnter scores for team %d:\n", i+1);
        for(j = 0; j < rounds; j++) {
            scanf("\n%d", &scores[i][j]);
        }
    }
    printf("___________________________\n");

    printf("\nEnter score threshold: ");
    scanf("%d", &threshold);

    for(i = 0; i < teams; i++) {
        int total = sumScores(scores[i], rounds);
        printf("\nTeam %d total score: %d\n", i+1, total);
        if(total > threshold) {
            printf("\nTeam %d is above the threshold!\n", i+1);
        }
    }

    return 0;
}

