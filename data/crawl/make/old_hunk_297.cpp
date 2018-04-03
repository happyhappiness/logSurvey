static void
reEnableAst(void)
{
	lib$enable_ctrl (&oldCtrlMask,0);
}

static int
astYHandler (void)
{
	struct child *c;
	for (c = children; c != 0; c = c->next)
		sys$delprc (&c->pid, 0, 0);
	ctrlYPressed= 1;
	kill (getpid(),SIGQUIT);
	return SS$_NORMAL;
}

static void
tryToSetupYAst(void)
{
	$DESCRIPTOR(inputDsc,"SYS$COMMAND");
	int	status;
	struct {
		short int	status, count;
		int	dvi;
	} iosb;
	unsigned short int loc_chan;

	setupYAstTried++;

	if (chan)
          loc_chan= chan;
	else {
		status= sys$assign(&inputDsc,&loc_chan,0,0);
		if (!(status&SS$_NORMAL)) {
			lib$signal(status);
			return;
		}
	}
	status= sys$qiow (0, loc_chan, IO$_SETMODE|IO$M_CTRLYAST,&iosb,0,0,
                          astYHandler,0,0,0,0,0);
        if (status==SS$_NORMAL)
          	status= iosb.status;
	if (status!=SS$_NORMAL) {
		if (!chan)
			sys$dassgn(loc_chan);
		if (status!=SS$_ILLIOFUNC && status!=SS$_NOPRIV)
			lib$signal(status);
		return;
	}

	/* called from AST handler ? */
	if (setupYAstTried>1)
		return;
	if (atexit(reEnableAst))
		fprintf (stderr,
                         _("-warning, you may have to re-enable CTRL-Y handling from DCL.\n"));
	status= lib$disable_ctrl (&ctrlMask, &oldCtrlMask);
	if (!(status&SS$_NORMAL)) {
		lib$signal(status);
		return;
	}
	if (!chan)
		chan = loc_chan;
}

int
