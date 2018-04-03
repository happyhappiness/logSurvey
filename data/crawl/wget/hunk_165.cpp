       return RETRFINISHED;
     }
 
-/* 2005-06-17 SMS.
-   For VMS, define common fopen() optional arguments.
-*/
-#ifdef __VMS
-# define FOPEN_OPT_ARGS "fop=sqo", "acc", acc_cb, &open_id
-# define FOPEN_BIN_FLAG 3
-#else /* def __VMS */
-# define FOPEN_BIN_FLAG true
-#endif /* def __VMS [else] */
-
-  /* Open the local file.  */
-  if (!output_stream)
+  err = open_output_stream (hs, count, &fp);
+  if (err != RETROK)
     {
-      mkalldirs (hs->local_file);
-      if (opt.backups)
-        rotate_backups (hs->local_file);
-      if (hs->restval)
-        {
-#ifdef __VMS
-          int open_id;
-
-          open_id = 21;
-          fp = fopen (hs->local_file, "ab", FOPEN_OPT_ARGS);
-#else /* def __VMS */
-          fp = fopen (hs->local_file, "ab");
-#endif /* def __VMS [else] */
-        }
-      else if (ALLOW_CLOBBER || count > 0)
-        {
-          if (opt.unlink && file_exists_p (hs->local_file))
-            {
-              if (unlink (hs->local_file) < 0)
-                {
-                  logprintf (LOG_NOTQUIET, "%s: %s\n", hs->local_file,
-                             strerror (errno));
-                  CLOSE_INVALIDATE (sock);
-                  xfree (head);
-                  xfree (type);
-                  return UNLINKERR;
-                }
-            }
-
-#ifdef __VMS
-          int open_id;
-
-          open_id = 22;
-          fp = fopen (hs->local_file, "wb", FOPEN_OPT_ARGS);
-#else /* def __VMS */
-          fp = fopen (hs->local_file, "wb");
-#endif /* def __VMS [else] */
-        }
-      else
-        {
-          fp = fopen_excl (hs->local_file, FOPEN_BIN_FLAG);
-          if (!fp && errno == EEXIST)
-            {
-              /* We cannot just invent a new name and use it (which is
-                 what functions like unique_create typically do)
-                 because we told the user we'd use this name.
-                 Instead, return and retry the download.  */
-              logprintf (LOG_NOTQUIET,
-                         _("%s has sprung into existence.\n"),
-                         hs->local_file);
-              CLOSE_INVALIDATE (sock);
-              xfree (head);
-              xfree (type);
-              return FOPEN_EXCL_ERR;
-            }
-        }
-      if (!fp)
-        {
-          logprintf (LOG_NOTQUIET, "%s: %s\n", hs->local_file, strerror (errno));
-          CLOSE_INVALIDATE (sock);
-          xfree (head);
-          xfree (type);
-          return FOPENERR;
-        }
+      xfree (type);
+      xfree (head);
+      CLOSE_INVALIDATE (sock);
+      return err;
     }
-  else
-    fp = output_stream;
-
-  /* Print fetch message, if opt.verbose.  */
-      logprintf (LOG_VERBOSE, _("Saving to: %s\n"),
-                 HYPHENP (hs->local_file) ? quote ("STDOUT") : quote (hs->local_file));
-
 
   err = read_response_body (hs, sock, fp, contlen, contrange,
                             chunked_transfer_encoding,
