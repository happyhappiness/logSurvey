AuthConfig *
getConfig(char const *type_str)
{
    Auth::authConfig &config = Auth::TheConfig;
    /* find a configuration for the scheme */
    AuthConfig *scheme = AuthConfig::Find(type_str);

    if (scheme == NULL) {
        /* Create a configuration */
        AuthScheme::Pointer theScheme = AuthScheme::Find(type_str);

        if (theScheme == NULL) {
            return NULL;
            //fatalf("Unknown authentication scheme '%s'.\n", type_str);
        }

        config.push_back(theScheme->createConfig());
        scheme = config.back();
        assert(scheme);
    }

    return scheme;
