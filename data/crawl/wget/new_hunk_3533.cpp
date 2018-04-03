static struct hash_table *dl_url_file_map;

/* List of HTML files downloaded in this Wget run.  Used for link
   conversion after Wget is done.  This list should only be traversed
   in order.  If you need to check whether a file has been downloaded,
   use a hash table, e.g. dl_file_url_map.  */
static slist *downloaded_html_files;

/* Functions for maintaining the URL queue.  */

struct queue_element {
  const char *url;
  const char *referer;
  int depth;
  struct queue_element *next;
};

struct url_queue {
  struct queue_element *head;
  struct queue_element *tail;
  int count, maxcount;
};

/* Create a URL queue. */

static struct url_queue *
url_queue_new (void)
{
  struct url_queue *queue = xmalloc (sizeof (*queue));
  memset (queue, '\0', sizeof (*queue));
  return queue;
}

/* Delete a URL queue. */

static void
url_queue_delete (struct url_queue *queue)
{
  xfree (queue);
}

/* Enqueue a URL in the queue.  The queue is FIFO: the items will be
   retrieved ("dequeued") from the queue in the order they were placed
   into it.  */

static void
url_enqueue (struct url_queue *queue,
	     const char *url, const char *referer, int depth)
{
  struct queue_element *qel = xmalloc (sizeof (*qel));
  qel->url = url;
  qel->referer = referer;
  qel->depth = depth;
  qel->next = NULL;

  ++queue->count;
  if (queue->count > queue->maxcount)
    queue->maxcount = queue->count;

  DEBUGP (("Enqueuing %s at depth %d\n", url, depth));
  DEBUGP (("Queue count %d, maxcount %d.\n", queue->count, queue->maxcount));

  if (queue->tail)
    queue->tail->next = qel;
  queue->tail = qel;

  if (!queue->head)
    queue->head = queue->tail;
}

/* Take a URL out of the queue.  Return 1 if this operation succeeded,
   or 0 if the queue is empty.  */

static int
url_dequeue (struct url_queue *queue,
	     const char **url, const char **referer, int *depth)
{
  struct queue_element *qel = queue->head;

  if (!qel)
    return 0;

  queue->head = queue->head->next;
  if (!queue->head)
    queue->tail = NULL;

  *url = qel->url;
  *referer = qel->referer;
  *depth = qel->depth;

  --queue->count;

  DEBUGP (("Dequeuing %s at depth %d\n", qel->url, qel->depth));
  DEBUGP (("Queue count %d, maxcount %d.\n", queue->count, queue->maxcount));

  xfree (qel);
  return 1;
}

static int descend_url_p PARAMS ((const struct urlpos *, struct url *, int,
				  struct url *, struct hash_table *));

/* Retrieve a part of the web beginning with START_URL.  This used to
   be called "recursive retrieval", because the old function was
   recursive and implemented depth-first search.  retrieve_tree on the
   other hand implements breadth-search traversal of the tree, which
   results in much nicer ordering of downloads.

   The algorithm this function uses is simple:

   1. put START_URL in the queue.
   2. while there are URLs in the queue:

     3. get next URL from the queue.
     4. download it.
     5. if the URL is HTML and its depth does not exceed maximum depth,
        get the list of URLs embedded therein.
     6. for each of those URLs do the following:

       7. if the URL is not one of those downloaded before, and if it
          satisfies the criteria specified by the various command-line
	  options, add it to the queue. */

