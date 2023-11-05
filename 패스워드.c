#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char* WARNINGS[] = {
    "길이는 최소한 8이상이어야 합니다.",
    "최소한 1개 이상의 숫자가 포함되어야 합니다.",
    "최소한 1개 이상의 영어 소문자가 포함되어야 합니다.",
    "최소한 1개 이상의 영어 대문자가 포함되어야 합니다.",
    "최소한 1개 이상의 제시하는 특수 문자(~ ! @ # $ % *)가 포함되어야 합니다."
};
bool hasDigit(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            return true;
        }
    }
    return false;
}bool hasLowerCase(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            return true;
        }
    }
    return false;
}bool hasUpperCase(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            return true;
        }
    }
    return false;
}bool hasSpecialChar(const char* str) {
    const char* specialChars = "~!@#$%*";
    for (int i = 0; str[i]; i++) {
        if (strchr(specialChars, str[i]) != NULL) {
            return true;
        }
    }
    return false;
}int main() {
    char password[100];
    bool valid = false;
    while (!valid) {
        printf("암호를 입력하세요: ");
        scanf("%s", password);
        valid = true;
        if (strlen(password) < 8) {
            valid = false;
            printf("%s\n", WARNINGS[0]);
        }
        if (!hasDigit(password)) {
            valid = false;
            printf("%s\n", WARNINGS[1]);
        }
        if (!hasLowerCase(password)) {
            valid = false;
            printf("%s\n", WARNINGS[2]);
        }
        if (!hasUpperCase(password)) {
            valid = false;
            printf("%s\n", WARNINGS[3]);
        }
        if (!hasSpecialChar(password)) {
            valid = false;
            printf("%s\n", WARNINGS[4]);
        }
        if (!valid) {
            printf("다시 입력하세요.\n");
        }
    }
    printf("입력하신 %s는 강력한 암호입니다.\n", password);
    return 0;
}
