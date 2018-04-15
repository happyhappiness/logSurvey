	return (0);
}

int log_create_file (char *filename, char **ds_def, int ds_num)
{
	FILE *log;
	int i;

	log = fopen (filename, "w");
	if (log == NULL)
	{
		syslog (LOG_WARNING, "Failed to create %s: %s", filename,
				strerror(errno));
		return (-1);
	}

	for (i = 0; i < ds_num; i++)
	{
		char *name;
		char *tmp;

		name = index (ds_def[i], ':');
		if (name == NULL)
		{
			syslog (LOG_WARNING, "Invalid DS definition '%s' for %s",
					ds_def[i], filename);
			fclose(log);
			remove(filename);
			return (-1);
		}

		name += 1;
		tmp = index(name, ':');
		if (tmp == NULL)
		{
			syslog (LOG_WARNING, "Invalid DS definition '%s' for %s",
					ds_def[i], filename);
			fclose(log);
			remove(filename);
			return (-1);
		}

		if (i != 0)
			fprintf (log, ":");
		fprintf(log, "%.*s", (tmp - name), name);
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
	assert (tmp > 0);

	/* Change the filename for logfiles. */
	if (strncmp (tmp, ".rrd", 4) == 0)
	{
		time_t now;
		struct tm *tm;

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

int rrd_create_file (char *filename, char **ds_def, int ds_num)
{
#ifdef HAVE_LIBRRD
	char **argv;
	int argc;
	int i, j;
