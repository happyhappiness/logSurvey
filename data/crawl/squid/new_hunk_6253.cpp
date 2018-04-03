    r->handler = handler;
    r->data = data;
    cbdataLock(r->data);
    if ((fqdn = fqdncache_gethostbyaddr(r->client_addr, 0)) == NULL)
	fqdn = dash_str;
    snprintf(buf, 8192, "%s %s/%s %s %s\n",
	r->orig_url,
	inet_ntoa(r->client_addr),
	fqdn,
	r->client_ident,
	r->method_s);
    helperSubmit(redirectors, buf, redirectHandleReply, r);
}

void
redirectInit(void)
{
    static int init = 0;
    safe_free(redirectors);
    if (!Config.Program.redirect)
	return;
    redirectors = xcalloc(1, sizeof(*redirectors));
    redirectors->id_name = "redirector";
    wordlistAdd(&redirectors->cmdline, Config.Program.redirect);
    redirectors->n_to_start = Config.redirectChildren;
    redirectors->ipc_type = IPC_TCP_SOCKET;
    helperOpenServers(redirectors);
    if (!init) {
	cachemgrRegister("redirector",
	    "URL Redirector Stats",
	    redirectStats, 0, 1);
    }
    init++;
}

void
redirectShutdown(void)
{
    if (!redirectors)
	return;
    helperShutdown(redirectors);
    wordlistDestroy(&redirectors->cmdline);
}
