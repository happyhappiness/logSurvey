	     * This should be safe at startup, but might still fail
	     * during reconfigure.
	     */
	    fatalf("getpwnam failed to find userid for effective user '%s'",
		Config.effectiveUser,
		xstrerror());
	Config2.effectiveUserID = pwd->pw_uid;
    }
    if (NULL != Config.effectiveGroup) {
	struct group *grp = getgrnam(Config.effectiveGroup);
