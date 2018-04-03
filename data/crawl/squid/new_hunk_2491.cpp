
    /* Open output x.c file */

    std::ofstream fout(output_filename,std::ostream::out);
    if (!fout.good()) {
        perror(output_filename);
        exit(1);
    }

    fout <<  "/*\n" <<
            " * Generated automatically from " << input_filename << " by " <<
            argv[0] << "\n"
            " *\n"
            " * Abstract: This file contains routines used to configure the\n"
            " *           variables in the squid server.\n"
            " */\n"
            "\n"
            "#include \"config.h\"\n"
            "\n";

    rc = gen_default(entries, fout);

    gen_default_if_none(entries, fout);

    gen_parse(entries, fout);

    gen_dump(entries, fout);

    gen_free(entries, fout);

    fout.close();

    /* Open output x.conf file */
    fout.open(conf_filename,std::ostream::out);
    if (!fout.good()) {
        perror(conf_filename);
        exit(1);
    }

    gen_conf(entries, fout, 1);

    fout.close();

    fout.open(conf_filename_short,std::ostream::out);
    if (!fout.good()) {
        perror(conf_filename_short);
        exit(1);
    }
    gen_conf(entries, fout, 0);
    fout.close();

    return (rc);
}

static int
gen_default(Entry * head, std::ostream &fout)
{
    Entry *entry;
    int rc = 0;
    fout << "static void\n"
            "default_line(const char *s)\n"
            "{\n"
            "\tLOCAL_ARRAY(char, tmp_line, BUFSIZ);\n"
            "\txstrncpy(tmp_line, s, BUFSIZ);\n"
            "\txstrncpy(config_input_line, s, BUFSIZ);\n"
            "\tconfig_lineno++;\n"
            "\tparse_line(tmp_line);\n"
            "}\n";
    fout << "static void\n"
            "default_all(void)\n"
            "{\n"
            "\tcfg_filename = \"Default Configuration\";\n"
            "\tconfig_lineno = 0;\n";

    for (entry = head; entry != NULL; entry = entry->next) {
        assert(entry->name);
