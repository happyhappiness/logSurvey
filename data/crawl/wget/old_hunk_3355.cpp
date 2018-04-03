  return result;
}

/* Return the URL of the proxy appropriate for url U.  */
char *
getproxy (struct url *u)
{
  char *proxy = NULL;
  char *rewritten_url;
  static char rewritten_storage[1024];

  if (!opt.use_proxy)
    return NULL;
  if (!no_proxy_match (u->host, (const char **)opt.no_proxy))
    return NULL;

  switch (u->scheme)
    {
    case SCHEME_HTTP:
      proxy = opt.http_proxy ? opt.http_proxy : getenv ("http_proxy");
      break;
#ifdef HAVE_SSL
    case SCHEME_HTTPS:
      proxy = opt.https_proxy ? opt.https_proxy : getenv ("https_proxy");
      break;
#endif
    case SCHEME_FTP:
      proxy = opt.ftp_proxy ? opt.ftp_proxy : getenv ("ftp_proxy");
      break;
    case SCHEME_INVALID:
      break;
    }
  if (!proxy || !*proxy)
    return NULL;

  /* Handle shorthands.  `rewritten_storage' is a kludge to allow
     getproxy() to return static storage. */
  rewritten_url = rewrite_shorthand_url (proxy);
  if (rewritten_url)
    {
      strncpy (rewritten_storage, rewritten_url, sizeof(rewritten_storage));
      rewritten_storage[sizeof (rewritten_storage) - 1] = '\0';
      proxy = rewritten_storage;
    }

  return proxy;
}

/* Should a host be accessed through proxy, concerning no_proxy?  */
int
no_proxy_match (const char *host, const char **no_proxy)
{
  if (!no_proxy)
    return 1;
  else
    return !sufmatch (no_proxy, host);
}

/* Support for converting links for local viewing in downloaded HTML
   files.  This should be moved to another file, because it has
   nothing to do with processing URLs.  */

static void write_backup_file PARAMS ((const char *, downloaded_file_t));
static const char *replace_attr PARAMS ((const char *, int, FILE *,
					 const char *));
static const char *replace_attr_refresh_hack PARAMS ((const char *, int, FILE *,
						      const char *, int));
static char *local_quote_string PARAMS ((const char *));

/* Change the links in one HTML file.  LINKS is a list of links in the
   document, along with their positions and the desired direction of
   the conversion.  */
