	if (setupYAstTried>1)
		return;
	if (atexit(reEnableAst))
		fprintf (stderr, "-warning, you may have to re-enable CTRL-Y"
			"handling from DCL.\n");
	status= lib$disable_ctrl (&ctrlMask, &oldCtrlMask);
	if (!(status&SS$_NORMAL)) {
		lib$signal(status);
