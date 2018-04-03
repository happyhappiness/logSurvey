 
   if (!replaced_filename)
     {
-      /* Add the file name. */
-      if (fnres.tail)
-	append_char ('/', &fnres);
+      /* Create the filename. */
       u_file = *u->file ? u->file : index_filename;
-      append_uri_pathel (u_file, u_file + strlen (u_file), false, &fnres);
 
-      /* Append "?query" to the file name, even if empty */
+      /* Append "?query" to the file name, even if empty,
+       * and create fname_len_check. */
       if (u->query)
-	{
-	  append_char (FN_QUERY_SEP, &fnres);
-	  append_uri_pathel (u->query, u->query + strlen (u->query),
-			     true, &fnres);
-	}
+        fname_len_check = concat_strings (u_file, FN_QUERY_SEP_STR, u->query, NULL);
+      else
+        fname_len_check = strdupdelim (u_file, u_file + strlen (u_file));
     }
   else
     {
-      if (fnres.tail)
-	append_char ('/', &fnres);
       u_file = replaced_filename;
-      append_uri_pathel (u_file, u_file + strlen (u_file), false, &fnres);
+      fname_len_check = strdupdelim (u_file, u_file + strlen (u_file));
     }
 
+  append_uri_pathel (fname_len_check,
+    fname_len_check + strlen (fname_len_check), false, &temp_fnres);
+
+  /* Zero-terminate the temporary file name. */
+  append_char ('\0', &temp_fnres);
+
+  /* Check that the length of the file name is acceptable. */
+  max_length = get_max_length (fnres.base, fnres.tail, _PC_NAME_MAX) - CHOMP_BUFFER;
+  if (max_length > 0 && strlen (temp_fnres.base) > max_length)
+    {
+      logprintf (LOG_NOTQUIET, "The name is too long, %lu chars total.\n",
+          (unsigned long) strlen (temp_fnres.base));
+      logprintf (LOG_NOTQUIET, "Trying to shorten...\n");
+
+      /* Shorten the file name. */
+      temp_fnres.base[max_length] = '\0';
+
+      logprintf (LOG_NOTQUIET, "New name is %s.\n", temp_fnres.base);
+    }
+
+  free (fname_len_check);
+
+  /* The filename has already been 'cleaned' by append_uri_pathel() above.  So,
+   * just append it. */
+  if (fnres.tail)
+    append_char ('/', &fnres);
+  append_string (temp_fnres.base, &fnres);
+
   /* Zero-terminate the file name. */
   append_char ('\0', &fnres);
 
   fname = fnres.base;
 
+  /* Make a final check that the path length is acceptable? */
+  /* TODO: check fnres.base for path length problem */
+
+  free (temp_fnres.base);
+
   /* Check the cases in which the unique extensions are not used:
      1) Clobbering is turned off (-nc).
      2) Retrieval with regetting.
