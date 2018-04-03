 static struct hash_table *dl_url_file_map;
 
 /* List of HTML files downloaded in this Wget run.  Used for link
-   conversion after Wget is done.  */
+   conversion after Wget is done.  This list should only be traversed
+   in order.  If you need to check whether a file has been downloaded,
+   use a hash table, e.g. dl_file_url_map.  */
 static slist *downloaded_html_files;
+
+/* Functions for maintaining the URL queue.  */
 
-/* List of undesirable-to-load URLs.  */
-static struct hash_table *undesirable_urls;
+struct queue_element {
+  const char *url;
+  const char *referer;
+  int depth;
+  struct queue_element *next;
+};
 
-/* Current recursion depth.  */
-static int depth;
+struct url_queue {
+  struct queue_element *head;
+  struct queue_element *tail;
+  int count, maxcount;
+};
 
-/* Base directory we're recursing from (used by no_parent).  */
-static char *base_dir;
+/* Create a URL queue. */
 
-static int first_time = 1;
+static struct url_queue *
+url_queue_new (void)
+{
+  struct url_queue *queue = xmalloc (sizeof (*queue));
+  memset (queue, '\0', sizeof (*queue));
+  return queue;
+}
 
+/* Delete a URL queue. */
 
-/* Cleanup the data structures associated with recursive retrieving
-   (the variables above).  */
-void
-recursive_cleanup (void)
+static void
+url_queue_delete (struct url_queue *queue)
 {
-  if (undesirable_urls)
-    {
-      string_set_free (undesirable_urls);
-      undesirable_urls = NULL;
-    }
-  if (dl_file_url_map)
-    {
-      free_keys_and_values (dl_file_url_map);
-      hash_table_destroy (dl_file_url_map);
-      dl_file_url_map = NULL;
-    }
-  if (dl_url_file_map)
-    {
-      free_keys_and_values (dl_url_file_map);
-      hash_table_destroy (dl_url_file_map);
-      dl_url_file_map = NULL;
-    }
-  undesirable_urls = NULL;
-  slist_free (downloaded_html_files);
-  downloaded_html_files = NULL;
-  FREE_MAYBE (base_dir);
-  first_time = 1;
+  xfree (queue);
 }
 
-/* Reset FIRST_TIME to 1, so that some action can be taken in
-   recursive_retrieve().  */
-void
-recursive_reset (void)
+/* Enqueue a URL in the queue.  The queue is FIFO: the items will be
+   retrieved ("dequeued") from the queue in the order they were placed
+   into it.  */
+
+static void
+url_enqueue (struct url_queue *queue,
+	     const char *url, const char *referer, int depth)
 {
-  first_time = 1;
+  struct queue_element *qel = xmalloc (sizeof (*qel));
+  qel->url = url;
+  qel->referer = referer;
+  qel->depth = depth;
+  qel->next = NULL;
+
+  ++queue->count;
+  if (queue->count > queue->maxcount)
+    queue->maxcount = queue->count;
+
+  DEBUGP (("Enqueuing %s at depth %d\n", url, depth));
+  DEBUGP (("Queue count %d, maxcount %d.\n", queue->count, queue->maxcount));
+
+  if (queue->tail)
+    queue->tail->next = qel;
+  queue->tail = qel;
+
+  if (!queue->head)
+    queue->head = queue->tail;
 }
 
