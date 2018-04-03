    else
        visible_appname_string = (char const *)APP_FULLNAME;

    if (Config.Program.redirect) {
        if (Config.redirectChildren.n_max < 1) {
            Config.redirectChildren.n_max = 0;
