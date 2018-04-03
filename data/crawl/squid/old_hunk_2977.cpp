    va_list ap;

    if (edui_conf.program[0] == '\0')
        strcpy(prog, EDUI_PROGRAM_NAME);
    else
        strncpy(prog, edui_conf.program, sizeof(prog));

    if ((msg == NULL) || (strlen(prog) > 256)) {
        /* FAIL */
        snprintf(dbuf, sizeof(dbuf), "%s: local_printfx() EPIC FAILURE.\n", prog);
        fputs(dbuf, stderr);
        return;
    }
    sz = sizeof(dbuf);
