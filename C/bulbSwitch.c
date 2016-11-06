int bulbSwitch(int n) {
    char *bulbs = (char *)malloc(n);
    memset(bulbs, 0, n);
    int i = 1, j;
    while (i <= n) {
        bulbs[0] = 1;
        for (j = 1; j < n; j++) {
            if ((j+1)%i) continue;
            bulbs[j] = !bulbs[j];
        }
        i++;
    }
    for (i = j =0; i < n; ++i) {
        if (bulbs[i]) j++;
    }
    free(bulbs);
    return j;
}

int bulbSwitch2(int n) {
    int i = 1, j, c, x;
    int half;
    x = 0;
    while (i <= n) {
        for (c = 0, j = 2, half = i / 2; j <= half; ++j) {
            c+= !(i % j);
        }
        x += (c & 0x01);
        i++;
    }
    return n ? x + 1: x;
}

int bulbSwitch3(int n) {
    return (int)sqrt(n);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 0;
    }
    printf("%d %d\n", bulbSwitch(atoi(argv[1])), bulbSwitch2(atoi(argv[1])));
    return 0;
}