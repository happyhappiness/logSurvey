       int dt;
 
       if (cur_url->ignore_when_downloading)
-	continue;
+        continue;
 
       if (opt.quota && total_downloaded_bytes > opt.quota)
-	{
-	  status = QUOTEXC;
-	  break;
-	}
+        {
+          status = QUOTEXC;
+          break;
+        }
       if ((opt.recursive || opt.page_requisites)
-	  && (cur_url->url->scheme != SCHEME_FTP || getproxy (cur_url->url)))
-      	{
-	  int old_follow_ftp = opt.follow_ftp;
-
-	  /* Turn opt.follow_ftp on in case of recursive FTP retrieval */
-	  if (cur_url->url->scheme == SCHEME_FTP) 
-	    opt.follow_ftp = 1;
-	  
-	  status = retrieve_tree (cur_url->url->url);
-
-	  opt.follow_ftp = old_follow_ftp;
-	}
+          && (cur_url->url->scheme != SCHEME_FTP || getproxy (cur_url->url)))
+        {
+          int old_follow_ftp = opt.follow_ftp;
+
+          /* Turn opt.follow_ftp on in case of recursive FTP retrieval */
+          if (cur_url->url->scheme == SCHEME_FTP) 
+            opt.follow_ftp = 1;
+          
+          status = retrieve_tree (cur_url->url->url);
+
+          opt.follow_ftp = old_follow_ftp;
+        }
       else
-	status = retrieve_url (cur_url->url->url, &filename, &new_file, NULL, &dt, opt.recursive);
+        status = retrieve_url (cur_url->url->url, &filename, &new_file, NULL, &dt, opt.recursive);
 
       if (filename && opt.delete_after && file_exists_p (filename))
-	{
-	  DEBUGP (("\
+        {
+          DEBUGP (("\
 Removing file due to --delete-after in retrieve_from_file():\n"));
-	  logprintf (LOG_VERBOSE, _("Removing %s.\n"), filename);
-	  if (unlink (filename))
-	    logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
-	  dt &= ~RETROKF;
-	}
+          logprintf (LOG_VERBOSE, _("Removing %s.\n"), filename);
+          if (unlink (filename))
+            logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
+          dt &= ~RETROKF;
+        }
 
       xfree_null (new_file);
       xfree_null (filename);
