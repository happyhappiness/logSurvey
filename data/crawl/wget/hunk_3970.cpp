     {
       logprintf (LOG_NOTQUIET, _("Cannot convert links in %s: %s\n"),
 		 file, strerror (errno));
-      free (buf);
+      read_file_free (fm);
       return;
     }
-  /* Presumably we have to loop through multiple URLs here (even though we're
-     only talking about a single local file) because of the -O option. */
-  for (p = buf; l; l = l->next)
+  /* Here we loop through all the URLs in file, replacing those of
+     them that are downloaded with relative references.  */
+  p = fm->content;
+  for (; l; l = l->next)
     {
-      if (l->pos >= size)
+      char *url_start = fm->content + l->pos;
+      if (l->pos >= fm->length)
 	{
 	  DEBUGP (("Something strange is going on.  Please investigate."));
 	  break;
 	}
-      /* If the URL already is relative or it is not to be converted
-	 for some other reason (e.g. because of not having been
-	 downloaded in the first place), skip it.  */
-      if ((l->flags & URELATIVE) || !(l->flags & UABS2REL))
+      /* If the URL is not to be converted, skip it.  */
+      if (!(l->flags & (UABS2REL | UREL2ABS)))
 	{
 	  DEBUGP (("Skipping %s at position %d (flags %d).\n", l->url,
 		   l->pos, l->flags));
 	  continue;
 	}
-      /* Else, reach the position of the offending URL, echoing
-	 everything up to it to the outfile.  */
-      for (p2 = buf + l->pos; p < p2; p++)
-	putc (*p, fp);
+
+      /* Echo the file contents, up to the offending URL's opening
+         quote, to the outfile.  */
+      fwrite (p, 1, url_start - p, fp);
+      p = url_start;
       if (l->flags & UABS2REL)
-	/* Convert absolute URL to relative. */
 	{
+	  /* Convert absolute URL to relative. */
 	  char *newname = construct_relative (file, l->local_name);
-	  fprintf (fp, "%s", newname);
+	  putc (*p, fp);	/* quoting char */
+	  fputs (newname, fp);
+	  p += l->size - 1;
+	  putc (*p, fp);	/* close quote */
+	  ++p;
 	  DEBUGP (("ABS2REL: %s to %s at position %d in %s.\n",
 		   l->url, newname, l->pos, file));
 	  free (newname);
 	}
-      p += l->size;
+      else if (l->flags & UREL2ABS)
+	{
+	  /* Convert the link to absolute URL. */
+	  char *newlink = l->url;
+	  putc (*p, fp);	/* quoting char */
+	  fputs (newlink, fp);
+	  p += l->size - 1;
+	  putc (*p, fp);	/* close quote */
+	  ++p;
+	  DEBUGP (("REL2ABS: <something> to %s at position %d in %s.\n",
+		   newlink, l->pos, file));
+	}
     }
   /* Output the rest of the file. */
-  if (p - buf < size)
-    {
-      for (p2 = buf + size; p < p2; p++)
-	putc (*p, fp);
-    }
+  if (p - fm->content < fm->length)
+    fwrite (p, 1, fm->length - (p - fm->content), fp);
   fclose (fp);
-  free (buf);
+  read_file_free (fm);
   logputs (LOG_VERBOSE, _("done.\n"));
 }
 