void
convert_links (const char *file, struct urlpos *links)
{
  struct file_memory *fm;
  FILE *fp;
  const char *p;
  downloaded_file_t downloaded_file_return;

  struct urlpos *link;
  int to_url_count = 0, to_file_count = 0;

  logprintf (LOG_VERBOSE, _("Converting %s... "), file);

  {
    /* First we do a "dry run": go through the list L and see whether
       any URL needs to be converted in the first place.  If not, just
       leave the file alone.  */
    int dry_count = 0;
    struct urlpos *dry = links;
    for (dry = links; dry; dry = dry->next)
      if (dry->convert != CO_NOCONVERT)
	++dry_count;
    if (!dry_count)
      {
	logputs (LOG_VERBOSE, _("nothing to do.\n"));
	return;
      }
  }

  fm = read_file (file);
  if (!fm)
    {
      logprintf (LOG_NOTQUIET, _("Cannot convert links in %s: %s\n"),
		 file, strerror (errno));
      return;
    }

  downloaded_file_return = downloaded_file (CHECK_FOR_FILE, file);
  if (opt.backup_converted && downloaded_file_return)
    write_backup_file (file, downloaded_file_return);

  /* Before opening the file for writing, unlink the file.  This is
     important if the data in FM is mmaped.  In such case, nulling the
     file, which is what fopen() below does, would make us read all
     zeroes from the mmaped region.  */
  if (unlink (file) < 0 && errno != ENOENT)
    {
      logprintf (LOG_NOTQUIET, _("Unable to delete `%s': %s\n"),
		 file, strerror (errno));
      read_file_free (fm);
      return;
    }
  /* Now open the file for writing.  */
  fp = fopen (file, "wb");
  if (!fp)
    {
      logprintf (LOG_NOTQUIET, _("Cannot convert links in %s: %s\n"),
		 file, strerror (errno));
      read_file_free (fm);
      return;
    }

  /* Here we loop through all the URLs in file, replacing those of
     them that are downloaded with relative references.  */
  p = fm->content;
  for (link = links; link; link = link->next)
    {
      char *url_start = fm->content + link->pos;

      if (link->pos >= fm->length)
	{
	  DEBUGP (("Something strange is going on.  Please investigate."));
	  break;
	}
      /* If the URL is not to be converted, skip it.  */
      if (link->convert == CO_NOCONVERT)
	{
	  DEBUGP (("Skipping %s at position %d.\n", link->url->url, link->pos));
	  continue;
	}

      /* Echo the file contents, up to the offending URL's opening
         quote, to the outfile.  */
      fwrite (p, 1, url_start - p, fp);
      p = url_start;

      switch (link->convert)
	{
	case CO_CONVERT_TO_RELATIVE:
	  /* Convert absolute URL to relative. */
	  {
	    char *newname = construct_relative (file, link->local_name);
	    char *quoted_newname = local_quote_string (newname);

	    if (!link->link_refresh_p)
	      p = replace_attr (p, link->size, fp, quoted_newname);
	    else
	      p = replace_attr_refresh_hack (p, link->size, fp, quoted_newname,
					     link->refresh_timeout);

	    DEBUGP (("TO_RELATIVE: %s to %s at position %d in %s.\n",
		     link->url->url, newname, link->pos, file));
	    xfree (newname);
	    xfree (quoted_newname);
	    ++to_file_count;
	    break;
	  }
	case CO_CONVERT_TO_COMPLETE:
	  /* Convert the link to absolute URL. */
	  {
	    char *newlink = link->url->url;
	    char *quoted_newlink = html_quote_string (newlink);

	    if (!link->link_refresh_p)
	      p = replace_attr (p, link->size, fp, quoted_newlink);
	    else
	      p = replace_attr_refresh_hack (p, link->size, fp, quoted_newlink,
					     link->refresh_timeout);

	    DEBUGP (("TO_COMPLETE: <something> to %s at position %d in %s.\n",
		     newlink, link->pos, file));
	    xfree (quoted_newlink);
	    ++to_url_count;
	    break;
	  }
	case CO_NULLIFY_BASE:
	  /* Change the base href to "". */
	  p = replace_attr (p, link->size, fp, "");
	  break;
	case CO_NOCONVERT:
	  abort ();
	  break;
	}
    }

  /* Output the rest of the file. */
  if (p - fm->content < fm->length)
    fwrite (p, 1, fm->length - (p - fm->content), fp);
  fclose (fp);
  read_file_free (fm);

  logprintf (LOG_VERBOSE, "%d-%d\n", to_file_count, to_url_count);
}

/* Construct and return a malloced copy of the relative link from two
   pieces of information: local name S1 of the referring file and
   local name S2 of the referred file.

   So, if S1 is "jagor.srce.hr/index.html" and S2 is
   "jagor.srce.hr/images/news.gif", the function will return
   "images/news.gif".

   Alternately, if S1 is "fly.cc.fer.hr/ioccc/index.html", and S2 is
   "fly.cc.fer.hr/images/fly.gif", the function will return
   "../images/fly.gif".

   Caveats: S1 should not begin with `/', unless S2 also begins with
   '/'.  S1 should not contain things like ".." and such --
   construct_relative ("fly/ioccc/../index.html",
   "fly/images/fly.gif") will fail.  (A workaround is to call
   something like path_simplify() on S1).  */
