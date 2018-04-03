#endif

static void
dump_http_header_access(StoreEntry * entry, const char *name, header_mangler header[])
{
    int i;
    storeAppendPrintf(entry, "%s:", name);
    for (i = 0; i < HDR_ENUM_END; i++) {
	if (header[i].access_list != NULL) {
	    storeAppendPrintf(entry, "\t");
	    dump_acl_access(entry, httpHeaderNameById(i),
		header[i].access_list);
	}
    }
}

static void
parse_http_header_access(header_mangler header[])
{
    int id, i;
    char *t = NULL;
    if ((t = strtok(NULL, w_space)) == NULL) {
	debug(3, 0) ("%s line %d: %s\n",
	    cfg_filename, config_lineno, config_input_line);
	debug(3, 0) ("parse_http_header_access: missing header name.\n");
	return;
    }
    /* Now lookup index of header. */
    id = httpHeaderIdByNameDef(t, strlen(t));
    if (strcmp(t, "All") == 0)
	id = HDR_ENUM_END;
    else if (strcmp(t, "Other") == 0)
	id = HDR_OTHER;
    else if (id == -1) {
	debug(3, 0) ("%s line %d: %s\n",
	    cfg_filename, config_lineno, config_input_line);
	debug(3, 0) ("parse_http_header_access: unknown header name %s.\n", t);
	return;
    }
    if (id != HDR_ENUM_END) {
	parse_acl_access(&header[id].access_list);
    } else {
	char *next_string = t + strlen(t);
	*next_string = ' ';
	for (i = 0; i < HDR_ENUM_END; i++) {
	    char *new_string = xstrdup(next_string);
	    strtok(new_string, " ");
	    parse_acl_access(&header[i].access_list);
	    safe_free(new_string);
	}
    }
}

static void
free_http_header_access(header_mangler header[])
{
    int i;
    for (i = 0; i < HDR_ENUM_END; i++) {
	free_acl_access(&header[i].access_list);
    }
}

static void
dump_http_header_replace(StoreEntry * entry, const char *name, header_mangler
    header[])
{
    int i;
    storeAppendPrintf(entry, "%s:", name);
    for (i = 0; i < HDR_ENUM_END; i++) {
	if (NULL == header[i].replacement)
	    continue;
	storeAppendPrintf(entry, "\t%s: %s", httpHeaderNameById(i),
	    header[i].replacement);
    }
}

static void
parse_http_header_replace(header_mangler header[])
{
    int id, i;
    char *t = NULL;
    if ((t = strtok(NULL, w_space)) == NULL) {
	debug(3, 0) ("%s line %d: %s\n",
	    cfg_filename, config_lineno, config_input_line);
	debug(3, 0) ("parse_http_header_replace: missing header name.\n");
	return;
    }
    /* Now lookup index of header. */
    id = httpHeaderIdByNameDef(t, strlen(t));
    if (strcmp(t, "All") == 0)
	id = HDR_ENUM_END;
    else if (strcmp(t, "Other") == 0)
	id = HDR_OTHER;
    else if (id == -1) {
	debug(3, 0) ("%s line %d: %s\n",
	    cfg_filename, config_lineno, config_input_line);
	debug(3, 0) ("parse_http_header_replace: unknown header name %s.\n",
	    t);
	return;
    }
    if (id != HDR_ENUM_END) {
	if (header[id].replacement != NULL)
	    safe_free(header[id].replacement);
	header[id].replacement = xstrdup(t + strlen(t) + 1);
    } else {
	for (i = 0; i < HDR_ENUM_END; i++) {
	    if (header[i].replacement != NULL)
		safe_free(header[i].replacement);
	    header[i].replacement = xstrdup(t + strlen(t) + 1);
	}
    }
}

static void
free_http_header_replace(header_mangler header[])
{
    int i;
    for (i = 0; i < HDR_ENUM_END; i++) {
	if (header[i].replacement != NULL)
	    safe_free(header[i].replacement);
    }
}

static void
