	fatal("Cannot open HTTP Port");
}

#if OLD_CODE
static int
handleConnectionHeader(int flag, char *where, char *what)
{
    char *t, *p, *wh;
