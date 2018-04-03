            printf("Service Name: " SQUIDSBUFPH "\n", SQUIDSBUFPRINT(service_name));
            if (strlen(SQUID_BUILD_INFO))
                printf("%s\n",SQUID_BUILD_INFO);
            printf( "configure options: %s\n", SQUID_CONFIGURE_OPTIONS);

#if USE_WIN32_SERVICE