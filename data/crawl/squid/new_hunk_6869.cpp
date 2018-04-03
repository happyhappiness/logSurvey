	ConfigFile = xstrdup(DefaultConfigFile);
    parseConfigFile(ConfigFile);

    setEffectiveUser();
    assert(Config.Port.http);
    if (httpPortNumOverride != 1)
	Config.Port.http->i = (u_short) httpPortNumOverride;
