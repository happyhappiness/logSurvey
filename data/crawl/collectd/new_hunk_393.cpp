	return (root);
} /* oconfig_item_t *cf_read_file */

static oconfig_item_t *cf_read_dir (const char *dir, int depth)
{
	oconfig_item_t *root = NULL;
	DIR *dh;
	struct dirent *de;
	char name[1024];
	int status;

	assert (depth < CF_MAX_DEPTH);

	dh = opendir (dir);
	if (dh == NULL)
	{
		char errbuf[1024];
		ERROR ("configfile: opendir failed: %s",
				sstrerror (errno, errbuf, sizeof (errbuf)));
		return (NULL);
	}

	root = (oconfig_item_t *) malloc (sizeof (oconfig_item_t));
	if (root == NULL)
	{
		ERROR ("configfile: malloc failed.");
		return (NULL);
	}
	memset (root, '\0', sizeof (oconfig_item_t));

	while ((de = readdir (dh)) != NULL)
	{
		oconfig_item_t *temp;

		if ((de->d_name[0] == '.') || (de->d_name[0] == '\0'))
			continue;

		status = snprintf (name, sizeof (name), "%s/%s",
				dir, de->d_name);
		if (status >= sizeof (name))
		{
			ERROR ("configfile: Not including `%s/%s' because its"
					" name is too long.",
					dir, de->d_name);
			continue;
		}

		temp = cf_read_generic (name, depth);
		if (temp == NULL)
			continue;

		cf_ci_append_children (root, temp);
		sfree (temp->children);
		sfree (temp);
	}

	return (root);
} /* oconfig_item_t *cf_read_dir */

/* 
 * cf_read_generic
 *
 * Path is stat'ed and either cf_read_file or cf_read_dir is called
 * accordingly.
 */
static oconfig_item_t *cf_read_generic (const char *path, int depth)
{
	struct stat statbuf;
	int status;

	if (depth >= CF_MAX_DEPTH)
	{
		ERROR ("configfile: Not including `%s' because the maximum "
				"nesting depth has been reached.", path);
		return (NULL);
	}

	fprintf (stderr, "cf_read_generic (path = %s, depth = %i);", path, depth);

	status = stat (path, &statbuf);
	if (status != 0)
	{
		char errbuf[1024];
		ERROR ("configfile: stat (%s) failed: %s",
				path,
				sstrerror (errno, errbuf, sizeof (errbuf)));
		return (NULL);
	}

	if (S_ISREG (statbuf.st_mode))
		return (cf_read_file (path, depth));
	else if (S_ISDIR (statbuf.st_mode))
		return (cf_read_dir (path, depth));

	ERROR ("configfile: %s is neither a file nor a directory.", path);
	return (NULL);
} /* oconfig_item_t *cf_read_generic */

/* 
 * Public functions
 */
