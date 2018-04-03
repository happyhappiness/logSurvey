     redirectStateData *r;
{
    char *buf = NULL;
    redirect->flags |= REDIRECT_FLAG_BUSY;
    redirect->redirectState = r;
    comm_write(redirect->fd,
	xstrdup(buf),
	strlen(buf),
	0,			/* timeout */
	NULL,			/* Handler */
	NULL);			/* Handler-data */
    debug(14, 5, "redirectDispatch: Request sent to Redirector #%d.\n",
	redirect->index + 1);
}


void redirectOpenServers()
{
    char *prg = getRedirectProgram();
    int k;
    int redirectsocket;
    static char fd_note_buf[FD_ASCII_NOTE_SZ];

    /* free old structures if present */
    if (redirect_child_table) {
	for (k = 0; k < NRedirectors; k++)
