main(int argc, char **argv)
{
    int auth = 0;
    char buf[256];
    char *user, *passwd, *p;

    setbuf(stdout, NULL);
    while (fgets(buf, 256, stdin) != NULL) {

        if ((p = strchr(buf, '\n')) != NULL)
            *p = '\0';		/* strip \n */

        if ((user = strtok(buf, " ")) == NULL) {
            printf(ERR);
            continue;
        }
        if ((passwd = strtok(NULL, "")) == NULL) {
            printf(ERR);
            continue;
        }
        rfc1738_unescape(user);
