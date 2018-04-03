    if ((pwd = getpwnam(getEffectiveUser())) == NULL)
	return;
    /* change current directory to swap space so we can get core */
    if (chdir(swappath(0))) {
	debug(21, 1, "Chdir Failed: Cached cannot write core file when it crash: %s\n",
	    xstrerror());
    }
    if (getEffectiveGroup() && (grp = getgrnam(getEffectiveGroup()))) {
	setgid(grp->gr_gid);
