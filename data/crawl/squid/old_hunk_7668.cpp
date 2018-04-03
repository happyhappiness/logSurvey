    redirector_t *redirector = NULL;
    if (!handler)
	fatal_dump("redirectStart: NULL handler");
    if (!do_redirect) {
	(*handler) (data, NULL);
	return;
    }