uerr_t
retrieve_tree (const char *start_url)
{
  uerr_t status = RETROK;

  /* The queue of URLs we need to load. */
  struct url_queue *queue = url_queue_new ();

  /* The URLs we decided we don't want to load. */
  struct hash_table *blacklist = make_string_hash_table (0);

  /* We'll need various components of this, so better get it over with
     now. */
  struct url *start_url_parsed = url_parse (start_url, NULL);

  url_enqueue (queue, xstrdup (start_url), NULL, 0);
  string_set_add (blacklist, start_url);

  while (1)
    {
      int descend = 0;
      char *url, *referer, *file = NULL;
      int depth;
      boolean dash_p_leaf_HTML = FALSE;

      if (downloaded_exceeds_quota ())
	break;

      if (status == FWRITEERR)
	break;

      /* Get the next URL from the queue. */

      if (!url_dequeue (queue,
			(const char **)&url, (const char **)&referer,
			&depth))
	break;

      /* And download it. */

      {
	int dt = 0;
	char *redirected = NULL;
	int oldrec = opt.recursive;

	opt.recursive = 0;
	status = retrieve_url (url, &file, &redirected, NULL, &dt);
	opt.recursive = oldrec;

	if (redirected)
	  {
	    xfree (url);
	    url = redirected;
	  }
	if (file && status == RETROK
	    && (dt & RETROKF) && (dt & TEXTHTML))
	  descend = 1;
      }

      if (descend
	  && depth >= opt.reclevel && opt.reclevel != INFINITE_RECURSION)
	{
	  if (opt.page_requisites && depth == opt.reclevel)
	    /* When -p is specified, we can do one more partial
	       recursion from the "leaf nodes" on the HTML document
	       tree.  The recursion is partial in that we won't
	       traverse any <A> or <AREA> tags, nor any <LINK> tags
	       except for <LINK REL="stylesheet">. */
	    /* #### This would be the place to implement the TODO
	       entry saying that -p should do two more hops on
	       framesets.  */
	    dash_p_leaf_HTML = TRUE;
	  else
	    {
	      /* Either -p wasn't specified or it was and we've
		 already gone the one extra (pseudo-)level that it
		 affords us, so we need to bail out. */
	      DEBUGP (("Not descending further; at depth %d, max. %d.\n",
		       depth, opt.reclevel));
	      descend = 0;
	    }
	}

      /* If the downloaded document was HTML, parse it and enqueue the
	 links it contains. */

      if (descend)
	{
	  int meta_disallow_follow = 0;
	  struct urlpos *children = get_urls_html (file, url, dash_p_leaf_HTML,
						   &meta_disallow_follow);

	  if (opt.use_robots && meta_disallow_follow)
	    {
	      free_urlpos (children);
	      children = NULL;
	    }

	  if (children)
	    {
	      struct urlpos *child = children;
	      struct url *url_parsed = url_parsed = url_parse (url, NULL);
	      assert (url_parsed != NULL);

	      for (; child; child = child->next)
		{
		  if (descend_url_p (child, url_parsed, depth, start_url_parsed,
				     blacklist))
		    {
		      url_enqueue (queue, xstrdup (child->url->url),
				   xstrdup (url), depth + 1);
		      /* We blacklist the URL we have enqueued, because we
			 don't want to enqueue (and hence download) the
			 same URL twice.  */
		      string_set_add (blacklist, child->url->url);
		    }
		}

	      url_free (url_parsed);
	      free_urlpos (children);
	    }
	}

      if (opt.delete_after || (file && !acceptable (file)))
	{
	  /* Either --delete-after was specified, or we loaded this
	     otherwise rejected (e.g. by -R) HTML file just so we
	     could harvest its hyperlinks -- in either case, delete
	     the local file. */
	  DEBUGP (("Removing file due to %s in recursive_retrieve():\n",
		   opt.delete_after ? "--delete-after" :
		   "recursive rejection criteria"));
	  logprintf (LOG_VERBOSE,
		     (opt.delete_after ? _("Removing %s.\n")
		      : _("Removing %s since it should be rejected.\n")),
		     file);
	  if (unlink (file))
	    logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
	}

      xfree (url);
      FREE_MAYBE (referer);
      FREE_MAYBE (file);
    }

  /* If anything is left of the queue due to a premature exit, free it
     now.  */
  {
    char *d1, *d2;
    int d3;
    while (url_dequeue (queue, (const char **)&d1, (const char **)&d2, &d3))
      {
	xfree (d1);
	FREE_MAYBE (d2);
      }
  }
  url_queue_delete (queue);

  if (start_url_parsed)
    url_free (start_url_parsed);
  string_set_free (blacklist);

  if (downloaded_exceeds_quota ())
    return QUOTEXC;
  else if (status == FWRITEERR)
    return FWRITEERR;
  else
    return RETROK;
}

/* Based on the context provided by retrieve_tree, decide whether a
   URL is to be descended to.  This is only ever called from
   retrieve_tree, but is in a separate function for clarity.  */

static int
descend_url_p (const struct urlpos *upos, struct url *parent, int depth,
	       struct url *start_url_parsed, struct hash_table *blacklist)
{
  struct url *u = upos->url;
  const char *url = u->url;

  DEBUGP (("Deciding whether to enqueue \"%s\".\n", url));

  if (string_set_contains (blacklist, url))
    {
      DEBUGP (("Already on the black list.\n"));
      goto out;
    }

  /* Several things to check for:
     1. if scheme is not http, and we don't load it
     2. check for relative links (if relative_only is set)
     3. check for domain
     4. check for no-parent
     5. check for excludes && includes
     6. check for suffix
     7. check for same host (if spanhost is unset), with possible
     gethostbyname baggage
     8. check for robots.txt

     Addendum: If the URL is FTP, and it is to be loaded, only the
     domain and suffix settings are "stronger".

     Note that .html files will get loaded regardless of suffix rules
     (but that is remedied later with unlink) unless the depth equals
     the maximum depth.

     More time- and memory- consuming tests should be put later on
     the list.  */

