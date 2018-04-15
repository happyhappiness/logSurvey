		char *t = fields[2];
		char *v = strchr (t, ':');
		if (v == NULL)
			return (-1);
		*v = '\0'; v++;

		vl.time = (time_t) atoi (t);
