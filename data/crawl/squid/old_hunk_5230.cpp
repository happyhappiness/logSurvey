    return username_quote(name);
}

static void
accessLogSquid(AccessLogEntry * al)
{
    const char *client = NULL;
    const char *user = NULL;
