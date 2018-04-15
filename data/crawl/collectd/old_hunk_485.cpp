		return (-1);
	}

	DBG ("rrd_update (%s, %s, %s)", argv[0], argv[1], argv[2]);

	optind = 0; /* bug in librrd? */
	rrd_clear_error ();
	if (rrd_update (3, argv) == -1)
	{
		syslog (LOG_WARNING, "rrd_update failed: %s: %s",
				filename, rrd_get_error ());
		return (-1);
	}
	return (0);
} /* int rrd_update_file */

void module_register (void)
{
	plugin_register_write ("rrdtool", rrd_write);
}