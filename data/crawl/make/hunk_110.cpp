          verify". However, the prolog and epilog commands are not shown. Also,
          if output redirection is used, the verification output is redirected
          into that file as well. */
-      fprintf (outfile, "$ %.*s_1 = \"''f$verify(0)'\"\n", tmpstrlen, tmpstr);
-      if (ifile[0])
-        {
-          fprintf (outfile, "$ assign/user %s sys$input\n", ifile);
-          DB (DB_JOBS, (_("Redirected input from %s\n"), ifile));
-          ifiledsc.dsc$w_length = 0;
-        }
+      fprintf (outfile, "$ gnv$$make_verify = \"''f$verify(0)'\"\n");
+      fprintf (outfile, "$ gnv$$make_pid = f$getjpi(\"\",\"pid\")\n");
+      fprintf (outfile, "$ on error then $ goto gnv$$make_error\n");
 
-      if (efile[0])
+      /* Handle append redirection */
+      if (append_file != NULL)
         {
-          fprintf (outfile, "$ define sys$error %s\n", efile);
-          DB (DB_JOBS, (_("Redirected error to %s\n"), efile));
-          efiledsc.dsc$w_length = 0;
+          /* If file does not exist, create it */
+          fprintf (outfile,
+                   "$ gnv$$make_al = \"gnv$$make_append''gnv$$make_pid'\"\n");
+          fprintf (outfile,
+                   "$ if f$search(\"%s\") .eqs. \"\" then create %s\n",
+                   append_file, append_file);
+
+          fprintf (outfile,
+                   "$ open/append 'gnv$$make_al' %s\n", append_file);
+
+          /* define sys$output to that file */
+          fprintf (outfile,
+                   "$ define/user sys$output 'gnv$$make_al'\n");
+          DB (DB_JOBS, (_("Append output to %s\n"), append_file));
+          free(append_file);
         }
 
-      if (ofile[0])
-        if (have_append)
-          {
-            fprintf (outfile, "$ define sys$output %.*s\n", comnamelen-3, child->comname);
-            fprintf (outfile, "$ on error then $ goto %.*s\n", tmpstrlen, tmpstr);
-            DB (DB_JOBS, (_("Append output to %s\n"), ofile));
-            ofiledsc.dsc$w_length = 0;
-          }
-        else
-          {
-            fprintf (outfile, "$ define sys$output %s\n", ofile);
-            DB (DB_JOBS, (_("Redirected output to %s\n"), ofile));
-            ofiledsc.dsc$w_length = 0;
-          }
-
-      /* Export the child environment into DCL symbols */
-      if (vms_always_use_cmd_file || (child->environment != 0))
-        {
-          char **ep = child->environment;
-          char *valstr;
-          while (*ep != 0)
-            {
-              valstr = strchr(*ep, '=');
-              if (valstr == NULL)
-                continue;
-              fprintf(outfile, "$ %.*s=\"%s\"\n", valstr - *ep, *ep,
-                  valstr + 1);
-              ep++;
-            }
-        }
+      fprintf (outfile, "$ gnv$$make_verify = f$verify(gnv$$make_verify)\n");
 
-      fprintf (outfile, "$ %.*s_ = f$verify(%.*s_1)\n", tmpstrlen, tmpstr, tmpstrlen, tmpstr);
-
-      /* TODO: give 78 a name! Whether 78 is a good number is another question.
-         Trim, split and write the command lines.
-         Splitting of a command is done after 78 output characters at an
-         appropriate place (after strings, after comma or space and
-         before slash): appending a hyphen indicates that the DCL command
-         is being continued.
-         Trimming is to skip any whitespace around - including - a
-         leading $ from the command to ensure writing exactly one "$ "
-         at the beginning of the line of the output file. Trimming is
-         done when a new command is seen, indicated by a '\n' (outside
-         of a string).
-         The buffer so far is written and reset, when a new command is
-         seen, when a split was done and at the end of the command.
+      /* TODO:
          Only for ONESHELL there will be several commands separated by
-         '\n'. But there can always be multiple continuation lines. */
-      p = sep = q = cmd;
-      for (c = '\n'; c; c = *q++)
-        {
-          switch (c)
-          {
-          case '\n':
-            if (q > p)
-              {
-                fwrite(p, 1, q - p, outfile);
-                p = q;
-              }
-            fputc('$', outfile);
-            fputc(' ', outfile);
-            while (isspace((unsigned char) *p))
-              p++;
-            if (*p == '$')
-              p++;
-            while (isspace((unsigned char) *p))
-              p++;
-            q = sep = p;
-            break;
-          case '"':
-            q = vms_handle_apos(q);
-            sep = q;
-            break;
-          case ',':
-          case ' ':
-            sep = q;
-            break;
-          case '/':
-          case '\0':
-            sep = q - 1;
-            break;
-          default:
-            break;
-          }
-          if (sep - p > 78)
-            {
-              /* Enough stuff for a line. */
-              fwrite(p, 1, sep - p, outfile);
-              p = sep;
-              if (*sep)
-                {
-                  /* The command continues.  */
-                  fputc('-', outfile);
-                }
-              fputc('\n', outfile);
-            }
-        }
+         '\n'. But there can always be multiple continuation lines.
+      */
 
