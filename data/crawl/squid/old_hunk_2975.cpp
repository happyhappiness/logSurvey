        fputs(cbuf, stderr);
        memset(dbuf, '\0', strlen(dbuf));
    } else {
        /* FAIL */
        snprintf(dbuf, sz, "%s: local_debug(%s) FAILURE: %zd\n", prog, dbuf, x);
        fputs(dbuf, stderr);
    }
}

/* local_debugx() -
 *
 * Print formatted message to stderr if EDUI_MODE_DEBUG is set, without preformatting.
 *
 */
void local_debugx(const char *msg,...)
{
    char prog[EDUI_MAXLEN], dbuf[EDUI_MAXLEN];
    size_t sz, x;
    va_list ap;
    if (!(edui_conf.mode & EDUI_MODE_DEBUG))
        return;

    if (edui_conf.program[0] == '\0')
        strcpy(prog, EDUI_PROGRAM_NAME);
    else
        strncpy(prog, edui_conf.program, sizeof(prog));
    if ((msg == NULL) || (strlen(prog) > 256)) {
        /* FAIL */
        snprintf(dbuf, sizeof(dbuf), "%s: local_debugx() EPIC FAILURE.\n", prog);
        fputs(dbuf, stderr);
        return;
