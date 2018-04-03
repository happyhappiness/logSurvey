	} else if (strncmp(token, "cipher=", 7) == 0) {
	    safe_free(s->cipher);
	    s->cipher = xstrdup(token + 7);
	} else if (strncmp(token, "clientca=", 9) == 0) {
	    safe_free(s->clientca);
	    s->clientca = xstrdup(token + 9);
	} else if (strncmp(token, "cafile=", 7) == 0) {
	    safe_free(s->cafile);
	    s->cafile = xstrdup(token + 7);
	} else if (strncmp(token, "capath=", 7) == 0) {
	    safe_free(s->capath);
	    s->capath = xstrdup(token + 7);
	} else if (strncmp(token, "sslflags=", 9) == 0) {
	    safe_free(s->sslflags);
	    s->sslflags = xstrdup(token + 9);
	} else {
	    self_destruct();
	}
    }
    while (*head)
	head = &(*head)->next;
    s->sslContext = sslCreateServerContext(s->cert, s->key, s->version, s->cipher, s->options, s->sslflags, s->clientca, s->cafile, s->capath);
    *head = s;
}

static void
dump_https_port_list(StoreEntry * e, const char *n, const https_port_list * s)
{
    while (s) {
	storeAppendPrintf(e, "%s %s:%d",
	    n,
	    inet_ntoa(s->s.sin_addr),
	    ntohs(s->s.sin_port));
	if (s->cert)
	    storeAppendPrintf(e, " cert=%s", s->cert);
	if (s->key)
	    storeAppendPrintf(e, " key=%s", s->cert);
	if (s->version)
	    storeAppendPrintf(e, " version=%d", s->version);
	if (s->options)
	    storeAppendPrintf(e, " options=%s", s->options);
	if (s->cipher)
	    storeAppendPrintf(e, " cipher=%s", s->cipher);
	if (s->cafile)
	    storeAppendPrintf(e, " cafile=%s", s->cafile);
	if (s->capath)
	    storeAppendPrintf(e, " capath=%s", s->capath);
	if (s->sslflags)
	    storeAppendPrintf(e, " sslflags=%s", s->sslflags);
	storeAppendPrintf(e, "\n");
	s = s->next;
    }
