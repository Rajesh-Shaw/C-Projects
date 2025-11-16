#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Q 100
#define MAX_LEN 300

typedef struct {
    char question[MAX_LEN];
    char opt1[MAX_LEN];
    char opt2[MAX_LEN];
    char opt3[MAX_LEN];
    char opt4[MAX_LEN];
    int correct;
} Quiz;

int load_questions(Quiz q[]);
void start_quiz(Quiz q[], int count);

int main() {
    Quiz questions[MAX_Q];
    int count;

    printf("===== QUIZ APPLICATION =====\n");

    count = load_questions(questions);
    if (count == 0) {
        printf("No questions loaded. Exiting...\n");
        return 0;
    }

    printf("Loaded %d questions!\n", count);
    start_quiz(questions, count);

    return 0;
}

int load_questions(Quiz q[]) {
    FILE *fp = fopen("questions.txt", "r");
    if (!fp) {
        printf("Error: Cannot open questions.txt\n");
        return 0;
    }

    int count = 0;

    while (!feof(fp) && count < MAX_Q) {
        fgets(q[count].question, MAX_LEN, fp);
        fgets(q[count].opt1, MAX_LEN, fp);
        fgets(q[count].opt2, MAX_LEN, fp);
        fgets(q[count].opt3, MAX_LEN, fp);
        fgets(q[count].opt4, MAX_LEN, fp);
        fscanf(fp, "%d\n", &q[count].correct);

        // Remove newlines
        q[count].question[strcspn(q[count].question, "\n")] = '\0';
        q[count].opt1[strcspn(q[count].opt1, "\n")] = '\0';
        q[count].opt2[strcspn(q[count].opt2, "\n")] = '\0';
        q[count].opt3[strcspn(q[count].opt3, "\n")] = '\0';
        q[count].opt4[strcspn(q[count].opt4, "\n")] = '\0';

        count++;
    }

    fclose(fp);
    return count;
}

void start_quiz(Quiz q[], int count) {
    int score = 0;

    for (int i = 0; i < count; i++) {
        printf("\nQ%d: %s\n", i + 1, q[i].question);
        printf("1. %s\n", q[i].opt1);
        printf("2. %s\n", q[i].opt2);
        printf("3. %s\n", q[i].opt3);
        printf("4. %s\n", q[i].opt4);

        printf("Your answer: ");
        int ans;
        scanf("%d", &ans);

        if (ans == q[i].correct) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! Correct answer = %d\n", q[i].correct);
        }
    }

    printf("\n===== QUIZ COMPLETED =====\n");
    printf("Your Score: %d / %d\n", score, count);
}
