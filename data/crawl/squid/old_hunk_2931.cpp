        if (!strcmp(entry->name, "comment"))
            continue;

        if (entry->loc == NULL) {
            fprintf(stderr, "NO LOCATION FOR %s\n", entry->name);
            rc |= 1;
