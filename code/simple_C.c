#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

short arr[MAX_SIZE];

int count_unique(int size) {
    int i = 0, j = 0, count = 0, is_unique = 1;
    
    while (i < size) {
        is_unique = 1;
        j = 0;
        
        while (j < i) {
            if (arr[i] == arr[j]) goto not_unique;
            j++;
        }
        
        count++;
        goto end_check;
        
    not_unique:
        is_unique = 0;
        
    end_check:
        i++;
    }
    
    return count;
}

int main() {
    int size;
    char input[20];
   
    printf("Enter array size: ");
    if (!fgets(input, sizeof(input), stdin) || sscanf(input, "%d", &size) != 1 || size <= 0 || size > MAX_SIZE) {
        printf("Error: incorrect array size.\n");
        return 1;
    }
    
    printf("Enter array elements:\n");
    int i = 0;
    while (i < size) {
        if (!fgets(input, sizeof(input), stdin) || sscanf(input, "%hd", &arr[i]) != 1) {
            printf("Error: incorrect array element.\n");
            return 1;
        }
        i++;
    }
    
    int unique_count = count_unique(size);
    printf("Number of unique elements: %d\n", unique_count);
    
    return 0;
}