#include <stdio.h>
#include<conio.h>
#define MAX 5 

int stack[MAX];
int top = -1;  
int isFull() {
    return top == MAX - 1;
}
int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
        printf("%d pushed onto the stack\n", value);
    }
}
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}
int main() {
    int choice, value;
    
    while (1) {
        // Display menu for the user
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Stack is full! Cannot push.\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(value);
                }
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("%d popped from the stack\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is %d\n", value);
                }
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    getch();
}
