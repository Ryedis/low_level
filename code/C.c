#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

short arr[MAX_SIZE];

int count_unique(int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            count++;
        }
    }
    return count;
}

int main() {
    int size;
    char input[20];

    printf("Enter array size: ");
    if (!fgets(input, sizeof(input), stdin) || sscanf(input, "%d", &size) != 1 || size <= 0 || size > MAX_SIZE) {
        printf("Error: incorrect array size\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        if (!fgets(input, sizeof(input), stdin) || sscanf(input, "%hd", &arr[i]) != 1) {
            printf("Error: incorrect array element.\n");
            return 1;
        }
    }

    int unique_count = count_unique(size);
    printf("Number of unique elements: %d\n", unique_count);
    
    return 0;
}