  /* 1. Schemes other than HTTP are normally not recursed into. */
  if (u->scheme != SCHEME_HTTP
      && !(u->scheme == SCHEME_FTP && opt.follow_ftp))
    {
      DEBUGP (("Not following non-HTTP schemes.\n"));
      goto blacklist;
    }

  /* 2. If it is an absolute link and they are not followed, throw it
     out.  */
  if (u->scheme == SCHEME_HTTP)
    if (opt.relative_only && !upos->link_relative_p)
      {
	DEBUGP (("It doesn't really look like a relative link.\n"));
	goto blacklist;
      }

  /* 3. If its domain is not to be accepted/looked-up, chuck it
     out.  */
  if (!accept_domain (u))
    {
      DEBUGP (("The domain was not accepted.\n"));
      goto blacklist;
    }

  /* 4. Check for parent directory.

     If we descended to a different host or changed the scheme, ignore
     opt.no_parent.  Also ignore it for -p leaf retrievals.  */
  if (opt.no_parent
      && u->scheme == parent->scheme
      && 0 == strcasecmp (u->host, parent->host)
      && u->port == parent->port)
    {
      if (!frontcmp (parent->dir, u->dir))
	{
	  DEBUGP (("Trying to escape the root directory with no_parent in effect.\n"));
	  goto blacklist;
	}
    }

  /* 5. If the file does not match the acceptance list, or is on the
     rejection list, chuck it out.  The same goes for the directory
     exclusion and inclusion lists.  */
  if (opt.includes || opt.excludes)
    {
      if (!accdir (u->dir, ALLABS))
	{
	  DEBUGP (("%s (%s) is excluded/not-included.\n", url, u->dir));
	  goto blacklist;
	}
    }

  /* 6. */
  {
    char *suf = NULL;
    /* Check for acceptance/rejection rules.  We ignore these rules
       for HTML documents because they might lead to other files which
       need to be downloaded.  Of course, we don't know which
       documents are HTML before downloading them, so we guess.

       A file is subject to acceptance/rejection rules if:

       * u->file is not "" (i.e. it is not a directory)
       and either:
         + there is no file suffix,
	 + or there is a suffix, but is not "html" or "htm",
	 + both:
	   - recursion is not infinite,
	   - and we are at its very end. */

    if (u->file[0] != '\0'
	&& ((suf = suffix (url)) == NULL
	    || (0 != strcmp (suf, "html") && 0 != strcmp (suf, "htm"))
	    || (opt.reclevel == INFINITE_RECURSION && depth >= opt.reclevel)))
      {
	if (!acceptable (u->file))
	  {
	    DEBUGP (("%s (%s) does not match acc/rej rules.\n",
		     url, u->file));
	    FREE_MAYBE (suf);
	    goto blacklist;
	  }
      }
    FREE_MAYBE (suf);
  }

  /* 7. */
  if (u->scheme == parent->scheme)
    if (!opt.spanhost && 0 != strcasecmp (parent->host, u->host))
      {
	DEBUGP (("This is not the same hostname as the parent's (%s and %s).\n",
		 u->host, parent->host));
	goto blacklist;
      }

  /* 8. */
  if (opt.use_robots && u->scheme == SCHEME_HTTP)
    {
      struct robot_specs *specs = res_get_specs (u->host, u->port);
      if (!specs)
	{
	  char *rfile;
	  if (res_retrieve_file (url, &rfile))
	    {
	      specs = res_parse_from_file (rfile);
	      xfree (rfile);
	    }
	  else
	    {
	      /* If we cannot get real specs, at least produce
		 dummy ones so that we can register them and stop
		 trying to retrieve them.  */
	      specs = res_parse ("", 0);
	    }
	  res_register_specs (u->host, u->port, specs);
	}

      /* Now that we have (or don't have) robots.txt specs, we can
	 check what they say.  */
      if (!res_match_path (specs, u->path))
	{
	  DEBUGP (("Not following %s because robots.txt forbids it.\n", url));
	  goto blacklist;
	}
    }

  /* The URL has passed all the tests.  It can be placed in the
     download queue. */
  DEBUGP (("Decided to load it.\n"));

  return 1;

 blacklist:
  string_set_add (blacklist, url);

 out:
  DEBUGP (("Decided NOT to load it.\n"));

  return 0;
}

/* Register that URL has been successfully downloaded to FILE. */

void
register_download (const char *url, const char *file)
{
