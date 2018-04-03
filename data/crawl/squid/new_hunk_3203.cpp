            dom = firstdom;

        if (dom == NULL) {
            SEND_ERR("");
            continue;
        }
        if ((p = popen(shcmd, "w")) == NULL) {
            SEND_ERR("");
            continue;
        }
        (void) fprintf(p, "%s\n", dom->name);
