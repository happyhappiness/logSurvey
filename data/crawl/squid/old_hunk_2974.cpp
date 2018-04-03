 * Print formatted message of func() to stderr if EDUI_MODE_DEBUG is set.
 *
 */
void local_debug(char *func, const char *msg,...)
{
    char prog[EDUI_MAXLEN], dbuf[EDUI_MAXLEN], cbuf[EDUI_MAXLEN];
    size_t sz, x;
    va_list ap;
    if (!(edui_conf.mode & EDUI_MODE_DEBUG))
        return;

    if (edui_conf.program[0] == '\0')
        strcpy(prog, EDUI_PROGRAM_NAME);
    else
        strncpy(prog, edui_conf.program, sizeof(prog));
    if ((func == NULL) || (msg == NULL) || (strlen(prog) > 256)) {
        /* FAIL */
        snprintf(dbuf, sizeof(dbuf), "%s: local_debug() EPIC FAILURE.\n", prog);
        fputs(dbuf, stderr);
        return;
    }
    sz = sizeof(dbuf);
    strncpy(cbuf, prog, sizeof(cbuf));
    strcat(cbuf, ": [DB] ");
    strncat(cbuf, func, sizeof(cbuf));
    strcat(cbuf, "() - ");
    va_start(ap, msg);
    x = vsnprintf(dbuf, sz, msg, ap);
    va_end(ap);
