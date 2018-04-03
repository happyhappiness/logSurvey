            dom = firstdom;

        if (dom == NULL) {
            (void) printf("ERR\n");
            continue;
        }
        if ((p = popen(shcmd, "w")) == NULL) {
            (void) printf("ERR\n");
            continue;
        }
        (void) fprintf(p, "%s\n", dom->name);
