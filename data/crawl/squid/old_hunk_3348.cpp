AuthConfig *
getConfig(char const *type_str)
{
    Vector<AuthConfig *> &config = Config.authConfiguration;
    /* find a configuration for the scheme */
    AuthConfig *scheme = AuthConfig::Find (type_str);

    if (scheme == NULL) {
        /* Create a configuration */
        AuthScheme *theScheme;

        if ((theScheme = AuthScheme::Find(type_str)) == NULL) {
            return NULL;
            //fatalf("Unknown authentication scheme '%s'.\n", type_str);
        }

        config.push_back(theScheme->createConfig());
        scheme = config.back();
        assert (scheme);
    }

    return scheme;
