             }
         }
 
+      /* Process the chosen application/metalink4+xml metaurl.  */
+      if (opt.metalink_index >= 0)
+        {
+          int _metalink_index = opt.metalink_index;
+
+          metalink_metaurl_t **murl_ptr;
+          int abs_count = 0, meta_count = 0;
+
+          uerr_t x_retr_err = METALINK_MISSING_RESOURCE;
+
+          opt.metalink_index = -1;
+
+          DEBUGP (("Searching application/metalink4+xml ordinal number %d...\n", _metalink_index));
+
+          if (mfile->metaurls && mfile->metaurls[0])
+            for (murl_ptr = mfile->metaurls; *murl_ptr; murl_ptr++)
+              {
+                metalink_t* metaurl_xml;
+                metalink_error_t meta_err;
+                metalink_metaurl_t *murl = *murl_ptr;
+
+                char *_dir_prefix = opt.dir_prefix;
+                char *_input_metalink = opt.input_metalink;
+
+                char *metafile = NULL;
+                char *metadest = NULL;
+                char *metadir = NULL;
+
+                abs_count++;
+
+                if (strcmp (murl->mediatype, "application/metalink4+xml"))
+                  continue;
+
+                meta_count++;
+
+                DEBUGP (("  Ordinal number %d: %s\n", meta_count, quote (murl->url)));
+
+                if (_metalink_index > 0)
+                  {
+                    if (meta_count < _metalink_index)
+                      continue;
+                    else if (meta_count > _metalink_index)
+                      break;
+                  }
+
+                logprintf (LOG_NOTQUIET,
+                           _("Processing metaurl %s...\n"), quote (murl->url));
+
+                /* Metalink/XML download file name.  */
+                metafile = xstrdup (safename);
+
+                if (opt.trustservernames)
+                  replace_metalink_basename (&metafile, murl->url);
+                else
+                  append_suffix_number (&metafile, ".meta#", meta_count);
+
+                if (!metalink_check_safe_path (metafile))
+                  {
+                    logprintf (LOG_NOTQUIET,
+                               _("Rejecting metaurl file %s. Unsafe name.\n"),
+                               quote (metafile));
+                    xfree (metafile);
+                    if (_metalink_index > 0)
+                      break;
+                    continue;
+                  }
+
+                /* For security reasons, always save metalink metaurl
+                   files as new unique files. Keep them on failure.  */
+                x_retr_err = fetch_metalink_file (murl->url, false, false,
+                                                  metafile, &metadest);
+
+                /* On failure, try the next metalink metaurl.  */
+                if (x_retr_err != RETROK)
+                  {
+                    logprintf (LOG_VERBOSE,
+                               _("Failed to download %s. Skipping metaurl.\n"),
+                               quote (metadest ? metadest : metafile));
+                    inform_exit_status (x_retr_err);
+                    xfree (metadest);
+                    xfree (metafile);
+                    if (_metalink_index > 0)
+                      break;
+                    continue;
+                  }
+
+                /* Parse Metalink/XML.  */
+                meta_err = metalink_parse_file (metadest, &metaurl_xml);
+
+                /* On failure, try the next metalink metaurl.  */
+                if (meta_err)
+                  {
+                    logprintf (LOG_NOTQUIET,
+                               _("Unable to parse metaurl file %s.\n"), quote (metadest));
+                    x_retr_err = METALINK_PARSE_ERROR;
+                    inform_exit_status (x_retr_err);
+                    xfree (metadest);
+                    xfree (metafile);
+                    if (_metalink_index > 0)
+                      break;
+                    continue;
+                  }
+
+                /* We need to sort the resources if preferred location
+                   was specified by the user.  */
+                if (opt.preferred_location && opt.preferred_location[0])
+                  {
+                    metalink_file_t **x_mfile_ptr;
+                    for (x_mfile_ptr = metaurl_xml->files; *x_mfile_ptr; x_mfile_ptr++)
+                      {
+                        metalink_resource_t **x_mres_ptr;
+                        metalink_file_t *x_mfile = *x_mfile_ptr;
+                        size_t mres_count = 0;
+
+                        for (x_mres_ptr = x_mfile->resources; *x_mres_ptr; x_mres_ptr++)
+                          mres_count++;
+
+                        stable_sort (x_mfile->resources,
+                                     mres_count,
+                                     sizeof (metalink_resource_t *),
+                                     metalink_res_cmp);
+                      }
+                  }
+
+                /* Insert the current "Directory Options".  */
+                if (metalink->origin)
+                  {
+                    /* WARNING: Do not use lib/dirname.c (dir_name) to
+                       get the directory name, it may append a dot '.'
+                       character to the directory name. */
+                    metadir = xstrdup (planname);
+                    replace_metalink_basename (&metadir, NULL);
+                  }
+                else
+                  {
+                    metadir = xstrdup (opt.dir_prefix);
+                  }
+
+                opt.dir_prefix = metadir;
+                opt.input_metalink = metadest;
+
+                x_retr_err = retrieve_from_metalink (metaurl_xml);
+
+                if (x_retr_err != RETROK)
+                  logprintf (LOG_NOTQUIET,
+                             _("Could not download all resources from %s.\n"),
+                             quote (metadest));
+
+                metalink_delete (metaurl_xml);
+                metaurl_xml = NULL;
+
+                opt.input_metalink = _input_metalink;
+                opt.dir_prefix = _dir_prefix;
+
+                xfree (metadir);
+                xfree (metadest);
+                xfree (metafile);
+
+                break;
+              }
+
+          if (x_retr_err != RETROK)
+            logprintf (LOG_NOTQUIET, _("Metaurls processing returned with error.\n"));
+
+          xfree (destname);
+          xfree (filename);
+          xfree (trsrname);
+          xfree (planname);
+
+          opt.output_document = _output_document;
+          output_stream_regular = _output_stream_regular;
+          output_stream = _output_stream;
+
+          opt.metalink_index = _metalink_index;
+
+          return x_retr_err;
+        }
+
       /* Resources are sorted by priority.  */
       for (mres_ptr = mfile->resources; *mres_ptr && !skip_mfile; mres_ptr++)
         {
