 
       if (*p)
         {
-          fwrite (p, 1, --q - p, outfile);
-          fputc ('\n', outfile);
+          /* At the end of the line, skip any whitespace around a leading $
+             from the command because one $ was already written into the DCL. */
+          while (isspace((unsigned char) *p))
+            p++;
+          if (*p == '$')
+            p++;
+          while (isspace((unsigned char) *p))
+            p++;
+          fwrite(p, 1, --q - p, outfile);
+          fputc('\n', outfile);
         }
 
       if (have_append)
         {
-          fprintf (outfile, "$ deassign sys$output ! 'f$verify(0)\n");
+          fprintf (outfile, "$ %.*s: ! 'f$verify(0)\n", tmpstrlen, tmpstr);
+          fprintf (outfile, "$ %.*s_2 = $status\n", tmpstrlen, tmpstr);
+          fprintf (outfile, "$ on error then $ exit\n");
+          fprintf (outfile, "$ deassign sys$output\n");
+          if (efile[0])
+            fprintf (outfile, "$ deassign sys$error\n");
           fprintf (outfile, "$ append:=append\n");
           fprintf (outfile, "$ delete:=delete\n");
           fprintf (outfile, "$ append/new %.*s %s\n", comnamelen-3, child->comname, ofile);
           fprintf (outfile, "$ delete %.*s;*\n", comnamelen-3, child->comname);
+          fprintf (outfile, "$ exit '%.*s_2 + (0*f$verify(%.*s_1))\n", tmpstrlen, tmpstr, tmpstrlen, tmpstr);
           DB (DB_JOBS, (_("Append %.*s and cleanup\n"), comnamelen-3, child->comname));
         }
 
