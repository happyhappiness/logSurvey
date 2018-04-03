	loop++;
}

static int init_global_variables (void)
{
	const char *str;

	str = global_option_get ("Hostname");
	if (str != NULL)
	{
		strncpy (hostname_g, str, sizeof (hostname_g));
	}
	else
	{
		if (gethostname (hostname_g, sizeof (hostname_g)) != 0)
		{
			fprintf (stderr, "`gethostname' failed and no "
					"hostname was configured.\n");
			return (-1);
		}
	}
	DBG ("hostname_g = %s;", hostname_g);

	str = global_option_get ("Interval");
	if (str == NULL)
		str = COLLECTD_STEP;
	interval_g = atoi (str);
	if (interval_g <= 0)
	{
		fprintf (stderr, "Cannot set the interval to a correct value.\n"
				"Please check your settings.\n");
		return (-1);
	}
	DBG ("interval_g = %i;", interval_g);

	return (0);
} /* int init_global_variables */

static int change_basedir (const char *orig_dir)
{
	char *dir = strdup (orig_dir);
