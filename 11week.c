#include <stdio.h>
#define _CRT_NO_WARNINGS

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) {
    if (b == 0) {
        printf("0으로 나눌 수 없습니다.\n");
        return 0;
    }
    return a / b;
}

int calc(int a, int b, int (*op)(int, int)) {
    return op(a, b);
}

int main() {
    int menu;
    int a, b;
    int result;
    int (*operations[4])(int, int) = { add, sub, mul, div };

    while (1) {
        printf("\n메뉴를 선택하세요:\n");
        printf("1. 덧셈\n2. 뺄셈\n3. 곱셈\n4. 나눗셈\n0. 종료\n");
        printf("선택: ");
        scanf("%d", &menu);

        if (menu == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        if (menu >= 1 && menu <= 4) {
            printf("두 정수를 입력하세요: ");
            scanf("%d %d", &a, &b);
            result = calc(a, b, operations[menu - 1]);
            printf("결과: %d\n", result);
        }
        else {
            printf("잘못된 메뉴입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}