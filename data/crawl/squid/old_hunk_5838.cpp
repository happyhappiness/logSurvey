		    exit(1);
		}
		break;
	default:
		fprintf(stderr, "squid_ldap_auth: ERROR: Unknown command line option '%c'\n", option);
		exit(1);
	}
    }
	
    if (argc != 2) {
	fprintf(stderr, "Usage: squid_ldap_auth [-b basedn] [-s searchscope] [-f searchfilter] ldap_server_name\n");
	exit(1);
    }
    ldapServer = (char *) argv[1];

    while (fgets(buf, 256, stdin) != NULL) {
	/* You can put this ldap connect outside the loop, but i didn't want to 
	 * have the connection open too much. If you have a site which will 
	 * be doing >1 authentication per second, you should move this (and the 
	 * below ldap_unbind()) outside the loop. 
	 */
	if ((ld = ldap_init(ldapServer, LDAP_PORT)) == NULL) {
	    fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
		ldapServer, LDAP_PORT);
	    exit(1);
	}
	if ((p = strchr(buf, '\n')) != NULL)
	    *p = '\0';		/* strip \n */

	if ((user = strtok(buf, " ")) == NULL) {
	    printf("ERR\n");
	    continue;
	}
	if ((passwd = strtok(NULL, "")) == NULL) {
	    printf("ERR\n");
	    continue;
	}
	if (checkLDAP(ld, user, passwd) != 0) {
	    printf("ERR\n");
	    continue;
	} else {
	    printf("OK\n");
	}
	ldap_unbind(ld);
    }
    return 0;
}

int
checkLDAP(LDAP * ld, char *userid, char *password)
{
    char dn[256];
    int result = 1;

    if (searchfilter) {
	char filter[256];
	LDAPMessage *res = NULL;
	LDAPMessage *entry;
	char *searchattr[] = {NULL};
	char *userdn;

	snprintf(filter, sizeof(filter), "%s%s", searchfilter, userid);
	if (ldap_search_s(ld, basedn, searchscope, filter, searchattr, 1, &res) != LDAP_SUCCESS)
	    return 1;
