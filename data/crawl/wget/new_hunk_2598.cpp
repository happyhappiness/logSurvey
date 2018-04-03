      bool dash_p_leaf_HTML = false;

      if (opt.quota && total_downloaded_bytes > opt.quota)
        break;
      if (status == FWRITEERR)
        break;

      /* Get the next URL from the queue... */

      if (!url_dequeue (queue,
                        (const char **)&url, (const char **)&referer,
                        &depth, &html_allowed))
        break;

      /* ...and download it.  Note that this download is in most cases
         unconditional, as download_child_p already makes sure a file
         doesn't get enqueued twice -- and yet this check is here, and
         not in download_child_p.  This is so that if you run `wget -r
         URL1 URL2', and a random URL is encountered once under URL1
         and again under URL2, but at a different (possibly smaller)
         depth, we want the URL's children to be taken into account
         the second time.  */
      if (dl_url_file_map && hash_table_contains (dl_url_file_map, url))
        {
          file = xstrdup (hash_table_get (dl_url_file_map, url));

          DEBUGP (("Already downloaded \"%s\", reusing it from \"%s\".\n",
                   url, file));

          if (html_allowed
              && downloaded_html_set
              && string_set_contains (downloaded_html_set, file))
            descend = true;
        }
      else
        {
          int dt = 0;
          char *redirected = NULL;

          status = retrieve_url (url, &file, &redirected, referer, &dt, false);

          if (html_allowed && file && status == RETROK
              && (dt & RETROKF) && (dt & TEXTHTML))
            descend = true;

          if (redirected)
            {
              /* We have been redirected, possibly to another host, or
                 different path, or wherever.  Check whether we really
                 want to follow it.  */
              if (descend)
                {
                  if (!descend_redirect_p (redirected, url, depth,
                                           start_url_parsed, blacklist))
                    descend = false;
                  else
                    /* Make sure that the old pre-redirect form gets
                       blacklisted. */
                    string_set_add (blacklist, url);
                }

              xfree (url);
              url = redirected;
            }
        }

      if (opt.spider)
        {
          visited_url (url, referer);
        }

      if (descend
          && depth >= opt.reclevel && opt.reclevel != INFINITE_RECURSION)
        {
          if (opt.page_requisites
              && (depth == opt.reclevel || depth == opt.reclevel + 1))
            {
              /* When -p is specified, we are allowed to exceed the
                 maximum depth, but only for the "inline" links,
                 i.e. those that are needed to display the page.
                 Originally this could exceed the depth at most by
                 one, but we allow one more level so that the leaf
                 pages that contain frames can be loaded
                 correctly.  */
              dash_p_leaf_HTML = true;
            }
          else
            {
              /* Either -p wasn't specified or it was and we've
                 already spent the two extra (pseudo-)levels that it
                 affords us, so we need to bail out. */
              DEBUGP (("Not descending further; at depth %d, max. %d.\n",
                       depth, opt.reclevel));
              descend = false;
            }
        }

      /* If the downloaded document was HTML, parse it and enqueue the
         links it contains. */

      if (descend)
        {
          bool meta_disallow_follow = false;
          struct urlpos *children
            = get_urls_html (file, url, &meta_disallow_follow);

          if (opt.use_robots && meta_disallow_follow)
            {
              free_urlpos (children);
              children = NULL;
            }

          if (children)
            {
              struct urlpos *child = children;
              struct url *url_parsed = url_parsed = url_parse (url, NULL);
              char *referer_url = url;
              bool strip_auth = url_parsed->user;
              assert (url_parsed != NULL);

              /* Strip auth info if present */
              if (strip_auth)
                referer_url = url_string (url_parsed, URL_AUTH_HIDE);

              for (; child; child = child->next)
                {
                  if (child->ignore_when_downloading)
                    continue;
                  if (dash_p_leaf_HTML && !child->link_inline_p)
                    continue;
                  if (download_child_p (child, url_parsed, depth, start_url_parsed,
                                        blacklist))
                    {
                      url_enqueue (queue, xstrdup (child->url->url),
                                   xstrdup (referer_url), depth + 1,
                                   child->link_expect_html);
                      /* We blacklist the URL we have enqueued, because we
                         don't want to enqueue (and hence download) the
                         same URL twice.  */
                      string_set_add (blacklist, child->url->url);
                    }
                }

              if (strip_auth)
                xfree (referer_url);
              url_free (url_parsed);
              free_urlpos (children);
            }
        }

      if (file 
          && (opt.delete_after 
              || opt.spider /* opt.recursive is implicitely true */
              || !acceptable (file)))
        {
          /* Either --delete-after was specified, or we loaded this
             (otherwise unneeded because of --spider or rejected by -R) 
             HTML file just to harvest its hyperlinks -- in either case, 
             delete the local file. */
          DEBUGP (("Removing file due to %s in recursive_retrieve():\n",
                   opt.delete_after ? "--delete-after" :
                   (opt.spider ? "--spider" : 
                    "recursive rejection criteria")));
          logprintf (LOG_VERBOSE,
                     (opt.delete_after || opt.spider
                      ? _("Removing %s.\n")
                      : _("Removing %s since it should be rejected.\n")),
                     file);
          if (unlink (file))
            logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
          logputs (LOG_VERBOSE, "\n");
          register_delete_file (file);
        }

      xfree (url);
      xfree_null (referer);
