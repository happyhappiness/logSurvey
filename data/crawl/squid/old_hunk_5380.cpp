    auth_basic_config *config = static_cast<auth_basic_config *>(scheme->scheme_data);
    wordlist *list = config->authenticate;
    storeAppendPrintf(entry, "%s %s", name, "basic");
    while (list != NULL) {
	storeAppendPrintf(entry, " %s", list->key);
	list = list->next;
    }
    storeAppendPrintf(entry, "\n%s %s realm %s\n%s %s children %d\n%s %s credentialsttl %d seconds\n",
	name, "basic", config->basicAuthRealm,
	name, "basic", config->authenticateChildren,
	name, "basic", (int) config->credentialsTTL);

}

static void
authBasicParse(authScheme * scheme, int n_configured, char *param_str)
{
    if (scheme->scheme_data == NULL) {
	assert(basicConfig == NULL);
	/* this is the first param to be found */
	scheme->scheme_data = xmalloc(sizeof(auth_basic_config));
	memset(scheme->scheme_data, 0, sizeof(auth_basic_config));
	basicConfig = static_cast<auth_basic_config *>(scheme->scheme_data);
	basicConfig->authenticateChildren = 5;
	basicConfig->credentialsTTL = 2 * 60 * 60;	/* two hours */
    }
    basicConfig =  static_cast<auth_basic_config *>(scheme->scheme_data);
    if (strcasecmp(param_str, "program") == 0) {
	if (basicConfig->authenticate)
	    wordlistDestroy(&basicConfig->authenticate);
	parse_wordlist(&basicConfig->authenticate);
	requirePathnameExists("authparam basic program", basicConfig->authenticate->key);
    } else if (strcasecmp(param_str, "children") == 0) {
	parse_int(&basicConfig->authenticateChildren);
    } else if (strcasecmp(param_str, "realm") == 0) {
	parse_eol(&basicConfig->basicAuthRealm);
    } else if (strcasecmp(param_str, "credentialsttl") == 0) {
	parse_time_t(&basicConfig->credentialsTTL);
    } else {
	debug(28, 0) ("unrecognised basic auth scheme parameter '%s'\n", param_str);
    }
}

