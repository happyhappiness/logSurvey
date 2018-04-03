	Config.singleParentBypass = 1;
}

static void parseDebugOptionsLine(line_in)
     char *line_in;
{
    char *token;
    token = strtok(NULL, "");	/* Note "", don't separate these */
    safe_free(Config.debugOptions);
    if (token == (char *) NULL) {
	Config.debugOptions = NULL;
	return;
    }
    Config.debugOptions = xstrdup(token);
}

int parseConfigFile(file_name)
     char *file_name;
{
    FILE *fp = NULL;
    char *token = NULL;
    static char tmp_line[BUFSIZ];
    static char line_in[BUFSIZ];
    static char fatal_str[4096];

    /* Initialize a few global strings, in case they aren't user defined */

    configSetFactoryDefaults();

    if ((fp = fopen(file_name, "r")) == NULL) {
	sprintf(fatal_str, "Unable to open configuration file: %s", file_name);
	fatal(fatal_str);
    }
