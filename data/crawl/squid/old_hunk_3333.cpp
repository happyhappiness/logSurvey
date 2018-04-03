    storeAppendPrintf(entry, "%s basic casesensitive %s\n", name, casesensitive ? "on" : "off");
}

AuthBasicConfig::AuthBasicConfig() : authenticateChildren(20)
{
    /* TODO: move into initialisation list */
    credentialsTTL = 2 * 60 * 60;	/* two hours */
    basicAuthRealm = xstrdup("Squid proxy-caching web server");
}

