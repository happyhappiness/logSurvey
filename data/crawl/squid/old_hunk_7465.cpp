	    str[x] = ' ';
}


static void
parse_object(char *string)
{
    char *tmp_line = NULL;
    char *url = NULL;
    char *token = NULL;
    char *store_time = NULL;
    char *last_ref = NULL;
    char *ttl = NULL;
    char *sto = NULL;
    char *status = NULL;
    char *obj_status = NULL;
    char *w_space = " \t\n";
    int obj_size;
    int ref_cnt;

    /* Use tmp_line as a temporary pointer to the input line */
    tmp_line = string;

    /* Parse out the url */
    url = strtok(tmp_line, w_space);

    if (!url)
	return;

#if !ALL_OBJECTS
    if (!strncmp(url, "cache_object", 12))
	return;
    if (!strncmp(url, "POST", 4))
	return;
#endif

    tmp_line = NULL;

    token = strtok(tmp_line, w_space);
    sscanf(token, "%d", &obj_size);

    token = strtok(tmp_line, w_space);
    store_time = xstrdup(token);

    token = strtok(tmp_line, w_space);
    obj_status = xstrdup(token);

    token = strtok(tmp_line, w_space);
    last_ref = xstrdup(token);

    token = strtok(tmp_line, w_space);
    ttl = xstrdup(token);

    token = strtok(tmp_line, w_space);
    /* Active */

    token = strtok(tmp_line, w_space);
    sscanf(token, "%d", &ref_cnt);

    token = strtok(tmp_line, w_space);
    sto = xstrdup(token);

    token = strtok(tmp_line, w_space);
    status = xstrdup(token);

    printf("<LI>Cache: <A HREF=\"%s\">%s</A><BR>",
	url, url);
    printf("Size: %d bytes, TTL: %s ,<BR>",
	obj_size, ttl);
    printf("Stored: %s, %s ago, %s %s,<BR>",
	sto, store_time, obj_status, status);
    printf("Refs: %d, Referenced %s hh:mm:ss ago</LI>\n",
	ref_cnt, last_ref);

    free(ttl);
    free(store_time);
    free(last_ref);
    free(sto);
    free(status);
}

int
