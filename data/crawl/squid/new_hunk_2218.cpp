
#if USE_HTTP_VIOLATIONS
static void
dump_http_header_access(StoreEntry * entry, const char *name, const HeaderManglers *manglers)
{
    if (manglers)
        manglers->dumpAccess(entry, name);
}

static void
parse_http_header_access(HeaderManglers **pm)
{
    char *t = NULL;

    if ((t = strtok(NULL, w_space)) == NULL) {
