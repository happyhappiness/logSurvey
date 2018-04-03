      free_urlpos (urls);
    }
}

/* Robots support.  */

/* Construct the robots URL.  */
static struct urlinfo *
robots_url (const char *url, const char *robots_filename)
{
  struct urlinfo *u = newurl ();
  uerr_t err;

  err = parseurl (url, u, 0);
  assert (err == URLOK && u->proto == URLHTTP);
  xfree (u->file);
  xfree (u->dir);
  xfree (u->url);
  u->dir = xstrdup ("");
  u->file = xstrdup (robots_filename);
  u->url = str_url (u, 0);
  return u;
}

/* Retrieves the robots_filename from the root server directory, if
   possible.  Returns ROBOTSOK if robots were retrieved OK, and
   NOROBOTS if robots could not be retrieved for any reason.  */
static uerr_t
retrieve_robots (const char *url, const char *robots_filename)
{
  int dt;
  uerr_t err;
  struct urlinfo *u;

  u = robots_url (url, robots_filename);
  logputs (LOG_VERBOSE, _("Loading robots.txt; please ignore errors.\n"));
  err = retrieve_url (u->url, NULL, NULL, NULL, &dt);
  freeurl (u, 1);
  if (err == RETROK)
    return ROBOTSOK;
  else
    return NOROBOTS;
}

/* Parse the robots_filename and return the disallowed path components
   in a malloc-ed vector of character pointers.

   It should be fully compliant with the syntax as described in the
   file norobots.txt, adopted by the robots mailing list
   (robots@webcrawler.com).  */
static char **
parse_robots (const char *robots_filename)
{
  FILE *fp;
  char **entries;
  char *line, *cmd, *str, *p;
  char *base_version, *version;
  int num, i;
  int wget_matched;		/* is the part meant for Wget?  */

  entries = NULL;

  num = 0;
  fp = fopen (robots_filename, "rb");
  if (!fp)
    return NULL;

  /* Kill version number.  */
  if (opt.useragent)
    {
      STRDUP_ALLOCA (base_version, opt.useragent);
      STRDUP_ALLOCA (version, opt.useragent);
    }
  else
    {
      int len = 10 + strlen (version_string);
      base_version = (char *)alloca (len);
      sprintf (base_version, "Wget/%s", version_string);
      version = (char *)alloca (len);
      sprintf (version, "Wget/%s", version_string);
    }
  for (p = version; *p; p++)
    *p = TOLOWER (*p);
  for (p = base_version; *p && *p != '/'; p++)
    *p = TOLOWER (*p);
  *p = '\0';

  /* Setting this to 1 means that Wget considers itself under
     restrictions by default, even if the User-Agent field is not
     present.  However, if it finds the user-agent set to anything
     other than Wget, the rest will be ignored (up to the following
     User-Agent field).  Thus you may have something like:

     Disallow: 1
     Disallow: 2
     User-Agent: stupid-robot
     Disallow: 3
     Disallow: 4
     User-Agent: Wget*
     Disallow: 5
     Disallow: 6
     User-Agent: *
     Disallow: 7

     In this case the 1, 2, 5, 6 and 7 disallow lines will be
     stored.  */
  wget_matched = 1;
  while ((line = read_whole_line (fp)))
    {
      int len = strlen (line);
      /* Destroy <CR><LF> if present.  */
      if (len && line[len - 1] == '\n')
	line[--len] = '\0';
      if (len && line[len - 1] == '\r')
	line[--len] = '\0';
      /* According to specifications, optional space may be at the
	 end...  */
      DEBUGP (("Line: %s\n", line));
      /* Skip spaces.  */
      for (cmd = line; *cmd && ISSPACE (*cmd); cmd++);
      if (!*cmd)
	{
	  xfree (line);
	  DEBUGP (("(chucked out)\n"));
	  continue;
	}
      /* Look for ':'.  */
      for (str = cmd; *str && *str != ':'; str++);
      if (!*str)
	{
	  xfree (line);
	  DEBUGP (("(chucked out)\n"));
	  continue;
	}
      /* Zero-terminate the command.  */
      *str++ = '\0';
      /* Look for the string beginning...  */
      for (; *str && ISSPACE (*str); str++);
      /* Look for comments or trailing spaces and kill them off.  */
      for (p = str; *p; p++)
	if (*p && ISSPACE (*p) && ((*(p + 1) == '#') || (*(p + 1) == '\0')))
	  {
	    /* We have found either a shell-style comment `<sp>+#' or some
               trailing spaces.  Now rewind to the beginning of the spaces
               and place '\0' there.  */
	    while (p > str && ISSPACE (*p))
	      --p;
	    if (p == str)
	      *p = '\0';
	    else
	      *(p + 1) = '\0';
	    break;
	  }
      if (!strcasecmp (cmd, "User-agent"))
	{
	  int match = 0;
	  /* Lowercase the agent string.  */
	  for (p = str; *p; p++)
	    *p = TOLOWER (*p);
	  /* If the string is `*', it matches.  */
	  if (*str == '*' && !*(str + 1))
	    match = 1;
	  else
	    {
	      /* If the string contains wildcards, we'll run it through
		 fnmatch().  */
	      if (has_wildcards_p (str))
		{
		  /* If the string contains '/', compare with the full
		     version.  Else, compare it to base_version.  */
		  if (strchr (str, '/'))
		    match = !fnmatch (str, version, 0);
		  else
		    match = !fnmatch (str, base_version, 0);
		}
	      else                /* Substring search */
		{
		  if (strstr (version, str))
		    match = 1;
		  else
		    match = 0;
		}
	    }
	  /* If Wget is not matched, skip all the entries up to the
	     next User-agent field.  */
	  wget_matched = match;
	}
      else if (!wget_matched)
	{
	  xfree (line);
	  DEBUGP (("(chucking out since it is not applicable for Wget)\n"));
	  continue;
	}
      else if (!strcasecmp (cmd, "Disallow"))
	{
	  /* If "Disallow" is empty, the robot is welcome.  */
	  if (!*str)
	    {
	      free_vec (entries);
	      entries = (char **)xmalloc (sizeof (char *));
	      *entries = NULL;
	      num = 0;
	    }
	  else
	    {
	      entries = (char **)xrealloc (entries, (num + 2)* sizeof (char *));
	      entries[num] = xstrdup (str);
	      entries[++num] = NULL;
	      /* Strip trailing spaces, according to specifications.  */
	      for (i = strlen (str); i >= 0 && ISSPACE (str[i]); i--)
		if (ISSPACE (str[i]))
		  str[i] = '\0';
	    }
	}
      else
	{
	  /* unknown command */
	  DEBUGP (("(chucked out)\n"));
	}
      xfree (line);
    }
  fclose (fp);
  return entries;
}

/* May the URL url be loaded according to disallowing rules stored in
   forbidden?  */
static int
robots_match (struct urlinfo *u, char **fb)
{
  int l;

  if (!fb)
    return 1;
  DEBUGP (("Matching %s against: ", u->path));
  for (; *fb; fb++)
    {
      DEBUGP (("%s ", *fb));
      l = strlen (*fb);
      /* If dir is fb, we may not load the file.  */
      if (strncmp (u->path, *fb, l) == 0)
	{
	  DEBUGP (("matched.\n"));
	  return 0; /* Matches, i.e. does not load...  */
	}
    }
  DEBUGP (("not matched.\n"));
  return 1;
}
