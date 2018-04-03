       if (outfile == 0)
 	pfatal_with_name (comname);
 
-      fprintf (outfile, "$ ");
-      c = cmd;
+      if (ifile[0])
+	{
+	  fprintf (outfile, "$ assign/user %s sys$input\n", ifile);
+          DB (DB_JOBS, (_("Redirected input from %s\n"), ifile));
+	  ifiledsc.dsc$w_length = 0;
+	}
+
+      if (efile[0])
+	{
+	  fprintf (outfile, "$ define sys$error %s\n", efile);
+          DB (DB_JOBS, (_("Redirected error to %s\n"), efile));
+	  efiledsc.dsc$w_length = 0;
+	}
+
+      if (ofile[0])
+	{
+	  fprintf (outfile, "$ define sys$output %s\n", ofile);
+	  DB (DB_JOBS, (_("Redirected output to %s\n"), ofile));
+	  ofiledsc.dsc$w_length = 0;
+	}
 
-      while (c)
+      p = sep = q = cmd;
+      for (c = '\n'; c; c = *q++)
 	{
-	  p = strchr (c, ',');
-	  if ((p == NULL) || (p-c > MAXCMDLEN))
-	    p = strchr (c, ' ');
-	  if (p != NULL)
+	  switch (c)
 	    {
-	      p++;
-	      tmp = *p;
-	      *p = '\0';
+            case '\n':
+              /* At a newline, skip any whitespace around a leading $
+                 from the command and issue exactly one $ into the DCL. */
+              while (isspace (*p))
+                p++;
+              if (*p == '$')
+                p++;
+              while (isspace (*p))
+                p++;
+              fwrite (p, 1, q - p, outfile);
+              fputc ('$', outfile);
+              fputc (' ', outfile);
+              /* Reset variables. */
+              p = sep = q;
+              break;
+
+	      /* Nice places for line breaks are after strings, after
+		 comma or space and before slash. */
+            case '"':
+              q = handle_apos (q + 1);
+              sep = q;
+              break;
+            case ',':
+            case ' ':
+              sep = q;
+              break;
+            case '/':
+            case '\0':
+              sep = q - 1;
+              break;
+            default:
+              break;
 	    }
-	  else
-	    tmp = '\0';
-	  fprintf (outfile, "%s%s\n", c, (tmp == '\0')?"":" -");
-	  if (p != NULL)
-	    *p = tmp;
-	  c = p;
-	}
+	  if (sep - p > 78)
+	    {
+	      /* Enough stuff for a line. */
+	      fwrite (p, 1, sep - p, outfile);
+	      p = sep;
+	      if (*sep)
+		{
+		  /* The command continues.  */
+		  fputc ('-', outfile);
+		}
+	      fputc ('\n', outfile);
+	    }
+  	}
+
+      fwrite (p, 1, q - p, outfile);
+      fputc ('\n', outfile);
 
       fclose (outfile);
 