static char *
construct_relative (const char *s1, const char *s2)
{
  int i, cnt, sepdirs1;
  char *res;

  if (*s2 == '/')
    return xstrdup (s2);
  /* S1 should *not* be absolute, if S2 wasn't.  */
  assert (*s1 != '/');
  i = cnt = 0;
  /* Skip the directories common to both strings.  */
  while (1)
    {
      while (s1[i] && s2[i]
	     && (s1[i] == s2[i])
	     && (s1[i] != '/')
	     && (s2[i] != '/'))
	++i;
      if (s1[i] == '/' && s2[i] == '/')
	cnt = ++i;
      else
	break;
    }
  for (sepdirs1 = 0; s1[i]; i++)
    if (s1[i] == '/')
      ++sepdirs1;
  /* Now, construct the file as of:
     - ../ repeated sepdirs1 time
     - all the non-mutual directories of S2.  */
  res = (char *)xmalloc (3 * sepdirs1 + strlen (s2 + cnt) + 1);
  for (i = 0; i < sepdirs1; i++)
    memcpy (res + 3 * i, "../", 3);
  strcpy (res + 3 * i, s2 + cnt);
  return res;
}

static void
write_backup_file (const char *file, downloaded_file_t downloaded_file_return)
{
  /* Rather than just writing over the original .html file with the
     converted version, save the former to *.orig.  Note we only do
     this for files we've _successfully_ downloaded, so we don't
     clobber .orig files sitting around from previous invocations. */

  /* Construct the backup filename as the original name plus ".orig". */
  size_t         filename_len = strlen(file);
  char*          filename_plus_orig_suffix;
  boolean        already_wrote_backup_file = FALSE;
  slist*         converted_file_ptr;
  static slist*  converted_files = NULL;

  if (downloaded_file_return == FILE_DOWNLOADED_AND_HTML_EXTENSION_ADDED)
    {
      /* Just write "orig" over "html".  We need to do it this way
	 because when we're checking to see if we've downloaded the
	 file before (to see if we can skip downloading it), we don't
	 know if it's a text/html file.  Therefore we don't know yet
	 at that stage that -E is going to cause us to tack on
	 ".html", so we need to compare vs. the original URL plus
	 ".orig", not the original URL plus ".html.orig". */
      filename_plus_orig_suffix = alloca (filename_len + 1);
      strcpy(filename_plus_orig_suffix, file);
      strcpy((filename_plus_orig_suffix + filename_len) - 4, "orig");
    }
  else /* downloaded_file_return == FILE_DOWNLOADED_NORMALLY */
    {
      /* Append ".orig" to the name. */
      filename_plus_orig_suffix = alloca (filename_len + sizeof(".orig"));
      strcpy(filename_plus_orig_suffix, file);
      strcpy(filename_plus_orig_suffix + filename_len, ".orig");
    }

  /* We can get called twice on the same URL thanks to the
     convert_all_links() call in main().  If we write the .orig file
     each time in such a case, it'll end up containing the first-pass
     conversion, not the original file.  So, see if we've already been
     called on this file. */
  converted_file_ptr = converted_files;
  while (converted_file_ptr != NULL)
    if (strcmp(converted_file_ptr->string, file) == 0)
      {
	already_wrote_backup_file = TRUE;
	break;
      }
    else
      converted_file_ptr = converted_file_ptr->next;

  if (!already_wrote_backup_file)
    {
      /* Rename <file> to <file>.orig before former gets written over. */
      if (rename(file, filename_plus_orig_suffix) != 0)
	logprintf (LOG_NOTQUIET, _("Cannot back up %s as %s: %s\n"),
		   file, filename_plus_orig_suffix, strerror (errno));

      /* Remember that we've already written a .orig backup for this file.
	 Note that we never free this memory since we need it till the
	 convert_all_links() call, which is one of the last things the
	 program does before terminating.  BTW, I'm not sure if it would be
	 safe to just set 'converted_file_ptr->string' to 'file' below,
	 rather than making a copy of the string...  Another note is that I
	 thought I could just add a field to the urlpos structure saying
	 that we'd written a .orig file for this URL, but that didn't work,
	 so I had to make this separate list.
	 -- Dan Harkless <wget@harkless.org>

         This [adding a field to the urlpos structure] didn't work
         because convert_file() is called from convert_all_links at
         the end of the retrieval with a freshly built new urlpos
         list.
	 -- Hrvoje Niksic <hniksic@arsdigita.com>
      */
      converted_file_ptr = xmalloc(sizeof(*converted_file_ptr));
      converted_file_ptr->string = xstrdup(file);  /* die on out-of-mem. */
      converted_file_ptr->next = converted_files;
      converted_files = converted_file_ptr;
    }
}

