      logprintf (LOG_NOTQUIET,
		 _("%s: unable to resolve bind address `%s'; disabling bind.\n"),
		 exec_name, opt.bind_address);
      should_bind = 0;
      return 0;
    }

  /* Pick the first address in the list and use it as bind address.
