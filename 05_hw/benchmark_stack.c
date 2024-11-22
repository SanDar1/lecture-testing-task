#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

#define NUM_ELEMENTS 1000000 // Количество элементов для теста

void benchmark_push(Stack* stack) {
    clock_t start = clock();
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        push(stack, i);
    }
    clock_t end = clock();
    printf("Time for push (%d elements): %f seconds\n", NUM_ELEMENTS, (double)(end - start) / CLOCKS_PER_SEC);
}

void benchmark_pop(Stack* stack) {
    clock_t start = clock();
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        pop(stack);
    }
    clock_t end = clock();
    printf("Time for pop (%d elements): %f seconds\n", NUM_ELEMENTS, (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    Stack stack;
    initStack(&stack);

    printf("Running benchmarks...\n");

    // Бенчмарк для push
    benchmark_push(&stack);

    // Бенчмарк для pop
    benchmark_pop(&stack);

    destroyStack(&stack);
    return 0;
}
