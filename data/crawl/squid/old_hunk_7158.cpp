}

static void
parseMcastGroupLine(void)
{
    char *token = NULL;
    while ((token = strtok(NULL, w_space)))
	wordlistAdd(&Config.mcast_group_list, token);
}

static void
parseHttpPortLine(void)
{
    char *token;
    int i;
    if (Config.Port.n_http == MAXHTTPPORTS) {
	sprintf(fatal_str, "Limit of %d HTTP Ports exceeded, redefine MAXHTTPPORTS.\n",
	    MAXHTTPPORTS);
	fatal(fatal_str);
    }
    GetInteger(i);
    if (i < 0)
	i = 0;
    Config.Port.http[Config.Port.n_http++] = (u_short) i;
}

static void
parseIcpPortLine(void)
{
    char *token;
    int i;
    GetInteger(i);
    if (i < 0)
	i = 0;
    Config.Port.icp = (u_short) i;
}

static void
parseDebugOptionsLine(void)
{
    char *token;
    token = strtok(NULL, null_string);
    safe_free(Config.debugOptions);
    if (token == NULL) {
	Config.debugOptions = NULL;
	return;
    }
    Config.debugOptions = xstrdup(token);
}

static void
parseVisibleHostnameLine(void)
{
    char *token;
    token = strtok(NULL, w_space);
    safe_free(Config.visibleHostname);
    if (token == NULL)
	self_destruct();
    Config.visibleHostname = xstrdup(token);
}

static void
parseCacheAnnounceLine(void)
{
    char *token;
    int i;
