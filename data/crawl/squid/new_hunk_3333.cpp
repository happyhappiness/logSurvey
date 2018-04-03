    storeAppendPrintf(entry, "%s basic casesensitive %s\n", name, casesensitive ? "on" : "off");
}

AuthBasicConfig::AuthBasicConfig() :
        credentialsTTL( 2*60*60 ),
        casesensitive(0),
        utf8(0)
{
    basicAuthRealm = xstrdup("Squid proxy-caching web server");
}

