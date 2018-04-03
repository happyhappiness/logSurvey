               {"negotiate", negotiate_parms, 1}
             };

    for (unsigned scheme=0; scheme < 4; scheme++)
        setup_scheme(getConfig(params[scheme].name), params[scheme].params, params[scheme].paramlength);

    authenticateInit(&config);

