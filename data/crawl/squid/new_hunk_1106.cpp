
    while (fgets(buf, 256, stdin) != NULL) {
        if ((p = strchr(buf, '\n')) != NULL)
            *p = '\0';      /* strip \n */

        if ((user = strtok(buf, " ")) == NULL) {
            printf("ERR\n");
