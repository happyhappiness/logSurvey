}

static void
dump_announceto(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_announceto(void)
{
    char *token;
    int i;

    token = strtok(NULL, w_space);
    if (token == NULL)
	self_destruct();
    safe_free(Config.Announce.host);
    Config.Announce.host = xstrdup(token);
    if ((token = strchr(Config.Announce.host, ':'))) {
	*token++ = '\0';
	if (sscanf(token, "%d", &i) != 1)
	    Config.Announce.port = i;
    }
    token = strtok(NULL, w_space);
    if (token == NULL)
	return;
    safe_free(Config.Announce.file);
    Config.Announce.file = xstrdup(token);
}

static void
dump_appenddomain(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_appenddomain(void)
{
    char *token = strtok(NULL, w_space);

    if (token == NULL)
	self_destruct();
    if (*token != '.')
	self_destruct();
    safe_free(Config.appendDomain);
    Config.appendDomain = xstrdup(token);
}

static void
dump_cacheannounce(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_cacheannounce(void)
{
    char *token;
    int i;
