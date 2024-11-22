
#include "stack.h"
#include <assert.h>
#include <stdio.h>

void test_init_destroy_stack() {
    Stack stack;
    initStack(&stack);
    assert(isEmpty(&stack) == true);
    destroyStack(&stack);
}

void test_push_pop() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    assert(getTop(&stack)->data == 10);
    push(&stack, 20);
    assert(getTop(&stack)->data == 20);

    pop(&stack);
    assert(getTop(&stack)->data == 10);
    pop(&stack);
    assert(isEmpty(&stack) == true);

    destroyStack(&stack);
}

void test_search_by_value() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    assert(searchByValue(&stack, 20) != NULL);
    assert(searchByValue(&stack, 40) == NULL);

    destroyStack(&stack);
}

void test_search_by_index() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    assert(searchByIndex(&stack, 0)->data == 30);
    assert(searchByIndex(&stack, 2)->data == 10);
    assert(searchByIndex(&stack, 3) == NULL);

    destroyStack(&stack);
}

void test_traverse_stack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Expected output: 30 20 10\n");
    printf("Actual output: ");
    traverseStack(&stack);

    destroyStack(&stack);
}

int main() {
    printf("Running tests...\n");
    test_init_destroy_stack();
    test_push_pop();
    test_search_by_value();
    test_search_by_index();
    test_traverse_stack();
    printf("All tests passed!\n");
    return 0;
}
