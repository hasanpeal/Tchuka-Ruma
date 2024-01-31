#include <stdio.h>
#include <stdbool.h>

#define NUM_SECTIONS 4

void printGameStatus(int data[], int ruma) {
    printf("%d %d %d %d | %d\n", data[0], data[1], data[2], data[3], ruma);
}

int main() {
    int data[NUM_SECTIONS] = {2, 2, 2, 2};
    int ruma = 0;
    int input;
    bool done = false;

    while (!done) {
        printGameStatus(data, ruma);
        printf("Choose a section (1-4): ");
        while(scanf("%d", &input) != 1 || input < 1 || input > NUM_SECTIONS || data[input - 1] == 0) {
            printf("Invalid choice. Choose a section (1-4): ");
            while(getchar() != '\n'); // Clear the input buffer
        }

        int currVal = input - 1;
        int total = data[currVal];
        data[currVal] = 0;

        while(total > 0) {
            currVal = (currVal + 1) % (NUM_SECTIONS + 1); 
            if (currVal == NUM_SECTIONS) { 
                ruma++;
            } else {
                data[currVal]++;
            }
            total--;

            if (total == 0) {
                if (currVal == NUM_SECTIONS) {
                    break;
                } else if (data[currVal] > 1) { 
                    printGameStatus(data, ruma);
                    printf("Last piece landed in section %d. Continue sowing seeds!\n", currVal + 1);
                    total = data[currVal];
                    data[currVal] = 0;
                } else if (data[currVal] == 1 && currVal != NUM_SECTIONS) {
                    printGameStatus(data, ruma);
                    printf("You lost because the last counter fell into section %d.\n", currVal + 1);
                    done = true;
                }
            }
        }
        if (!done) {
            done = true;
            for (int i = 0; i < NUM_SECTIONS; i++) {
                if (data[i] != 0) {
                    done = false;
                    break;
                }
            }
            if (done && ruma > 0) {
                printf("You won!\n");
            }
        }
    }
    return 0;
}

