    redirector_t *redirector = NULL;
    if (!handler)
	fatal_dump("redirectStart: NULL handler");
    if (Config.Program.redirect == NULL) {
	(*handler) (data, NULL);
	return;
    }
