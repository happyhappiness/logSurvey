	}
	xfree(p);
    }

    debugOpenLog(logfile);

#if HAVE_SYSLOG
    if (syslog_enable)
