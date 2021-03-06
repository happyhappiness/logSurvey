        case 'r':
            norealm = 1;
            break;
        case 'k':
#if HAVE_SYS_STAT_H
            struct stat fstat;
            char *ktp;
#endif
	    if (optarg)
                keytab_name = xstrdup(optarg);
	    else {
                fprintf(stderr, "ERROR: keytab file not given\n");
		exit(1);
	    }
            /*
             * Some sanity checks
             */
#if HAVE_SYS_STAT_H
            if ((ktp=strchr(keytab_name,':')))
                ktp++;
            else
                ktp=keytab_name;
            if (stat((const char*)ktp, &fstat)) {
                if (ENOENT == errno)
                    fprintf(stderr, "ERROR: keytab file %s does not exist\n",keytab_name);
                else
                    fprintf(stderr, "ERROR: Error %s during stat of keytab file %s\n",strerror(errno),keytab_name);
                exit(1);
            } else if (!S_ISREG(fstat.st_mode)) {
                fprintf(stderr, "ERROR: keytab file %s is not a file\n",keytab_name);
                exit(1);
            }
#endif
#if HAVE_UNISTD_H
            if (access(ktp, R_OK)) {
                fprintf(stderr, "ERROR: keytab file %s is not accessible\n",keytab_name);
                exit(1);
            }
#endif
            break;
        case 'c':
#if HAVE_SYS_STAT_H
            struct stat dstat;
#endif
	    if (optarg)
                rcache_dir = xstrdup(optarg);
	    else {
                fprintf(stderr, "ERROR: replay cache directory not given\n");
		exit(1);
	    }
            /*
             * Some sanity checks
             */
#if HAVE_SYS_STAT_H
            if (stat((const char*)rcache_dir, &dstat)) {
                if (ENOENT == errno)
                    fprintf(stderr, "ERROR: replay cache directory %s does not exist\n",rcache_dir);
                else
                    fprintf(stderr, "ERROR: Error %s during stat of replay cache directory %s\n",strerror(errno),rcache_dir);
                exit(1);
            } else if (!S_ISDIR(dstat.st_mode)) {
                fprintf(stderr, "ERROR: replay cache directory %s is not a directory\n",rcache_dir);
                exit(1);
            }
#endif
#if HAVE_UNISTD_H
            if (access(rcache_dir, W_OK)) {
                fprintf(stderr, "ERROR: replay cache directory %s is not accessible\n",rcache_dir);
                exit(1);
            }
#endif
            break;
        case 't':
	    if (optarg)
                rcache_type = xstrdup(optarg);
	    else {
                fprintf(stderr, "ERROR: replay cache type not given\n");
		exit(1);
	    }
            break;
        case 's':
	    if (optarg)
                service_principal = xstrdup(optarg);
	    else {
                fprintf(stderr, "ERROR: service principal not given\n");
		exit(1);
	    }
            break;
        default:
            fprintf(stderr, "Usage: \n");
            fprintf(stderr, "squid_kerb_auth [-d] [-i] [-s SPN] [-k keytab] [-c rcdir] [-t rctype]\n");
            fprintf(stderr, "-d full debug\n");
            fprintf(stderr, "-i informational messages\n");
            fprintf(stderr, "-r remove realm from username\n");
            fprintf(stderr, "-s service principal name\n");
            fprintf(stderr, "-k keytab name\n");
            fprintf(stderr, "-c replay cache directory\n");
            fprintf(stderr, "-t replay cache type\n");
            fprintf(stderr,
                    "The SPN can be set to GSS_C_NO_NAME to allow any entry from keytab\n");
            fprintf(stderr, "default SPN is HTTP/fqdn@DEFAULT_REALM\n");
            exit(0);
        }
    }

    debug((char *) "%s| %s: INFO: Starting version %s\n", LogTime(), PROGRAM, SQUID_KERB_AUTH_VERSION);
    if (service_principal && strcasecmp(service_principal, "GSS_C_NO_NAME")) {
        if (!strstr(service_principal,"HTTP/")) {
            debug((char *) "%s| %s: WARN: service_principal %s does not start with HTTP/\n",
                  LogTime(), PROGRAM, service_principal);
        }
        service.value = service_principal;
        service.length = strlen((char *) service.value);
    } else {
