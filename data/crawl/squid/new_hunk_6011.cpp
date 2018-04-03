    }
    if (aclPurgeMethodInUse(Config.accessList.http))
	Config2.onoff.enable_purge = 1;
    if (NULL != Config.effectiveUser) {
	struct passwd *pwd = getpwnam(Config.effectiveUser);
	if (NULL == pwd)
	    /*
	     * Andres Kroonmaa <andre@online.ee>:
	     * Some getpwnam() implementations (Solaris?) require
	     * an available FD < 256 for opening a FILE* to the
	     * passwd file.
	     * DW:
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
	if (NULL == grp)
	    fatalf("getgrnam failed to find groupid for effective group '%s'",
		Config.effectiveGroup,
		xstrerror());
	Config2.effectiveGroupID = grp->gr_gid;
    }
}

/* Parse a time specification from the config file.  Store the
