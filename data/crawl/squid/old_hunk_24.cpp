        case 'v':
            /** \par v
             * Display squid version and build information. Then exit. */
            printf("Squid Cache: Version %s\n" ,version_string);
            printf("Service Name: " SQUIDSBUFPH "\n", SQUIDSBUFPRINT(service_name));
            if (strlen(SQUID_BUILD_INFO))
                printf("%s\n",SQUID_BUILD_INFO);