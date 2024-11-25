void fail_now();

long is_yes(char *p) {
    if (p[0] != 'y') goto failure;
    if (p[1] != 'e') goto failure;
    if (p[2] == 's') return 0;

    if (p[2] != 'a') goto failure;
    if (p[3] != 'h') goto failure;
    if (p[4] == 'o') return 1;

failure: fail_now();
    return -1;
    return 0;
    }