-      if (*p)
-        {
-          fwrite(p, 1, --q - p, outfile);
-          fputc('\n', outfile);
-        }
+      fprintf (outfile, "%s\n", cmd_dsc->dsc$a_pointer);
+      fprintf (outfile, "$ gnv$$make_status_2 = $status\n");
+      fprintf (outfile, "$ goto gnv$$make_exit\n");
+
+      /* Exit and clean up */
+      fprintf (outfile, "$ gnv$$make_error: ! 'f$verify(0)\n");
+      fprintf (outfile, "$ gnv$$make_status_2 = $status\n");
 
-      if (have_append)
+      if (append_token != -1)
         {
-          fprintf (outfile, "$ %.*s: ! 'f$verify(0)\n", tmpstrlen, tmpstr);
-          fprintf (outfile, "$ %.*s_2 = $status\n", tmpstrlen, tmpstr);
-          fprintf (outfile, "$ on error then $ exit\n");
           fprintf (outfile, "$ deassign sys$output\n");
-          if (efile[0])
-            fprintf (outfile, "$ deassign sys$error\n");
-          fprintf (outfile, "$ append:=append\n");
-          fprintf (outfile, "$ delete:=delete\n");
-          fprintf (outfile, "$ append/new %.*s %s\n", comnamelen-3, child->comname, ofile);
-          fprintf (outfile, "$ delete %.*s;*\n", comnamelen-3, child->comname);
-          fprintf (outfile, "$ exit '%.*s_2 + (0*f$verify(%.*s_1))\n", tmpstrlen, tmpstr, tmpstrlen, tmpstr);
-          DB (DB_JOBS, (_("Append %.*s and cleanup\n"), comnamelen-3, child->comname));
+          fprintf (outfile, "$ close 'gnv$$make_al'\n");
+
+          DB (DB_JOBS,
+              (_("Append %.*s and cleanup\n"), comnamelen-3, child->comname));
         }
+      fprintf (outfile, "$ gnv$$make_exit: ! 'f$verify(0)\n");
+      fprintf (outfile,
+             "$ exit 'gnv$$make_status_2' + (0*f$verify(gnv$$make_verify))\n");
 
       fclose (outfile);
 
-      sprintf (cmd, "$ @%s", child->comname);
+      free (cmd_dsc->dsc$a_pointer);
+      cmd_dsc->dsc$a_pointer = xmalloc (256 + 4);
+      sprintf (cmd_dsc->dsc$a_pointer, "$ @%s", child->comname);
+      cmd_dsc->dsc$w_length = strlen (cmd_dsc->dsc$a_pointer);
 
-      DB (DB_JOBS, (_("Executing %s instead\n"), cmd));
+      DB (DB_JOBS, (_("Executing %s instead\n"), child->comname));
     }
 
-  cmddsc.dsc$w_length = strlen(cmd);
-  cmddsc.dsc$a_pointer = cmd;
-  cmddsc.dsc$b_dtype = DSC$K_DTYPE_T;
-  cmddsc.dsc$b_class = DSC$K_CLASS_S;
-
   child->efn = 0;
   while (child->efn < 32 || child->efn > 63)
     {
-      status = lib$get_ef ((unsigned long *)&child->efn);
-      if (!(status & 1))
+      status = LIB$GET_EF ((unsigned long *)&child->efn);
+      if (!$VMS_STATUS_SUCCESS (status))
         {
           if (child->comname)
             {
