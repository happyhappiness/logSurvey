
    storeAppendPrintf(entry, "%s basic credentialsttl %d seconds\n", name, (int) credentialsTTL);
    storeAppendPrintf(entry, "%s basic casesensitive %s\n", name, casesensitive ? "on" : "off");
    return true;
}

Auth::Basic::Config::Config() :
    credentialsTTL( 2*60*60 ),
    casesensitive(0)
{
    static const SBuf defaultRealm("Squid proxy-caching web server");
    realm = defaultRealm;
