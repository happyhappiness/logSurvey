            fatalf("Can't parse configuration token: '%s'\n", def);
        }

        if (*cur == ' ') {
            space = true;
            ++cur;