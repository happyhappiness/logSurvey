        case 'm':
            margs.mdepth = atoi(optarg);
            break;
        case 'S':
            margs.llist = xstrdup(optarg);
            break;
        case 'h':
            fprintf(stderr, "Usage: \n");
            fprintf(stderr, "squid_kerb_ldap [-d] [-i] -g group list [-D domain] [-N netbios domain map] [-s] [-u ldap user] [-p ldap user password] [-l ldap url] [-b ldap bind path] [-a] [-m max depth] [-h]\n");
