{
    redirectStateData *r = NULL;
    redirector_t *redirector = NULL;
    if (!handler)
	fatal_dump("redirectStart: NULL handler");
    if (!icpState)
