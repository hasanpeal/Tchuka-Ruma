
#include <stdio.h>
#include <stdbool.h>

int main() {
    int data[4] = {2, 2, 2, 2};
    int ruma = 0;
    int input;
    bool done = false;

    while (!done) {
        // Print the current state of the game
        printf("%d %d %d %d | %d\n", data[0], data[1], data[2], data[3], ruma);

        // Prompt the user for input
        printf("Choose a section (1-4): ");
        while(scanf("%d", &input) != 1 || input < 1 || input > 4 || data[input - 1] == 0) {
            printf("Invalid choice. Choose a section (1-4): ");
            while(getchar() != '\n'); // Clear the input buffer
        }

        // Sow the seeds
        int currVal = input - 1;
        int total = data[currVal];
        data[currVal] = 0;

        while(total > 0) {
            currVal = (currVal + 1) % 5; // Move to the next section or Ruma
            if (currVal == 4) { // If it's Ruma
                ruma++;
            } else {
                data[currVal]++;
            }
            total--;

            // Continue sowing seeds if last piece lands in a non-empty section
            if (total == 0) {
                if (currVal == 4) { // Last piece in Ruma
                    break; // Player takes another turn
                } else if (data[currVal] > 1) { // Last piece in a section with counters
                    printf("Last piece landed in section %d. Continue sowing seeds!\n", currVal + 1);
                    total = data[currVal];
                    data[currVal] = 0;
                } else if (data[currVal] == 1 && currVal != 4) { // Last piece in an empty section
                    printf("%d %d %d %d | %d\n", data[0], data[1], data[2], data[3], ruma);
                    printf("You lost because the last counter fell into section %d.\n", currVal + 1);
                    done = true;
                }
            }
        }

        // Check for win condition
        if (!done && data[0] == 0 && data[1] == 0 && data[2] == 0 && data[3] == 0 && ruma > 0) {
            printf("You won!\n");
            done = true;
        }
    }

    return 0;
}