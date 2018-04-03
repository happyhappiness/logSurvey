}

#if HAVE_REGEX_H
static int ignorelist_append_regex(ignorelist_t *il, const char *re_str)
{
	regex_t *re;
	ignorelist_item_t *entry;
	int status;

	re = malloc (sizeof (*re));
	if (re == NULL)
	{
		ERROR ("utils_ignorelist: malloc failed");
		return (ENOMEM);
	}
	memset (re, 0, sizeof (*re));

	status = regcomp (re, re_str, REG_EXTENDED);
	if (status != 0)
	{
		char errbuf[1024] = "";
		regerror (status, re, errbuf, sizeof (errbuf));
		ERROR ("utils_ignorelist: regcomp failed: %s", errbuf);
		regfree (re);
		sfree (re);
		return (status);
	}

	entry = malloc (sizeof (*entry));
	if (entry == NULL)
	{
		ERROR ("utils_ignorelist: malloc failed");
		regfree (re);
		sfree (re);
		return (ENOMEM);
	}
	memset (entry, 0, sizeof (*entry));
	entry->rmatch = re;

	ignorelist_append (il, entry);
	return (0);
} /* int ignorelist_append_regex */
#endif

static int ignorelist_append_string(ignorelist_t *il, const char *entry)
