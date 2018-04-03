    FH = fopen(filename, "r");
    if ( FH ) {
        /* the pointer to the first entry in the linked list */
        while ((cp = fgets (line, sizeof(line), FH)) != NULL) {
            if (line[0] == '#') {
                continue;
            }
            if ((cp = strchr (line, '\n')) != NULL) {
                /* chop \n characters */
                *cp = '\0';
            }
            log_debug("read config line \"%s\".\n", line);
            if ((cp = strtok (line, "\t ")) != NULL) {
                username = cp;

                /* get the time budget */
                budget = strtok (NULL, "/");
                period = strtok (NULL, "/");

                parseTime(budget, &budgetSecs, &start);
                parseTime(period, &periodSecs, &start);
