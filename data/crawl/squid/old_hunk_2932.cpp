{
    fprintf(fp, "\tif (!strcmp(token, \"%s\")) {\n", name);

    if (strcmp(entry->loc, "none") == 0) {
        fprintf(fp,
                "\t\tparse_%s();\n",
                entry->type
