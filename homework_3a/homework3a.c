#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{

    int i;
    int num1, num2 = 10;
    char c1 = 'A';
    char c2 = 'E';
    float score1 = 12.5;
    char ca[3] = "Hi";

    printf("Address of argc: %p, Value of argc: %d\n", &argc, argc);
    printf("Address of argv: %p, Value of argv: %p\n", &argv, argv);
    printf("Address of num1: %p, Value of num1: %d\n", &num1, num1);
    printf("Address of num2: %p, Value of num2: %d\n", &num2, num2);
    printf("Address of c1: %p, Value of c1: %c\n", &c1, c1);
    printf("Address of c2: %p, Value of c2: %c\n", &c2, c2);
    printf("Address of score1: %p, Value of score1: %f\n", &score1, score1);

    for (i = 0; i < 3; i++) {
        printf("Address of ca[%d]: %p, Value of ca[%d]: %c\n", i, &ca[i], i, ca[i]);
    }

    printf("char byte value: %lu\n", sizeof(char));
    printf("int byte value: %lu\n", sizeof(int));
    printf("float byte value: %lu\n", sizeof(float));

    dummy(num2, c1, ca, score1);

    return 0;
}

void dummy(int x, char y, char* z, float w)
{
    x++;
    y++;
    w = w + 3.1;

    printf("Address of x: %p, Value of x: %d\n", &x, x);
    printf("Address of y: %p, Value of y: %c\n", &y, y);
    printf("Address of z: %p, Value of z: %p\n", &z, z);
    printf("Address of w: %p, Value of w: %f\n", &w, w);

    /* pause here */
}