-/* The core of recursive retrieving.  Endless recursion is avoided by
-   having all URLs stored to a linked list of URLs, which is checked
-   before loading any URL.  That way no URL can get loaded twice.
+/* Take a URL out of the queue.  Return 1 if this operation succeeded,
+   or 0 if the queue is empty.  */
+
+static int
+url_dequeue (struct url_queue *queue,
+	     const char **url, const char **referer, int *depth)
+{
+  struct queue_element *qel = queue->head;
+
+  if (!qel)
+    return 0;
+
+  queue->head = queue->head->next;
+  if (!queue->head)
+    queue->tail = NULL;
+
+  *url = qel->url;
+  *referer = qel->referer;
+  *depth = qel->depth;
+
+  --queue->count;
+
+  DEBUGP (("Dequeuing %s at depth %d\n", qel->url, qel->depth));
+  DEBUGP (("Queue count %d, maxcount %d.\n", queue->count, queue->maxcount));
+
+  xfree (qel);
+  return 1;
+}
+
+static int descend_url_p PARAMS ((const struct urlpos *, struct url *, int,
+				  struct url *, struct hash_table *));
+
+/* Retrieve a part of the web beginning with START_URL.  This used to
+   be called "recursive retrieval", because the old function was
+   recursive and implemented depth-first search.  retrieve_tree on the
+   other hand implements breadth-search traversal of the tree, which
+   results in much nicer ordering of downloads.
+
+   The algorithm this function uses is simple:
+
+   1. put START_URL in the queue.
+   2. while there are URLs in the queue:
+
+     3. get next URL from the queue.
+     4. download it.
+     5. if the URL is HTML and its depth does not exceed maximum depth,
+        get the list of URLs embedded therein.
+     6. for each of those URLs do the following:
+
+       7. if the URL is not one of those downloaded before, and if it
+          satisfies the criteria specified by the various command-line
+	  options, add it to the queue. */
 
-   The function also supports specification of maximum recursion depth
-   and a number of other goodies.  */
 uerr_t
