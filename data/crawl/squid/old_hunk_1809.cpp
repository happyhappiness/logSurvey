        fprintf(stderr, "Invalid config line: %s\n", s);
        return false;
    }
    // Keep the initial value on cfgparam. The ConfigParser  methods will write on cfgline
    strcpy(cfgparam, tmp+1);

    // Initialize parser to point to the start of quoted string
    strtok(cfgline, w_space);
