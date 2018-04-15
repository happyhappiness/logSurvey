	return (0);
}

static int log_create_file (char *filename, char **ds_def, int ds_num)
{
	FILE *log;
	int i;

	if (check_create_dir (filename))
		return (-1);

	log = fopen (filename, "w");
	if (log == NULL)
	{
		syslog (LOG_WARNING, "Failed to create %s: %s", filename,
				strerror(errno));
		return (-1);
	}

	fprintf (log, "epoch");
	for (i = 0; i < ds_num; i++)
	{
		char *name;
		char *tmp;

		name = strchr (ds_def[i], ':');
		if (name == NULL)
		{
			syslog (LOG_WARNING, "Invalid DS definition '%s' for %s",
					ds_def[i], filename);
			fclose(log);
			remove(filename);
			return (-1);
		}

		name += 1;
		tmp = strchr (name, ':');
		if (tmp == NULL)
		{
			syslog (LOG_WARNING, "Invalid DS definition '%s' for %s",
					ds_def[i], filename);
			fclose(log);
			remove(filename);
			return (-1);
		}

		/* The `%.*s' is needed because there is no null-byte behind
		 * the name. */
		fprintf(log, ",%.*s", (int) (tmp - name), name);
	}
	fprintf(log, "\n");
	fclose(log);

	return 0;
}

int log_update_file (char *host, char *file, char *values,
		char **ds_def, int ds_num)
{
	char *tmp;
	FILE *fp;
	struct stat statbuf;
	char full_file[1024];

	/* Cook the values a bit: Substitute colons with commas */
	strsubstitute (values, ':', ',');

	/* host == NULL => local mode */
	if (host != NULL)
	{
		if (snprintf (full_file, 1024, "%s/%s", host, file) >= 1024)
			return (-1);
	}
	else
	{
		if (snprintf (full_file, 1024, "%s", file) >= 1024)
			return (-1);
	}

	strncpy (full_file, file, 1024);

	tmp = full_file + strlen (full_file) - 4;
	assert ((tmp != NULL) && (tmp > full_file));

	/* Change the filename for logfiles. */
	if (strncmp (tmp, ".rrd", 4) == 0)
	{
		time_t now;
		struct tm *tm;

		/* TODO: Find a way to minimize the calls to `localtime', since
		 * they are pretty expensive.. */
		now = time (NULL);
		tm = localtime (&now);

		strftime (tmp, 1024 - (tmp - full_file), "-%Y-%m-%d", tm);

		/* `localtime(3)' returns a pointer to static data,
		 * therefore the pointer may not be free'd. */
	}
	else
		DBG ("The filename ends with `%s' which is unexpected.", tmp);

	if (stat (full_file, &statbuf) == -1)
	{
		if (errno == ENOENT)
		{
			if (log_create_file (full_file, ds_def, ds_num))
				return (-1);
		}
		else
		{
			syslog (LOG_ERR, "stat %s: %s", full_file, strerror (errno));
			return (-1);
		}
	}
	else if (!S_ISREG (statbuf.st_mode))
	{
		syslog (LOG_ERR, "stat %s: Not a regular file!", full_file);
		return (-1);
	}


	fp = fopen (full_file, "a");
	if (fp == NULL)
	{
		syslog (LOG_WARNING, "Failed to append to %s: %s", full_file,
				strerror(errno));
		return (-1);
	}
	fprintf(fp, "%s\n", values);
	fclose(fp);

	return (0);
} /* int log_update_file */


#ifdef HAVE_LIBKSTAT
int get_kstat (kstat_t **ksp_ptr, char *module, int instance, char *name)
{
