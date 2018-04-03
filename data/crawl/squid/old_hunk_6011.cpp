    }
    if (aclPurgeMethodInUse(Config.accessList.http))
	Config2.onoff.enable_purge = 1;
}

/* Parse a time specification from the config file.  Store the
