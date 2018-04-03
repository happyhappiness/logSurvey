        return;
    }

    if (!*pm)
        *pm = new HeaderManglers;
    HeaderManglers *manglers = *pm;
    header_mangler *mangler = manglers->track(t);
    assert(mangler);
    parse_acl_access(&mangler->access_list);
}

static void
free_HeaderManglers(HeaderManglers **pm)
{
    // we delete the entire http_header_* mangler configuration at once
    if (const HeaderManglers *manglers = *pm) {
        delete manglers;
        *pm = NULL;
    }
}

static void
dump_http_header_replace(StoreEntry * entry, const char *name, const HeaderManglers *manglers)
{
    if (manglers)
        manglers->dumpReplacement(entry, name);
}

static void
parse_http_header_replace(HeaderManglers **pm)
{
    char *t = NULL;

    if ((t = strtok(NULL, w_space)) == NULL) {
