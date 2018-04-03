
  return success;
}


#define ENSURE_TABLES_EXIST do {			\
  if (!dl_file_url_map)					\
    dl_file_url_map = make_string_hash_table (0);	\
  if (!dl_url_file_map)					\
    dl_url_file_map = make_string_hash_table (0);	\
} while (0)

/* Return 1 if S1 and S2 are the same, except for "/index.html".  The
   three cases in which it returns one are (substitute any substring
   for "foo"):

   m("foo/index.html", "foo/")  ==> 1
   m("foo/", "foo/index.html")  ==> 1
   m("foo", "foo/index.html")   ==> 1
   m("foo", "foo/"              ==> 1
   m("foo", "foo")              ==> 1  */

static int
match_except_index (const char *s1, const char *s2)
{
  int i;
  const char *lng;

  /* Skip common substring. */
  for (i = 0; *s1 && *s2 && *s1 == *s2; s1++, s2++, i++)
    ;
  if (i == 0)
    /* Strings differ at the very beginning -- bail out.  We need to
       check this explicitly to avoid `lng - 1' reading outside the
       array.  */
    return 0;

  if (!*s1 && !*s2)
    /* Both strings hit EOF -- strings are equal. */
    return 1;
  else if (*s1 && *s2)
    /* Strings are randomly different, e.g. "/foo/bar" and "/foo/qux". */
    return 0;
  else if (*s1)
    /* S1 is the longer one. */
    lng = s1;
  else
    /* S2 is the longer one. */
    lng = s2;

  /* foo            */            /* foo/           */
  /* foo/index.html */  /* or */  /* foo/index.html */
  /*    ^           */            /*     ^          */

  if (*lng != '/')
    /* The right-hand case. */
    --lng;

  if (*lng == '/' && *(lng + 1) == '\0')
    /* foo  */
    /* foo/ */
    return 1;

  return 0 == strcmp (lng, "/index.html");
}

static int
dissociate_urls_from_file_mapper (void *key, void *value, void *arg)
{
  char *mapping_url = (char *)key;
  char *mapping_file = (char *)value;
  char *file = (char *)arg;

  if (0 == strcmp (mapping_file, file))
    {
      hash_table_remove (dl_url_file_map, mapping_url);
      xfree (mapping_url);
      xfree (mapping_file);
    }

  /* Continue mapping. */
  return 0;
}

/* Remove all associations from various URLs to FILE from dl_url_file_map. */

static void
dissociate_urls_from_file (const char *file)
{
  hash_table_map (dl_url_file_map, dissociate_urls_from_file_mapper,
		  (char *)file);
}

/* Register that URL has been successfully downloaded to FILE.  This
   is used by the link conversion code to convert references to URLs
   to references to local files.  It is also being used to check if a
   URL has already been downloaded.  */

void
register_download (const char *url, const char *file)
{
  char *old_file, *old_url;

  ENSURE_TABLES_EXIST;

  /* With some forms of retrieval, it is possible, although not likely
     or particularly desirable.  If both are downloaded, the second
     download will override the first one.  When that happens,
     dissociate the old file name from the URL.  */

  if (hash_table_get_pair (dl_file_url_map, file, &old_file, &old_url))
    {
      if (0 == strcmp (url, old_url))
	/* We have somehow managed to download the same URL twice.
	   Nothing to do.  */
	return;

      if (match_except_index (url, old_url)
	  && !hash_table_contains (dl_url_file_map, url))
	/* The two URLs differ only in the "index.html" ending.  For
	   example, one is "http://www.server.com/", and the other is
	   "http://www.server.com/index.html".  Don't remove the old
	   one, just add the new one as a non-canonical entry.  */
	goto url_only;

      hash_table_remove (dl_file_url_map, file);
      xfree (old_file);
      xfree (old_url);

      /* Remove all the URLs that point to this file.  Yes, there can
	 be more than one such URL, because we store redirections as
	 multiple entries in dl_url_file_map.  For example, if URL1
	 redirects to URL2 which gets downloaded to FILE, we map both
	 URL1 and URL2 to FILE in dl_url_file_map.  (dl_file_url_map
	 only points to URL2.)  When another URL gets loaded to FILE,
	 we want both URL1 and URL2 dissociated from it.

         This is a relatively expensive operation because it performs
         a linear search of the whole hash table, but it should be
         called very rarely, only when two URLs resolve to the same
         file name, *and* the "<file>.1" extensions are turned off.
         In other words, almost never.  */
      dissociate_urls_from_file (file);
    }

  hash_table_put (dl_file_url_map, xstrdup (file), xstrdup (url));

 url_only:
  /* A URL->FILE mapping is not possible without a FILE->URL mapping.
     If the latter were present, it should have been removed by the
     above `if'.  So we could write:

         assert (!hash_table_contains (dl_url_file_map, url));

     The above is correct when running in recursive mode where the
     same URL always resolves to the same file.  But if you do
     something like:

         wget URL URL

     then the first URL will resolve to "FILE", and the other to
     "FILE.1".  In that case, FILE.1 will not be found in
     dl_file_url_map, but URL will still point to FILE in
     dl_url_file_map.  */
  if (hash_table_get_pair (dl_url_file_map, url, &old_url, &old_file))
    {
      hash_table_remove (dl_url_file_map, url);
      xfree (old_url);
      xfree (old_file);
    }

  hash_table_put (dl_url_file_map, xstrdup (url), xstrdup (file));
}

/* Register that FROM has been redirected to TO.  This assumes that TO
   is successfully downloaded and already registered using
   register_download() above.  */

