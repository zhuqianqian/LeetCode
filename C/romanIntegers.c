#include <stdio.h>
#include <string.h>

int map[] = {
    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  100,  500,    0,    0,    0,
    0,    1,    0,    0,   50, 1000,    0,    0,
    0,    0,    0,    0,    0,    0,    5,    0,
   10,    0,    0,    0,    0,    0,    0,    0};

int romanToInt(char* s) {
    int result = 0;
    int last = 0;
    char* next;
    while (*s) {
        next = s + 1;
        if (*next && map[*s] < map[*next]) {
            result += (map[*next] - map[*s]);
            s++;
        }
        else {
            result += map[*s];
        }
        s++;
    }
    return result;
}

char slots[32];
char* intToRoman(int num) {
    char* w = slots;
    int next = 0, t;
    int nums[] = { 1000, 500, 100, 50, 10, 5, 1 };
    int adjs[] = { 900, 400, 90, 40, 9, 4, 0 };
    char *romans = "MDCLXVI";
    while (num) {
        if (num >= nums[next]) {
            *w++ = romans[next];
            num -= nums[next];
        }
        else if (num >= adjs[next]) {
            t = next + 2 - (next & 0x01);
            *w++ = *(romans + t);
            *w++ = *(romans + next);
            num -= adjs[next]; 
            next = t;
        }
        else {
            next++;
        }
    }
    *w = 0;
    return slots;
}

char *help =
"ricvt <option> <value>\nConvert roman and integers.\n"
"option can be: -i: convert integer to roman.\n"
"               -r: convert roman to integer.\n"
"value is the value you want to convert from.\n";

int main(int argc, char** argv) {

    if (argc < 3) {
        printf("%s", help);
        return 0;
    }
    if (!strcmp(argv[1], "-i")) {
        printf("Roman of integer %s is :%s\n", argv[2], intToRoman(atoi(argv[2])));
    }
    else if (!strcmp(argv[1], "-r")) {
        printf("Integer of Roman %s is: %d\n", argv[2], romanToInt(argv[2]));
    }
    return 0;
}