static int find_fragment PARAMS ((const char *, int, const char **,
				  const char **));

/* Replace an attribute's original text with NEW_TEXT. */

static const char *
replace_attr (const char *p, int size, FILE *fp, const char *new_text)
{
  int quote_flag = 0;
  char quote_char = '\"';	/* use "..." for quoting, unless the
				   original value is quoted, in which
				   case reuse its quoting char. */
  const char *frag_beg, *frag_end;

  /* Structure of our string is:
       "...old-contents..."
       <---    size    --->  (with quotes)
     OR:
       ...old-contents...
       <---    size   -->    (no quotes)   */

  if (*p == '\"' || *p == '\'')
    {
      quote_char = *p;
      quote_flag = 1;
      ++p;
      size -= 2;		/* disregard opening and closing quote */
    }
  putc (quote_char, fp);
  fputs (new_text, fp);

  /* Look for fragment identifier, if any. */
  if (find_fragment (p, size, &frag_beg, &frag_end))
    fwrite (frag_beg, 1, frag_end - frag_beg, fp);
  p += size;
  if (quote_flag)
    ++p;
  putc (quote_char, fp);

  return p;
}

/* The same as REPLACE_ATTR, but used when replacing
   <meta http-equiv=refresh content="new_text"> because we need to
   append "timeout_value; URL=" before the next_text.  */

static const char *
replace_attr_refresh_hack (const char *p, int size, FILE *fp,
			   const char *new_text, int timeout)
{
  /* "0; URL=..." */
  char *new_with_timeout = (char *)alloca (numdigit (timeout)
					   + 6 /* "; URL=" */
					   + strlen (new_text)
					   + 1);
  sprintf (new_with_timeout, "%d; URL=%s", timeout, new_text);

  return replace_attr (p, size, fp, new_with_timeout);
}

/* Find the first occurrence of '#' in [BEG, BEG+SIZE) that is not
   preceded by '&'.  If the character is not found, return zero.  If
   the character is found, return 1 and set BP and EP to point to the
   beginning and end of the region.

   This is used for finding the fragment indentifiers in URLs.  */

static int
find_fragment (const char *beg, int size, const char **bp, const char **ep)
{
  const char *end = beg + size;
  int saw_amp = 0;
  for (; beg < end; beg++)
    {
      switch (*beg)
	{
	case '&':
	  saw_amp = 1;
	  break;
	case '#':
	  if (!saw_amp)
	    {
	      *bp = beg;
	      *ep = end;
	      return 1;
	    }
	  /* fallthrough */
	default:
	  saw_amp = 0;
	}
    }
  return 0;
}

/* Quote FILE for use as local reference to an HTML file.

   We quote ? as %3F to avoid passing part of the file name as the
   parameter when browsing the converted file through HTTP.  However,
   it is safe to do this only when `--html-extension' is turned on.
   This is because converting "index.html?foo=bar" to
   "index.html%3Ffoo=bar" would break local browsing, as the latter
   isn't even recognized as an HTML file!  However, converting
   "index.html?foo=bar.html" to "index.html%3Ffoo=bar.html" should be
   safe for both local and HTTP-served browsing.  */

