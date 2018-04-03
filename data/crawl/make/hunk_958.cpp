 {
   int i;
   static struct dsc$descriptor_s cmddsc;
-#ifndef DONTWAITFORCHILD
-  int spflags = 0;
-#else
+  static struct dsc$descriptor_s pnamedsc;
+  static struct dsc$descriptor_s ifiledsc;
+  static struct dsc$descriptor_s ofiledsc;
+  static struct dsc$descriptor_s efiledsc;
+  int have_redirection = 0;
+  int have_newline = 0;
+
   int spflags = CLI$M_NOWAIT;
-#endif
   int status;
-  char cmd[4096],*p,*c;
+  char *cmd = alloca (strlen (argv) + 512), *p, *q;
+  char ifile[256], ofile[256], efile[256];
   char comname[50];
+  char procname[100];
+
+  /* Parse IO redirection.  */
+
+  ifile[0] = 0;
+  ofile[0] = 0;
+  efile[0] = 0;
+
+  if (debug_flag)
+    printf ("child_execute_job (%s)\n", argv);
+
+  while (isspace (*argv))
+    argv++;
+
+  if (*argv == 0)
+    return 0;
+
+  sprintf (procname, "GMAKE_%05x", getpid () & 0xfffff);
+  pnamedsc.dsc$w_length = strlen(procname);
+  pnamedsc.dsc$a_pointer = procname;
+  pnamedsc.dsc$b_dtype = DSC$K_DTYPE_T;
+  pnamedsc.dsc$b_class = DSC$K_CLASS_S;
+
+  /* Handle comments and redirection. */
+  for (p = argv, q = cmd; *p; p++, q++)
+    {
+      switch (*p)
+	{
+	  case '#':
+	    *p-- = 0;
+	    *q-- = 0;
+	    break;
+	  case '\\':
+	    p++;
+	    if (*p == '\n')
+	      p++;
+	    if (isspace (*p))
+	      {
+		do { p++; } while (isspace (*p));
+		p--;
+	      }
+	    *q = *p;
+	    break;
+	  case '<':
+	    p = vms_redirect (&ifiledsc, ifile, p);
+	    *q = ' ';
+	    have_redirection = 1;
+	    break;
+	  case '>':
+	    have_redirection = 1;
+	    if (*(p-1) == '2')
+	      {
+		q--;
+		if (strncmp (p, ">&1", 3) == 0)
+		  {
+		    p += 3;
+		    strcpy (efile, "sys$output");
+		    efiledsc.dsc$w_length = strlen(efile);
+		    efiledsc.dsc$a_pointer = efile;
+		    efiledsc.dsc$b_dtype = DSC$K_DTYPE_T;
+		    efiledsc.dsc$b_class = DSC$K_CLASS_S;
+		  }
+		else
+		  {
+		    p = vms_redirect (&efiledsc, efile, p);
+		  }
+	      }
+	    else
+	      {
+		p = vms_redirect (&ofiledsc, ofile, p);
+	      }
+	    *q = ' ';
+	    break;
+	  case '\n':
+	    have_newline = 1;
+	  default:
+	    *q = *p;
+	    break;
+	}
+    }
+  *q = *p;
 
-/* Remove backslashes */
-  for (p = argv, c = cmd; *p; p++,c++)
+  if (strncmp (cmd, "builtin_", 8) == 0)
     {
-      if (*p == '\\') p++;
-	*c = *p;
+      child->pid = 270163;
+      child->efn = 0;
+      child->cstatus = 1;
+
+      if (debug_flag)
+	printf ("BUILTIN [%s][%s]\n", cmd, cmd+8);
+
+      p = cmd + 8;
+
+      if ((*(p) == 'c')
+	  && (*(p+1) == 'd')
+	  && ((*(p+2) == ' ') || (*(p+2) == '\t')))
+	{
+	  p += 3;
+	  while ((*p == ' ') || (*p == '\t'))
+	    p++;
+	  if (debug_flag)
+	    printf ("BUILTIN CD %s\n", p);
+	  if (chdir (p))
+	    return 0;
+	  else
+	    return 1;
+	}
+      else if ((*(p) == 'r')
+	  && (*(p+1) == 'm')
+	  && ((*(p+2) == ' ') || (*(p+2) == '\t')))
+	{
+	  int in_arg;
+
+	  /* rm  */
+	  p += 3;
+	  while ((*p == ' ') || (*p == '\t'))
+	    p++;
+	  in_arg = 1;
+
+	  if (debug_flag)
+	    printf ("BUILTIN RM %s\n", p);
+	  while (*p)
+	    {
+	      switch (*p)
+		{
+		  case ' ':
+		  case '\t':
+		    if (in_arg)
+		      {
+			*p++ = ';';
+			in_arg = 0;
+		      }
+		    break;
+		  default:
+		    break;
+		}
+	      p++;
+	    }
+	}
+      else
+	{
+	  printf("Unknown builtin command '%s'\n", cmd);
+	  fflush(stdout);
+	  return 0;
+	}
     }
-  *c = *p;
 
-  /* Check for maximum DCL length and create *.com file if neccesary.
-     Also create a .com file if the command is more than one line long.  */
+  /* Create a *.com file if either the command is too long for
+     lib$spawn, or the command contains a newline, or if redirection
+     is desired. Forcing commands with newlines into DCLs allows to
+     store search lists on user mode logicals.  */
 
   comname[0] = '\0';
 
-  if (strlen (cmd) > MAXCMDLEN || strchr (cmd, '\n'))
+  if (strlen (cmd) > MAXCMDLEN
+      || (have_redirection != 0)
+      || (have_newline != 0))
     {
       FILE *outfile;
-      char tmp;
+      char c;
+      char *sep;
+      int alevel = 0;	/* apostrophe level */
+
+      if (strlen (cmd) == 0)
+	{
+	  printf ("Error, empty command\n");
+	  fflush (stdout);
+	  return 0;
+	}
 
       strcpy (comname, "sys$scratch:CMDXXXXXX.COM");
       (void) mktemp (comname);
