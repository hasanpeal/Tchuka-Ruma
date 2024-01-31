#include <stdio.h>
#include <stdbool.h>

int main() {
    int data[4] = {2, 2, 2, 2};
    int ruma = 0;
    int input;
    bool done = false;

    while (!done) {
        printf("%d %d %d %d | %d\n", data[0], data[1], data[2], data[3], ruma);
        printf("Choose a section (1-4): ");
        while(scanf("%d", &input) != 1 || input < 1 || input > 4 || data[input - 1] == 0) {
            printf("Invalid choice. Choose a section (1-4): ");
            while(getchar() != '\n');
        }
        int currVal = input - 1;
        int total = data[currVal];
        data[currVal] = 0;

        while(total > 0) {
            currVal = (currVal + 1) % 5; 
            if (currVal == 4) { 
                ruma++;
            } else {
                data[currVal]++;
            }
            total--;
            if (total == 0) {
                if (currVal == 4) {
                    break;
                } else if (data[currVal] > 1) { 
                    printf("%d %d %d %d | %d\n", data[0], data[1], data[2], data[3], ruma);
                    printf("Last piece landed in section %d. Continue sowing seeds!\n", currVal + 1);
                    total = data[currVal];
                    data[currVal] = 0;
                } else if (data[currVal] == 1 && currVal != 4) {
                    printf("%d %d %d %d | %d\n", data[0], data[1], data[2], data[3], ruma);
                    printf("You lost because the last counter fell into section %d.\n", currVal + 1);
                    done = true;
                }
            }
        }
        if (!done && data[0] == 0 && data[1] == 0 && data[2] == 0 && data[3] == 0 && ruma > 0) {
            printf("You won!\n");
            done = true;
        }
    }
    return 0;
}