void
register_redirection (const char *from, const char *to)
{
  char *file;

  ENSURE_TABLES_EXIST;

  file = hash_table_get (dl_url_file_map, to);
  assert (file != NULL);
  if (!hash_table_contains (dl_url_file_map, from))
    hash_table_put (dl_url_file_map, xstrdup (from), xstrdup (file));
}

/* Register that the file has been deleted. */

static void
register_delete_file (const char *file)
{
  char *old_url, *old_file;

  ENSURE_TABLES_EXIST;

  if (!hash_table_get_pair (dl_file_url_map, file, &old_file, &old_url))
    return;

  hash_table_remove (dl_file_url_map, file);
  xfree (old_file);
  xfree (old_url);
  dissociate_urls_from_file (file);
}

/* Register that FILE is an HTML file that has been downloaded. */

void
register_html (const char *url, const char *file)
{
  if (!downloaded_html_set)
    downloaded_html_set = make_string_hash_table (0);
  else if (hash_table_contains (downloaded_html_set, file))
    return;

  /* The set and the list should use the same copy of FILE, but the
     slist interface insists on strduping the string it gets.  Oh
     well. */
  string_set_add (downloaded_html_set, file);
  downloaded_html_list = slist_prepend (downloaded_html_list, file);
}

/* This function is called when the retrieval is done to convert the
   links that have been downloaded.  It has to be called at the end of
   the retrieval, because only then does Wget know conclusively which
   URLs have been downloaded, and which not, so it can tell which
   direction to convert to.

   The "direction" means that the URLs to the files that have been
   downloaded get converted to the relative URL which will point to
   that file.  And the other URLs get converted to the remote URL on
   the server.

   All the downloaded HTMLs are kept in downloaded_html_files, and
   downloaded URLs in urls_downloaded.  All the information is
   extracted from these two lists.  */

void
convert_all_links (void)
{
  slist *html;
  long msecs;
  int file_count = 0;

  struct wget_timer *timer = wtimer_new ();

  /* Destructively reverse downloaded_html_files to get it in the right order.
     recursive_retrieve() used slist_prepend() consistently.  */
  downloaded_html_list = slist_nreverse (downloaded_html_list);

  for (html = downloaded_html_list; html; html = html->next)
    {
      struct urlpos *urls, *cur_url;
      char *url;
      char *file = html->string;

      /* Determine the URL of the HTML file.  get_urls_html will need
	 it.  */
      url = hash_table_get (dl_file_url_map, file);
      if (!url)
	{
	  DEBUGP (("Apparently %s has been removed.\n", file));
	  continue;
	}

      DEBUGP (("Scanning %s (from %s)\n", file, url));

      /* Parse the HTML file...  */
      urls = get_urls_html (file, url, NULL);

      /* We don't respect meta_disallow_follow here because, even if
         the file is not followed, we might still want to convert the
         links that have been followed from other files.  */

      for (cur_url = urls; cur_url; cur_url = cur_url->next)
	{
	  char *local_name;
	  struct url *u = cur_url->url;

	  if (cur_url->link_base_p)
	    {
	      /* Base references have been resolved by our parser, so
		 we turn the base URL into an empty string.  (Perhaps
		 we should remove the tag entirely?)  */
	      cur_url->convert = CO_NULLIFY_BASE;
	      continue;
	    }

	  /* We decide the direction of conversion according to whether
	     a URL was downloaded.  Downloaded URLs will be converted
	     ABS2REL, whereas non-downloaded will be converted REL2ABS.  */
	  local_name = hash_table_get (dl_url_file_map, u->url);

	  /* Decide on the conversion type.  */
	  if (local_name)
	    {
	      /* We've downloaded this URL.  Convert it to relative
                 form.  We do this even if the URL already is in
                 relative form, because our directory structure may
                 not be identical to that on the server (think `-nd',
                 `--cut-dirs', etc.)  */
	      cur_url->convert = CO_CONVERT_TO_RELATIVE;
	      cur_url->local_name = xstrdup (local_name);
	      DEBUGP (("will convert url %s to local %s\n", u->url, local_name));
	    }
	  else
	    {
	      /* We haven't downloaded this URL.  If it's not already
                 complete (including a full host name), convert it to
                 that form, so it can be reached while browsing this
                 HTML locally.  */
	      if (!cur_url->link_complete_p)
		cur_url->convert = CO_CONVERT_TO_COMPLETE;
	      cur_url->local_name = NULL;
	      DEBUGP (("will convert url %s to complete\n", u->url));
	    }
	}

      /* Convert the links in the file.  */
      convert_links (file, urls);
      ++file_count;

      /* Free the data.  */
      free_urlpos (urls);
    }

  msecs = wtimer_elapsed (timer);
  wtimer_delete (timer);
  logprintf (LOG_VERBOSE, _("Converted %d files in %.2f seconds.\n"),
	     file_count, (double)msecs / 1000);
}

/* Cleanup the data structures associated with recursive retrieving
   (the variables above).  */
void
recursive_cleanup (void)
{
  if (dl_file_url_map)
    {
      free_keys_and_values (dl_file_url_map);
      hash_table_destroy (dl_file_url_map);
      dl_file_url_map = NULL;
    }
  if (dl_url_file_map)
    {
      free_keys_and_values (dl_url_file_map);
      hash_table_destroy (dl_url_file_map);
      dl_url_file_map = NULL;
    }
  if (downloaded_html_set)
    string_set_free (downloaded_html_set);
  slist_free (downloaded_html_list);
  downloaded_html_list = NULL;
}
