#endif

static void
dump_http_header(StoreEntry * entry, const char *name, HttpHeaderMask header)
{
    int i;
    for (i = 0; i < HDR_OTHER; i++) {
	if (http_header_allowed && !CBIT_TEST(header, i))
	    storeAppendPrintf(entry, "%s allow %s\n", name, httpHeaderNameById(i));
	else if (!http_header_allowed && CBIT_TEST(header, i))
	    storeAppendPrintf(entry, "%s deny %s\n", name, httpHeaderNameById(i));
    }
}

static void
parse_http_header(HttpHeaderMask * header)
{
    int allowed, id;
    char *t = NULL;
    if ((t = strtok(NULL, w_space)) == NULL) {
	debug(3, 0) ("%s line %d: %s\n",
	    cfg_filename, config_lineno, config_input_line);
	debug(3, 0) ("parse_http_header: missing 'allow' or 'deny'.\n");
	return;
    }
    if (!strcmp(t, "allow"))
	allowed = 1;
    else if (!strcmp(t, "deny"))
	allowed = 0;
    else {
	debug(3, 0) ("%s line %d: %s\n",
	    cfg_filename, config_lineno, config_input_line);
	debug(3, 0) ("parse_http_header: expecting 'allow' or 'deny', got '%s'.\n", t);
	return;
    }
    if (!http_header_first) {
	http_header_first = 1;
	if (allowed) {
	    http_header_allowed = 1;
	    httpHeaderMaskInit(header, 0xFF);
	} else {
	    http_header_allowed = 0;
	    httpHeaderMaskInit(header, 0);
	}
    }
    while ((t = strtok(NULL, w_space))) {
	if ((id = httpHeaderIdByNameDef(t, strlen(t))) == -1)
	    debug(3, 0) ("parse_http_header: Ignoring unknown header '%s'\n", t);
	else if (allowed)
	    CBIT_CLR(*header, id);
	else
	    CBIT_SET(*header, id);
    }
}

static void
free_http_header(HttpHeaderMask * header)
{
    httpHeaderMaskInit(header, 0);
}

static void
