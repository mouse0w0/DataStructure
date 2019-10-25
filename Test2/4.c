#include <stdio.h>
#include <stdlib.h>

#define DOWN 1
#define RIGHT 2
#define UP 3
#define LEFT 4

typedef enum {
    false = 0, true = 1
} bool;
typedef struct {
    int x;
    int y;
    int direction;
} ElementType;
typedef struct {
    ElementType *array;
    int size;
    int top;
} Stack;
typedef Stack *PStack;

PStack InitStack(int size);

bool IsEmpty(PStack stack);

bool IsFull(PStack stack);

bool Push(PStack stack, ElementType value);

bool Pop(PStack stack, ElementType *value);

//int Maze[10][10] = {
//        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//        {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
//        {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
//        {1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
//        {1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
//        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
//        {1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
//        {1, 0, 1, 1, 1, 1, 0, 0, 1, 1},
//        {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
//        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
//};

int width, height;
int *maze;

int get(int x, int y) {
    return maze[x + y * width];
}

void set(int x, int y, int value) {
    maze[x + y * width] = value;
}

int main() {
    scanf("%d %d", &width, &height);
    width += 2;
    height += 2;
    int i, j;
    maze = malloc(width * height * sizeof(int));
    for (i = 0; i < width; i++) {
        maze[i] = 1;
        maze[(height - 1) * width + i] = 1;
    }
    for (i = 0; i < height; i++) {
        maze[i * width] = 1;
        maze[i * width + width - 1] = 1;
    }
    for (i = 1; i < height - 1; i++) {
        for (j = 1; j < width - 1; j++) {
            scanf("%d", maze + i * width + j);
        }
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", maze[i * width + j] == 1 ? '#' : ' ');
        }
        printf("\n");
    }

    int startX, startY;
    int endX, endY;
    scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

    PStack path = InitStack(100);
    ElementType position;
    position.x = startX;
    position.y = startY;
    while (position.x != endX || position.y != endY) {
        if (get(position.x, position.y + 1) == 0) {
            set(position.x, position.y + 1, 2);
            position.direction = DOWN;
            Push(path, position);
            position.y += 1;
        } else if (get(position.x + 1, position.y) == 0) {
            set(position.x + 1, position.y, 2);
            position.direction = RIGHT;
            Push(path, position);
            position.x += 1;
        } else if (get(position.x, position.y - 1) == 0) {
            set(position.x, position.y - 1, 2);
            position.direction = UP;
            Push(path, position);
            position.y -= 1;
        } else if (get(position.x - 1, position.y) == 0) {
            set(position.x - 1, position.y, 2);
            position.direction = LEFT;
            Push(path, position);
            position.x -= 1;
        } else {
            Pop(path, &position);
        }
    }

    printf("Result:\n");
    for (i = 0; i <= path->top; i++) {
        ElementType pathPos = path->array[i];
//        printf("%d %d %d\n", pathPos.x, pathPos.y, pathPos.direction);
        set(pathPos.x, pathPos.y, pathPos.direction + 3);
    }
    set(endX, endY, 3);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            char c;
            switch (maze[i * width + j]) {
                case 1:
                    c = '#';
                    break;
                case 3:
                    c = 'A';
                    break;
                case 4:
                case 6:
                    c = '|';
                    break;
                case 5:
                case 7:
                    c = '-';
                    break;
                default:
                    c = ' ';
                    break;
            }
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}

PStack InitStack(int size) {
    PStack stack = malloc(sizeof(Stack));
    stack->size = size;
    stack->array = malloc(size * sizeof(ElementType));
    stack->top = -1;
    return stack;
}

bool IsEmpty(PStack stack) {
    return stack->top == -1;
}

bool IsFull(PStack stack) {
    return stack->top == stack->size - 1;
}

bool Push(PStack stack, ElementType value) {
    if (IsFull(stack)) {
        return false;
    }

    stack->top++;
    stack->array[stack->top] = value;
    return true;
}

bool Pop(PStack stack, ElementType *value) {
    if (IsEmpty(stack))
        return false;

    *value = stack->array[stack->top];
    stack->top--;
    return true;
}

