        AuthConfig *schemeConfig;
        schemeConfig = getConfig(params[scheme].name);
        if (schemeConfig != NULL)
            setup_scheme (schemeConfig, params[scheme].params, 
                params[scheme].paramlength);
		else
            fprintf(stderr,"Skipping unknown authentication scheme '%s'.\n", 
                params[scheme].name);
    }

    authenticateInit(&config);
