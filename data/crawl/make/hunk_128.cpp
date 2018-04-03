         }
 
       outfile = output_tmpfile (&child->comname, "sys$scratch:CMDXXXXXX.COM");
+      /*                                          012345678901234567890 */
+#define TMP_OFFSET 12
+#define TMP_LEN 9
       if (outfile == 0)
         pfatal_with_name (_("fopen (temporary file)"));
       comnamelen = strlen (child->comname);
-
+      tmpstr = &child->comname[TMP_OFFSET];
+      tmpstrlen = TMP_LEN;
+      /* The whole DCL "script" is executed as one action, and it behaves as
+         any DCL "script", that is errors stop it but warnings do not. Usually
+         the command on the last line, defines the exit code.  However, with
+         redirections there is a prolog and possibly an epilog to implement
+         the redirection.  Both are part of the script which is actually
+         executed. So if the redirection encounters an error in the prolog,
+         the user actions will not run; if in the epilog, the user actions
+         ran, but output is not captured. In both error cases, the error of
+         redirection is passed back and not the exit code of the actions. The
+         user should be able to enable DCL "script" verification with "set
+         verify". However, the prolog and epilog commands are not shown. Also,
+         if output redirection is used, the verification output is redirected
+         into that file as well. */
+      fprintf (outfile, "$ %.*s_1 = \"''f$verify(0)'\"\n", tmpstrlen, tmpstr);
       if (ifile[0])
         {
           fprintf (outfile, "$ assign/user %s sys$input\n", ifile);
