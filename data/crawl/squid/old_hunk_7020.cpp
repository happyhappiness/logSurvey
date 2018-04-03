	Config.appendDomainLen = 0;
    safe_free(debug_options)
	debug_options = xstrdup(Config.debugOptions);
}

/* Parse a time specification from the config file.  Store the