-recursive_retrieve (const char *file, const char *this_url)
+retrieve_tree (const char *start_url)
 {
-  char *constr, *filename, *newloc;
-  char *canon_this_url = NULL;
-  int dt, inl, dash_p_leaf_HTML = FALSE;
-  int meta_disallow_follow;
-  int this_url_ftp;            /* See below the explanation */
-  urlpos *url_list, *cur_url;
-  struct url *u;
-
-  assert (this_url != NULL);
-  assert (file != NULL);
-  /* If quota was exceeded earlier, bail out.  */
-  if (downloaded_exceeds_quota ())
-    return QUOTEXC;
-  /* Cache the current URL in the list.  */
-  if (first_time)
-    {
-      /* These three operations need to be done only once per Wget
-         run.  They should probably be at a different location.  */
-      if (!undesirable_urls)
-	undesirable_urls = make_string_hash_table (0);
-
-      hash_table_clear (undesirable_urls);
-      string_set_add (undesirable_urls, this_url);
-      /* Enter this_url to the hash table, in original and "enhanced" form.  */
-      u = url_parse (this_url, NULL);
-      if (u)
-	{
-	  string_set_add (undesirable_urls, u->url);
-	  if (opt.no_parent)
-	    base_dir = xstrdup (u->dir); /* Set the base dir.  */
-	  /* Set the canonical this_url to be sent as referer.  This
-	     problem exists only when running the first time.  */
-	  canon_this_url = xstrdup (u->url);
-	}
-      else
-	{
-	  DEBUGP (("Double yuck!  The *base* URL is broken.\n"));
-	  base_dir = NULL;
-	}
-      url_free (u);
-      depth = 1;
-      first_time = 0;
-    }
-  else
-    ++depth;
+  uerr_t status = RETROK;
 
-  if (opt.reclevel != INFINITE_RECURSION && depth > opt.reclevel)
-    /* We've exceeded the maximum recursion depth specified by the user. */
-    {
-      if (opt.page_requisites && depth <= opt.reclevel + 1)
-	/* When -p is specified, we can do one more partial recursion from the
-	   "leaf nodes" on the HTML document tree.  The recursion is partial in
-	   that we won't traverse any <A> or <AREA> tags, nor any <LINK> tags
-	   except for <LINK REL="stylesheet">. */
-	dash_p_leaf_HTML = TRUE;
-      else
-	/* Either -p wasn't specified or it was and we've already gone the one
-	   extra (pseudo-)level that it affords us, so we need to bail out. */
-	{
-	  DEBUGP (("Recursion depth %d exceeded max. depth %d.\n",
-		   depth, opt.reclevel));
-	  --depth;
-	  return RECLEVELEXC;
-	}
-    }
+  /* The queue of URLs we need to load. */
+  struct url_queue *queue = url_queue_new ();
 
-  /* Determine whether this_url is an FTP URL.  If it is, it means
-     that the retrieval is done through proxy.  In that case, FTP
-     links will be followed by default and recursion will not be
-     turned off when following them.  */
-  this_url_ftp = (url_scheme (this_url) == SCHEME_FTP);
+  /* The URLs we decided we don't want to load. */
+  struct hash_table *blacklist = make_string_hash_table (0);
 
-  /* Get the URL-s from an HTML file: */
-  url_list = get_urls_html (file, canon_this_url ? canon_this_url : this_url,
-			    dash_p_leaf_HTML, &meta_disallow_follow);
+  /* We'll need various components of this, so better get it over with
+     now. */
+  struct url *start_url_parsed = url_parse (start_url, NULL);
 
-  if (opt.use_robots && meta_disallow_follow)
-    {
-      /* The META tag says we are not to follow this file.  Respect
-         that.  */
-      free_urlpos (url_list);
-      url_list = NULL;
-    }
+  url_enqueue (queue, xstrdup (start_url), NULL, 0);
+  string_set_add (blacklist, start_url);
 
-  /* Decide what to do with each of the URLs.  A URL will be loaded if
-     it meets several requirements, discussed later.  */
-  for (cur_url = url_list; cur_url; cur_url = cur_url->next)
+  while (1)
     {
-      /* If quota was exceeded earlier, bail out.  */
+      int descend = 0;
+      char *url, *referer, *file = NULL;
+      int depth;
+      boolean dash_p_leaf_HTML = FALSE;
+
       if (downloaded_exceeds_quota ())
 	break;
-      /* Parse the URL for convenient use in other functions, as well
-	 as to get the optimized form.  It also checks URL integrity.  */
-      u = url_parse (cur_url->url, NULL);
-      if (!u)
-	{
-	  DEBUGP (("Yuck!  A bad URL.\n"));
-	  continue;
-	}
-      assert (u->url != NULL);
-      constr = xstrdup (u->url);
-
-      /* Several checkings whether a file is acceptable to load:
-	 1. check if URL is ftp, and we don't load it
-	 2. check for relative links (if relative_only is set)
-	 3. check for domain
-	 4. check for no-parent
-	 5. check for excludes && includes
-	 6. check for suffix
-	 7. check for same host (if spanhost is unset), with possible
-	 gethostbyname baggage
-	 8. check for robots.txt
-
-	 Addendum: If the URL is FTP, and it is to be loaded, only the
-	 domain and suffix settings are "stronger".
-
-	 Note that .html and (yuck) .htm will get loaded regardless of
-	 suffix rules (but that is remedied later with unlink) unless
-	 the depth equals the maximum depth.
-
-	 More time- and memory- consuming tests should be put later on
-	 the list.  */
-
-      /* inl is set if the URL we are working on (constr) is stored in
-	 undesirable_urls.  Using it is crucial to avoid unnecessary
-	 repeated continuous hits to the hash table.  */
-      inl = string_set_contains (undesirable_urls, constr);
-
-      /* If it is FTP, and FTP is not followed, chuck it out.  */
-      if (!inl)
-	if (u->scheme == SCHEME_FTP && !opt.follow_ftp && !this_url_ftp)
-	  {
-	    DEBUGP (("Uh, it is FTP but i'm not in the mood to follow FTP.\n"));
-	    string_set_add (undesirable_urls, constr);
-	    inl = 1;
-	  }
-      /* If it is absolute link and they are not followed, chuck it
-	 out.  */
-      if (!inl && u->scheme != SCHEME_FTP)
-	if (opt.relative_only && !cur_url->link_relative_p)
-	  {
-	    DEBUGP (("It doesn't really look like a relative link.\n"));
-	    string_set_add (undesirable_urls, constr);
-	    inl = 1;
-	  }
-      /* If its domain is not to be accepted/looked-up, chuck it out.  */
-      if (!inl)
-	if (!accept_domain (u))
+
+      if (status == FWRITEERR)
+	break;
+
+      /* Get the next URL from the queue. */
+
+      if (!url_dequeue (queue,
+			(const char **)&url, (const char **)&referer,
+			&depth))
+	break;
+
+      /* And download it. */
+
+      {
+	int dt = 0;
+	char *redirected = NULL;
+	int oldrec = opt.recursive;
+
+	opt.recursive = 0;
+	status = retrieve_url (url, &file, &redirected, NULL, &dt);
+	opt.recursive = oldrec;
+
+	if (redirected)
 	  {
-	    DEBUGP (("I don't like the smell of that domain.\n"));
-	    string_set_add (undesirable_urls, constr);
-	    inl = 1;
+	    xfree (url);
+	    url = redirected;
 	  }
-      /* Check for parent directory.  */
-      if (!inl && opt.no_parent
-	  /* If the new URL is FTP and the old was not, ignore
-             opt.no_parent.  */
-	  && !(!this_url_ftp && u->scheme == SCHEME_FTP))
+	if (file && status == RETROK
+	    && (dt & RETROKF) && (dt & TEXTHTML))
+	  descend = 1;
+      }
+
+      if (descend
+	  && depth >= opt.reclevel && opt.reclevel != INFINITE_RECURSION)
 	{
-	  /* Check for base_dir first.  */
-	  if (!(base_dir && frontcmp (base_dir, u->dir)))
+	  if (opt.page_requisites && depth == opt.reclevel)
+	    /* When -p is specified, we can do one more partial
+	       recursion from the "leaf nodes" on the HTML document
+	       tree.  The recursion is partial in that we won't
+	       traverse any <A> or <AREA> tags, nor any <LINK> tags
+	       except for <LINK REL="stylesheet">. */
+	    /* #### This would be the place to implement the TODO
+	       entry saying that -p should do two more hops on
+	       framesets.  */
+	    dash_p_leaf_HTML = TRUE;
+	  else
 	    {
-	      /* Failing that, check for parent dir.  */
-	      struct url *ut = url_parse (this_url, NULL);
-	      if (!ut)
-		DEBUGP (("Double yuck!  The *base* URL is broken.\n"));
-	      else if (!frontcmp (ut->dir, u->dir))
-		{
-		  /* Failing that too, kill the URL.  */
-		  DEBUGP (("Trying to escape parental guidance with no_parent on.\n"));
-		  string_set_add (undesirable_urls, constr);
-		  inl = 1;
-		}
-	      url_free (ut);
+	      /* Either -p wasn't specified or it was and we've
+		 already gone the one extra (pseudo-)level that it
+		 affords us, so we need to bail out. */
+	      DEBUGP (("Not descending further; at depth %d, max. %d.\n",
+		       depth, opt.reclevel));
+	      descend = 0;
 	    }
 	}
-      /* If the file does not match the acceptance list, or is on the
-	 rejection list, chuck it out.  The same goes for the
-	 directory exclude- and include- lists.  */
-      if (!inl && (opt.includes || opt.excludes))
+
+      /* If the downloaded document was HTML, parse it and enqueue the
+	 links it contains. */
+
+      if (descend)
 	{
-	  if (!accdir (u->dir, ALLABS))
+	  int meta_disallow_follow = 0;
+	  struct urlpos *children = get_urls_html (file, url, dash_p_leaf_HTML,
+						   &meta_disallow_follow);
+
+	  if (opt.use_robots && meta_disallow_follow)
 	    {
-	      DEBUGP (("%s (%s) is excluded/not-included.\n", constr, u->dir));
-	      string_set_add (undesirable_urls, constr);
-	      inl = 1;
+	      free_urlpos (children);
+	      children = NULL;
 	    }
-	}
-      if (!inl)
-	{
-	  char *suf = NULL;
-	  /* We check for acceptance/rejection rules only for non-HTML
-	     documents.  Since we don't know whether they really are
-	     HTML, it will be deduced from (an OR-ed list):
-
-	     1) u->file is "" (meaning it is a directory)
-	     2) suffix exists, AND:
-	     a) it is "html", OR
-	     b) it is "htm"
-
-	     If the file *is* supposed to be HTML, it will *not* be
-            subject to acc/rej rules, unless a finite maximum depth has
-            been specified and the current depth is the maximum depth. */
-	  if (!
-	      (!*u->file
-	       || (((suf = suffix (constr)) != NULL)
-                  && ((!strcmp (suf, "html") || !strcmp (suf, "htm"))
-                      && ((opt.reclevel != INFINITE_RECURSION) &&
-			  (depth != opt.reclevel))))))
+
+	  if (children)
 	    {
-	      if (!acceptable (u->file))
+	      struct urlpos *child = children;
+	      struct url *url_parsed = url_parsed = url_parse (url, NULL);
+	      assert (url_parsed != NULL);
+
+	      for (; child; child = child->next)
 		{
-		  DEBUGP (("%s (%s) does not match acc/rej rules.\n",
-			  constr, u->file));
-		  string_set_add (undesirable_urls, constr);
-		  inl = 1;
+		  if (descend_url_p (child, url_parsed, depth, start_url_parsed,
+				     blacklist))
+		    {
+		      url_enqueue (queue, xstrdup (child->url->url),
+				   xstrdup (url), depth + 1);
+		      /* We blacklist the URL we have enqueued, because we
+			 don't want to enqueue (and hence download) the
+			 same URL twice.  */
+		      string_set_add (blacklist, child->url->url);
+		    }
 		}
+
+	      url_free (url_parsed);
+	      free_urlpos (children);
 	    }
-	  FREE_MAYBE (suf);
 	}
-      /* Optimize the URL (which includes possible DNS lookup) only
-	 after all other possibilities have been exhausted.  */
-      if (!inl)
+
+      if (opt.delete_after || (file && !acceptable (file)))
 	{
-	  if (!opt.simple_check)
-	    {
-	      /* Find the "true" host.  */
-	      char *host = realhost (u->host);
-	      xfree (u->host);
-	      u->host = host;
-
-	      /* Refresh the printed representation of the URL.  */
-	      xfree (u->url);
-	      u->url = url_string (u, 0);
-	    }
-	  else
-	    {
-	      char *p;
-	      /* Just lowercase the hostname.  */
-	      for (p = u->host; *p; p++)
-		*p = TOLOWER (*p);
-	      xfree (u->url);
-	      u->url = url_string (u, 0);
-	    }
-	  xfree (constr);
-	  constr = xstrdup (u->url);
-	  /* After we have canonicalized the URL, check if we have it
-	     on the black list. */
-	  if (string_set_contains (undesirable_urls, constr))
-	    inl = 1;
-	  /* This line is bogus. */
-	  /*string_set_add (undesirable_urls, constr);*/
-
-	  if (!inl && !((u->scheme == SCHEME_FTP) && !this_url_ftp))
-	    if (!opt.spanhost && this_url && !same_host (this_url, constr))
-	      {
-		DEBUGP (("This is not the same hostname as the parent's.\n"));
-		string_set_add (undesirable_urls, constr);
-		inl = 1;
-	      }
+	  /* Either --delete-after was specified, or we loaded this
+	     otherwise rejected (e.g. by -R) HTML file just so we
+	     could harvest its hyperlinks -- in either case, delete
+	     the local file. */
+	  DEBUGP (("Removing file due to %s in recursive_retrieve():\n",
+		   opt.delete_after ? "--delete-after" :
+		   "recursive rejection criteria"));
+	  logprintf (LOG_VERBOSE,
+		     (opt.delete_after ? _("Removing %s.\n")
+		      : _("Removing %s since it should be rejected.\n")),
+		     file);
+	  if (unlink (file))
+	    logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
 	}
-      /* What about robots.txt?  */
-      if (!inl && opt.use_robots && u->scheme == SCHEME_HTTP)
+
+      xfree (url);
+      FREE_MAYBE (referer);
+      FREE_MAYBE (file);
+    }
+
+  /* If anything is left of the queue due to a premature exit, free it
+     now.  */
+  {
+    char *d1, *d2;
+    int d3;
+    while (url_dequeue (queue, (const char **)&d1, (const char **)&d2, &d3))
+      {
+	xfree (d1);
+	FREE_MAYBE (d2);
+      }
+  }
+  url_queue_delete (queue);
+
+  if (start_url_parsed)
+    url_free (start_url_parsed);
+  string_set_free (blacklist);
+
+  if (downloaded_exceeds_quota ())
+    return QUOTEXC;
+  else if (status == FWRITEERR)
+    return FWRITEERR;
+  else
+    return RETROK;
+}
+
+/* Based on the context provided by retrieve_tree, decide whether a
+   URL is to be descended to.  This is only ever called from
+   retrieve_tree, but is in a separate function for clarity.  */
+
+static int
+descend_url_p (const struct urlpos *upos, struct url *parent, int depth,
+	       struct url *start_url_parsed, struct hash_table *blacklist)
+{
+  struct url *u = upos->url;
+  const char *url = u->url;
+
+  DEBUGP (("Deciding whether to enqueue \"%s\".\n", url));
+
+  if (string_set_contains (blacklist, url))
+    {
+      DEBUGP (("Already on the black list.\n"));
+      goto out;
+    }
+
+  /* Several things to check for:
+     1. if scheme is not http, and we don't load it
+     2. check for relative links (if relative_only is set)
+     3. check for domain
+     4. check for no-parent
+     5. check for excludes && includes
+     6. check for suffix
+     7. check for same host (if spanhost is unset), with possible
+     gethostbyname baggage
+     8. check for robots.txt
+
+     Addendum: If the URL is FTP, and it is to be loaded, only the
+     domain and suffix settings are "stronger".
+
+     Note that .html files will get loaded regardless of suffix rules
+     (but that is remedied later with unlink) unless the depth equals
+     the maximum depth.
+
+     More time- and memory- consuming tests should be put later on
+     the list.  */
+
+  /* 1. Schemes other than HTTP are normally not recursed into. */
+  if (u->scheme != SCHEME_HTTP
+      && !(u->scheme == SCHEME_FTP && opt.follow_ftp))
+    {
+      DEBUGP (("Not following non-HTTP schemes.\n"));
+      goto blacklist;
+    }
+
+  /* 2. If it is an absolute link and they are not followed, throw it
+     out.  */
+  if (u->scheme == SCHEME_HTTP)
+    if (opt.relative_only && !upos->link_relative_p)
+      {
+	DEBUGP (("It doesn't really look like a relative link.\n"));
+	goto blacklist;
+      }
+
+  /* 3. If its domain is not to be accepted/looked-up, chuck it
+     out.  */
+  if (!accept_domain (u))
+    {
+      DEBUGP (("The domain was not accepted.\n"));
+      goto blacklist;
+    }
+
+  /* 4. Check for parent directory.
+
+     If we descended to a different host or changed the scheme, ignore
+     opt.no_parent.  Also ignore it for -p leaf retrievals.  */
+  if (opt.no_parent
+      && u->scheme == parent->scheme
+      && 0 == strcasecmp (u->host, parent->host)
+      && u->port == parent->port)
+    {
+      if (!frontcmp (parent->dir, u->dir))
 	{
-	  struct robot_specs *specs = res_get_specs (u->host, u->port);
-	  if (!specs)
-	    {
-	      char *rfile;
-	      if (res_retrieve_file (constr, &rfile))
-		{
-		  specs = res_parse_from_file (rfile);
-		  xfree (rfile);
-		}
-	      else
-		{
-		  /* If we cannot get real specs, at least produce
-		     dummy ones so that we can register them and stop
-		     trying to retrieve them.  */
-		  specs = res_parse ("", 0);
-		}
-	      res_register_specs (u->host, u->port, specs);
-	    }
+	  DEBUGP (("Trying to escape the root directory with no_parent in effect.\n"));
+	  goto blacklist;
+	}
+    }
 
-	  /* Now that we have (or don't have) robots.txt specs, we can
-	     check what they say.  */
-	  if (!res_match_path (specs, u->path))
-	    {
-	      DEBUGP (("Not following %s because robots.txt forbids it.\n",
-		       constr));
-	      string_set_add (undesirable_urls, constr);
-	      inl = 1;
-	    }
+  /* 5. If the file does not match the acceptance list, or is on the
+     rejection list, chuck it out.  The same goes for the directory
+     exclusion and inclusion lists.  */
+  if (opt.includes || opt.excludes)
+    {
+      if (!accdir (u->dir, ALLABS))
+	{
+	  DEBUGP (("%s (%s) is excluded/not-included.\n", url, u->dir));
+	  goto blacklist;
 	}
+    }
 
-      filename = NULL;
-      /* If it wasn't chucked out, do something with it.  */
-      if (!inl)
+  /* 6. */
+  {
+    char *suf = NULL;
+    /* Check for acceptance/rejection rules.  We ignore these rules
+       for HTML documents because they might lead to other files which
+       need to be downloaded.  Of course, we don't know which
+       documents are HTML before downloading them, so we guess.
+
+       A file is subject to acceptance/rejection rules if:
+
+       * u->file is not "" (i.e. it is not a directory)
+       and either:
+         + there is no file suffix,
+	 + or there is a suffix, but is not "html" or "htm",
+	 + both:
+	   - recursion is not infinite,
+	   - and we are at its very end. */
+
+    if (u->file[0] != '\0'
+	&& ((suf = suffix (url)) == NULL
+	    || (0 != strcmp (suf, "html") && 0 != strcmp (suf, "htm"))
+	    || (opt.reclevel == INFINITE_RECURSION && depth >= opt.reclevel)))
+      {
+	if (!acceptable (u->file))
+	  {
+	    DEBUGP (("%s (%s) does not match acc/rej rules.\n",
+		     url, u->file));
+	    FREE_MAYBE (suf);
+	    goto blacklist;
+	  }
+      }
+    FREE_MAYBE (suf);
+  }
+
+  /* 7. */
+  if (u->scheme == parent->scheme)
+    if (!opt.spanhost && 0 != strcasecmp (parent->host, u->host))
+      {
+	DEBUGP (("This is not the same hostname as the parent's (%s and %s).\n",
+		 u->host, parent->host));
+	goto blacklist;
+      }
+
+  /* 8. */
+  if (opt.use_robots && u->scheme == SCHEME_HTTP)
+    {
+      struct robot_specs *specs = res_get_specs (u->host, u->port);
+      if (!specs)
 	{
-	  DEBUGP (("I've decided to load it -> "));
-	  /* Add it to the list of already-loaded URL-s.  */
-	  string_set_add (undesirable_urls, constr);
-	  /* Automatically followed FTPs will *not* be downloaded
-	     recursively.  */
-	  if (u->scheme == SCHEME_FTP)
+	  char *rfile;
+	  if (res_retrieve_file (url, &rfile))
 	    {
-	      /* Don't you adore side-effects?  */
-	      opt.recursive = 0;
-	    }
-	  /* Reset its type.  */
-	  dt = 0;
-	  /* Retrieve it.  */
-	  retrieve_url (constr, &filename, &newloc,
-		       canon_this_url ? canon_this_url : this_url, &dt);
-	  if (u->scheme == SCHEME_FTP)
-	    {
-	      /* Restore...  */
-	      opt.recursive = 1;
-	    }
-	  if (newloc)
-	    {
-	      xfree (constr);
-	      constr = newloc;
-	    }
-	  /* If there was no error, and the type is text/html, parse
-	     it recursively.  */
-	  if (dt & TEXTHTML)
-	    {
-	      if (dt & RETROKF)
-		recursive_retrieve (filename, constr);
+	      specs = res_parse_from_file (rfile);
+	      xfree (rfile);
 	    }
 	  else
-	    DEBUGP (("%s is not text/html so we don't chase.\n",
-		     filename ? filename: "(null)"));
-
-	  if (opt.delete_after || (filename && !acceptable (filename)))
-	    /* Either --delete-after was specified, or we loaded this otherwise
-	       rejected (e.g. by -R) HTML file just so we could harvest its
-	       hyperlinks -- in either case, delete the local file. */
 	    {
-	      DEBUGP (("Removing file due to %s in recursive_retrieve():\n",
-		       opt.delete_after ? "--delete-after" :
-		       "recursive rejection criteria"));
-	      logprintf (LOG_VERBOSE,
-			 (opt.delete_after ? _("Removing %s.\n")
-			  : _("Removing %s since it should be rejected.\n")),
-			 filename);
-	      if (unlink (filename))
-		logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
-	      dt &= ~RETROKF;
+	      /* If we cannot get real specs, at least produce
+		 dummy ones so that we can register them and stop
+		 trying to retrieve them.  */
+	      specs = res_parse ("", 0);
 	    }
+	  res_register_specs (u->host, u->port, specs);
+	}
 
-	  /* If everything was OK, and links are to be converted, let's
-	     store the local filename.  */
-	  if (opt.convert_links && (dt & RETROKF) && (filename != NULL))
-	    {
-	      cur_url->convert = CO_CONVERT_TO_RELATIVE;
-	      cur_url->local_name = xstrdup (filename);
-	    }
+      /* Now that we have (or don't have) robots.txt specs, we can
+	 check what they say.  */
+      if (!res_match_path (specs, u->path))
+	{
+	  DEBUGP (("Not following %s because robots.txt forbids it.\n", url));
+	  goto blacklist;
 	}
-      else
-	DEBUGP (("%s already in list, so we don't load.\n", constr));
-      /* Free filename and constr.  */
-      FREE_MAYBE (filename);
-      FREE_MAYBE (constr);
-      url_free (u);
-      /* Increment the pbuf for the appropriate size.  */
     }
-  if (opt.convert_links && !opt.delete_after)
-    /* This is merely the first pass: the links that have been
-       successfully downloaded are converted.  In the second pass,
-       convert_all_links() will also convert those links that have NOT
-       been downloaded to their canonical form.  */
-    convert_links (file, url_list);
-  /* Free the linked list of URL-s.  */
-  free_urlpos (url_list);
-  /* Free the canonical this_url.  */
-  FREE_MAYBE (canon_this_url);
-  /* Decrement the recursion depth.  */
-  --depth;
-  if (downloaded_exceeds_quota ())
-    return QUOTEXC;
-  else
-    return RETROK;
+
+  /* The URL has passed all the tests.  It can be placed in the
+     download queue. */
+  DEBUGP (("Decided to load it.\n"));
+
+  return 1;
+
+ blacklist:
+  string_set_add (blacklist, url);
+
+ out:
+  DEBUGP (("Decided NOT to load it.\n"));
+
+  return 0;
 }
 
+/* Register that URL has been successfully downloaded to FILE. */
+
 void
 register_download (const char *url, const char *file)
 {
