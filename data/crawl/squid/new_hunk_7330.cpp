{
    redirectStateData *r = NULL;
    redirector_t *redirector = NULL;
    debug(29, 5, "redirectStart: '%s'\n", icpState->url);
    if (!handler)
	fatal_dump("redirectStart: NULL handler");
    if (!icpState)
