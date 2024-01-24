#include <stdio.h>
#include <stdbool.h>

int main() {
    int data[4] = {2, 2, 2, 2};
    int end = 0;
    int input;
    bool done = false;
    int count = 0;
    int total;
    int currVal;

    while (!done) {
        printf("%d %d %d %d | %d\n", data[0], data[1], data[2], data[3], end);
        printf("Choose a section (1-4): ");
        fflush(stdout); 
        scanf("%d", &input);
        
        if(input < 1 || input > 4 || data[input - 1] == 0) {
            printf("Invalid choice. Choose a section (1-4): \n");
            fflush(stdout); 
            continue;
        }
        currVal = input-1;
        total = data[input - 1];
        data[input - 1] = 0;
        while(total > 0) {
            if(currVal == 3) { 
                if(total > 1) { 
                    currVal = -1; 
                } else { 
                    end++;
                    total--;
                    if(total == 0 && data[0] == 0 && data[1] == 0 && data[2] == 0 && data[3] == 0) {
                        printf("You won!\n");
                        done = true;
                    }
                    break; 
                }
            }
            else {
                currVal += 1;
                if (currVal > 3) { 
                    currVal = 0;
                }
                data[currVal] += 1;
                total -= 1;

                if(total == 0 && data[currVal] == 1) {
                    printf("You lost because the last counter fell into section %d.\n", currVal + 1);
                    done = true;
                }
                else if(data[currVal] > 1 && total == 0) {
                    printf("Last piece landed in section %d. Continue sowing seeds!\n", currVal + 1);
                    total = data[currVal];
                    data[currVal] = 0;
                }
            }
        }
    }
    return 0;
}
