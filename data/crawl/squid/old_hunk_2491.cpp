
    /* Open output x.c file */

    if ((fp = fopen(output_filename, "w")) == NULL) {
        perror(output_filename);
        exit(1);
    }

#if _SQUID_WINDOWS_
    setmode(fileno(fp), O_TEXT);
#endif

    fprintf(fp,
            "/*\n"
            " * Generated automatically from %s by %s\n"
            " *\n"
            " * Abstract: This file contains routines used to configure the\n"
            " *           variables in the squid server.\n"
            " */\n"
            "\n"
            "#include \"config.h\"\n"
            "\n",
            input_filename, argv[0]
           );

    rc = gen_default(entries, fp);

    gen_default_if_none(entries, fp);

    gen_parse(entries, fp);

    gen_dump(entries, fp);

    gen_free(entries, fp);

    fclose(fp);

    /* Open output x.conf file */
    if ((fp = fopen(conf_filename, "w")) == NULL) {
        perror(conf_filename);
        exit(1);
    }

#if _SQUID_WINDOWS_
    setmode(fileno(fp), O_TEXT);
#endif

    gen_conf(entries, fp, 1);

    fclose(fp);

    if ((fp = fopen(conf_filename_short, "w")) == NULL) {
        perror(conf_filename_short);
        exit(1);
    }
#if _SQUID_WINDOWS_
    setmode(fileno(fp), O_TEXT);
#endif
    gen_conf(entries, fp, 0);
    fclose(fp);

    return (rc);
}

static int
gen_default(Entry * head, FILE * fp)
{
    Entry *entry;
    int rc = 0;
    fprintf(fp,
            "static void\n"
            "default_line(const char *s)\n"
            "{\n"
            "\tLOCAL_ARRAY(char, tmp_line, BUFSIZ);\n"
            "\txstrncpy(tmp_line, s, BUFSIZ);\n"
            "\txstrncpy(config_input_line, s, BUFSIZ);\n"
            "\tconfig_lineno++;\n"
            "\tparse_line(tmp_line);\n"
            "}\n"
           );
    fprintf(fp,
            "static void\n"
            "default_all(void)\n"
            "{\n"
            "\tcfg_filename = \"Default Configuration\";\n"
            "\tconfig_lineno = 0;\n"
           );

    for (entry = head; entry != NULL; entry = entry->next) {
        assert(entry->name);