static char *
local_quote_string (const char *file)
{
  const char *file_sans_qmark;
  int qm;

  if (!opt.html_extension)
    return html_quote_string (file);

  qm = count_char (file, '?');

  if (qm)
    {
      const char *from = file;
      char *to, *newname;

      /* qm * 2 because we replace each question mark with "%3F",
	 i.e. replace one char with three, hence two more.  */
      int fsqlen = strlen (file) + qm * 2;

      to = newname = (char *)alloca (fsqlen + 1);
      for (; *from; from++)
	{
	  if (*from != '?')
	    *to++ = *from;
	  else
	    {
	      *to++ = '%';
	      *to++ = '3';
	      *to++ = 'F';
	    }
	}
      assert (to - newname == fsqlen);
      *to = '\0';

      file_sans_qmark = newname;
    }
  else
    file_sans_qmark = file;

  return html_quote_string (file_sans_qmark);
}

/* We're storing "modes" of type downloaded_file_t in the hash table.
   However, our hash tables only accept pointers for keys and values.
   So when we need a pointer, we use the address of a
   downloaded_file_t variable of static storage.  */
   
static downloaded_file_t *
downloaded_mode_to_ptr (downloaded_file_t mode)
{
  static downloaded_file_t
    v1 = FILE_NOT_ALREADY_DOWNLOADED,
    v2 = FILE_DOWNLOADED_NORMALLY,
    v3 = FILE_DOWNLOADED_AND_HTML_EXTENSION_ADDED,
    v4 = CHECK_FOR_FILE;

  switch (mode)
    {
    case FILE_NOT_ALREADY_DOWNLOADED:
      return &v1;
    case FILE_DOWNLOADED_NORMALLY:
      return &v2;
    case FILE_DOWNLOADED_AND_HTML_EXTENSION_ADDED:
      return &v3;
    case CHECK_FOR_FILE:
      return &v4;
    }
  return NULL;
}

/* This should really be merged with dl_file_url_map and
   downloaded_html_files in recur.c.  This was originally a list, but
   I changed it to a hash table beause it was actually taking a lot of
   time to find things in it.  */

static struct hash_table *downloaded_files_hash;

/* Remembers which files have been downloaded.  In the standard case, should be
   called with mode == FILE_DOWNLOADED_NORMALLY for each file we actually
   download successfully (i.e. not for ones we have failures on or that we skip
   due to -N).

   When we've downloaded a file and tacked on a ".html" extension due to -E,
   call this function with FILE_DOWNLOADED_AND_HTML_EXTENSION_ADDED rather than
   FILE_DOWNLOADED_NORMALLY.

   If you just want to check if a file has been previously added without adding
   it, call with mode == CHECK_FOR_FILE.  Please be sure to call this function
   with local filenames, not remote URLs. */
downloaded_file_t
downloaded_file (downloaded_file_t mode, const char *file)
{
  downloaded_file_t *ptr;

  if (mode == CHECK_FOR_FILE)
    {
      if (!downloaded_files_hash)
	return FILE_NOT_ALREADY_DOWNLOADED;
      ptr = hash_table_get (downloaded_files_hash, file);
      if (!ptr)
	return FILE_NOT_ALREADY_DOWNLOADED;
      return *ptr;
    }

  if (!downloaded_files_hash)
    downloaded_files_hash = make_string_hash_table (0);

  ptr = hash_table_get (downloaded_files_hash, file);
  if (ptr)
    return *ptr;

  ptr = downloaded_mode_to_ptr (mode);
  hash_table_put (downloaded_files_hash, xstrdup (file), &ptr);

  return FILE_NOT_ALREADY_DOWNLOADED;
}

static int
df_free_mapper (void *key, void *value, void *ignored)
{
  xfree (key);
  return 0;
}

void
downloaded_files_free (void)
{
  if (downloaded_files_hash)
    {
      hash_table_map (downloaded_files_hash, df_free_mapper, NULL);
      hash_table_destroy (downloaded_files_hash);
      downloaded_files_hash = NULL;
    }
}

/* Return non-zero if scheme a is similar to scheme b.
 
   Schemes are similar if they are equal.  If SSL is supported, schemes
