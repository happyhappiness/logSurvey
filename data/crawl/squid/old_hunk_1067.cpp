    while(ConfigParser::NextKvPair(key, value)) {
        if (strcasecmp(key, "on_timeout") == 0) {
            if (strcasecmp(value, "bypass") == 0)
                Config.onUrlRewriteTimeout.action = toutActBypass;
            else if (strcasecmp(value, "fail") == 0)
                Config.onUrlRewriteTimeout.action = toutActFail;
            else if (strcasecmp(value, "retry") == 0)
                Config.onUrlRewriteTimeout.action = toutActRetry;
            else if (strcasecmp(value, "use_configured_response") == 0) {
                Config.onUrlRewriteTimeout.action = toutActUseConfiguredResponse;
            } else {
                debugs(3, DBG_CRITICAL, "FATAL: unsuported \"on_timeout\"  action:" << value);
                self_destruct();
            }
        } else if (strcasecmp(key, "response") == 0) {
            Config.onUrlRewriteTimeout.response = xstrdup(value);
        } else {
            debugs(3, DBG_CRITICAL, "FATAL: unsuported option " << key);
            self_destruct();
        }
    }

    if (Config.onUrlRewriteTimeout.action == toutActUseConfiguredResponse && !Config.onUrlRewriteTimeout.response) {
        debugs(3, DBG_CRITICAL, "FATAL: Expected 'response=' option after 'on_timeout=use_configured_response' option");
        self_destruct();
    }

    if (Config.onUrlRewriteTimeout.action != toutActUseConfiguredResponse && Config.onUrlRewriteTimeout.response) {
        debugs(3, DBG_CRITICAL, "FATAL: 'response=' option is valid only when used with the  'on_timeout=use_configured_response' option");
        self_destruct();
    }
}

static void
dump_url_rewrite_timeout(StoreEntry *entry, const char *name, SquidConfig &config)
{
    const char  *onTimedOutActions[] = {"bypass", "fail", "retry", "use_configured_response"};
    assert(Config.onUrlRewriteTimeout.action >= 0 && Config.onUrlRewriteTimeout.action <= toutActUseConfiguredResponse);

    dump_time_t(entry, name, Config.Timeout.urlRewrite);
    storeAppendPrintf(entry, " on_timeout=%s", onTimedOutActions[Config.onUrlRewriteTimeout.action]);

    if (Config.onUrlRewriteTimeout.response)
        storeAppendPrintf(entry, " response=\"%s\"", Config.onUrlRewriteTimeout.response);

    storeAppendPrintf(entry, "\n");
}

static void
free_url_rewrite_timeout(SquidConfig *config)
{
    Config.Timeout.urlRewrite = 0;
    Config.onUrlRewriteTimeout.action = 0;
    xfree(Config.onUrlRewriteTimeout.response);
    Config.onUrlRewriteTimeout.response = NULL;
}

static void
parse_configuration_includes_quoted_values(bool *recognizeQuotedValues)
{
    int val = 0;
    parse_onoff(&val);
