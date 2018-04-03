    else
        visible_appname_string = (char const *)APP_FULLNAME;

#if USE_DNSSERVERS

    if (Config.dnsChildren.n_max < 1)
        fatal("No dnsservers allocated");

#endif

    if (Config.Program.redirect) {
