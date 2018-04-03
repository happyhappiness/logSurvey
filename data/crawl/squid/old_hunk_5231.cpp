                  al->http.content_type);

    safe_free(user);
}

static void
accessLogCommon(AccessLogEntry * al)
{
    const char *client = NULL;
    char *user1 = NULL, *user2 = NULL;
