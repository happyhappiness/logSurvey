	fatal("Cannot open HTTP Port");
}

int
handleConnectionHeader(int flag, char *where, char *what)
{
    char *t, *p, *wh;
