
    if (authenticateProgram)
        wordlistDestroy(&authenticateProgram);
}

bool
Auth::Basic::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme) const
{
    if (!Auth::Config::dump(entry, name, scheme))
        return false; // not configured

    storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) credentialsTTL);
    storeAppendPrintf(entry, "%s basic casesensitive %s\n", name, casesensitive ? "on" : "off");
    storeAppendPrintf(entry, "%s basic utf8 %s\n", name, utf8 ? "on" : "off");
    return true;
}

Auth::Basic::Config::Config() :
        credentialsTTL( 2*60*60 ),
        casesensitive(0),
        utf8(0)
{
    static const SBuf defaultRealm("Squid proxy-caching web server");
    realm = defaultRealm;
}

void
Auth::Basic::Config::parse(Auth::Config * scheme, int n_configured, char *param_str)
{
    if (strcmp(param_str, "credentialsttl") == 0) {
        parse_time_t(&credentialsTTL);
    } else if (strcmp(param_str, "casesensitive") == 0) {
        parse_onoff(&casesensitive);
