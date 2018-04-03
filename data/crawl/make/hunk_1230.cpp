   return !strcmp (percent + 1, str + (strlength - sfxlen));
 }
 
-int shell_function_pid = 0, shell_function_completed;
 
-/* Perform the function specified by FUNCTION on the text at TEXT.
-   END is points to the end of the argument text (exclusive).
-   The output is written into VARIABLE_BUFFER starting at O.  */
+/* Find the next comma or ENDPAREN (counting nested STARTPAREN and
+   ENDPARENtheses), starting at PTR before END.  Return a pointer to
+   next character.
 
-/* Note this absorbs a semicolon and is safe to use in conditionals.  */
-#define BADARGS(func)  do {                                                   \
-    fatal (reading_file, "insufficient arguments to function `%s'", func);    \
-  } while (0)
+   If no next argument is found, return NULL.
+*/
 
 static char *
-expand_function (o, function, text, end)
-     char *o;
-     enum function function;
-     char *text;
-     char *end;
+find_next_argument (startparen, endparen, ptr, end)
+     char startparen;
+     char endparen;
+     const char *ptr;
+     const char *end;
 {
-  char *p, *p2, *p3;
-  unsigned int i, j, len;
-  int doneany = 0;
-  int count;
-  char endparen = *end, startparen = *end == ')' ? '(' : '{';
+  int count = 0;
 
-  switch (function)
-    {
-    default:
-      abort ();
-      break;
+  for (; ptr < end; ++ptr)
+    if (*ptr == startparen)
+      ++count;
 
-#ifndef VMS /* not supported for vms yet */
-    case function_shell:
+    else if (*ptr == endparen)
       {
-	char* batch_filename = NULL;
-#ifdef WINDOWS32
-	SECURITY_ATTRIBUTES saAttr;
-	HANDLE hIn;
-	HANDLE hErr;
-	HANDLE hChildOutRd;
-	HANDLE hChildOutWr;
-	HANDLE hProcess;
-#endif
-#ifdef __MSDOS__
-	FILE *fpipe;
-#endif
-	char **argv;
-	char *error_prefix;
-#ifndef _AMIGA
-	char **envp;
-	int pipedes[2];
-	int pid;
-#endif
-
-	/* Expand the command line.  */
-	text = expand_argument (text, end);
-
-#ifndef __MSDOS__
-	/* Construct the argument list.  */
-	argv = construct_command_argv (text,
-				       (char **) NULL, (struct file *) 0, &batch_filename);
-	if (argv == 0)
-	  break;
-#endif
-
-#ifndef _AMIGA
-	/* Using a target environment for `shell' loses in cases like:
-		export var = $(shell echo foobie)
-	   because target_environment hits a loop trying to expand $(var)
-	   to put it in the environment.  This is even more confusing when
-	   var was not explicitly exported, but just appeared in the
-	   calling environment.  */
-#if 1
-	envp = environ;
-#else
-	/* Construct the environment.  */
-	envp = target_environment ((struct file *) 0);
-#endif
-#endif  /* Not Amiga.  */
-
-	/* For error messages.  */
-	if (reading_file != 0)
-	  {
-	    error_prefix = (char *) alloca (strlen(reading_file->filenm)+100);
-	    sprintf (error_prefix,
-		     "%s:%lu: ", reading_file->filenm, reading_file->lineno);
-	  }
-	else
-	  error_prefix = "";
+	--count;
+	if (count < 0)
+	  return NULL;
+      }
 
-#ifndef _AMIGA
-# ifdef WINDOWS32
-	saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
-	saAttr.bInheritHandle = TRUE;
-	saAttr.lpSecurityDescriptor = NULL;
-
-	if (DuplicateHandle(GetCurrentProcess(),
-			    GetStdHandle(STD_INPUT_HANDLE),
-			    GetCurrentProcess(),
-			    &hIn,
-			    0,
-			    TRUE,
-			    DUPLICATE_SAME_ACCESS) == FALSE) {
-	  fatal (NILF, "create_child_process: DuplicateHandle(In) failed (e=%d)\n",
-		GetLastError());
-	}
-	if (DuplicateHandle(GetCurrentProcess(),
-			    GetStdHandle(STD_ERROR_HANDLE),
-			    GetCurrentProcess(),
-			    &hErr,
-			    0,
-			    TRUE,
-			    DUPLICATE_SAME_ACCESS) == FALSE) {
-	  fatal (NILF, "create_child_process: DuplicateHandle(Err) failed (e=%d)\n",
-		GetLastError());
-	}
+    else if (*ptr == ',' && !count)
+      return (char *)ptr;
 
-	if (!CreatePipe(&hChildOutRd, &hChildOutWr, &saAttr, 0))
-	  fatal (NILF, "CreatePipe() failed (e=%d)\n", GetLastError());
+  /* We didn't find anything.  */
+  return NULL;
+}
+
 
-	hProcess = process_init_fd(hIn, hChildOutWr, hErr);
+static char *
+expand_builtin_function (o, argc, argv, entry_p)
+     char *o;
+     int argc;
+     char **argv;
+     struct function_table_entry *entry_p;
+{
+  if (argc < entry_p->required_arguments && entry_p->required_arguments >= 0)
+    fatal (reading_file,
+           "Insufficient number of arguments (%d) to function `%s'",
+           argc, entry_p->name);
 
-	if (!hProcess)
-	  fatal (NILF, "expand_function: process_init_fd() failed\n");
-	else
-	  process_register(hProcess);
+  if (!entry_p->func_ptr)
+    fatal (reading_file, "Unimplemented on this platform: function `%s'",
+           entry_p->name);
 
-	/* make sure that CreateProcess() has Path it needs */
-	sync_Path_environment();
+  return entry_p->func_ptr (o, argv, entry_p->name);
+}
 
-	if (!process_begin(hProcess, argv, envp, argv[0], NULL))
-		pid = (int) hProcess;
-	else
-		fatal (NILF, "expand_function: unable to launch process (e=%d)\n",
-		      process_last_err(hProcess));
+/* Check for a function invocation in *STRINGP.  *STRINGP points at the
+   opening ( or { and is not null-terminated.  If a function invocation
+   is found, expand it into the buffer at *OP, updating *OP, incrementing
+   *STRINGP past the reference and returning nonzero.  If not, return zero.  */
 
-	/* set up to read data from child */
-	pipedes[0] = _open_osfhandle((long) hChildOutRd, O_RDONLY);
+int
+handle_function (op, stringp)
+     char **op;
+     char **stringp;
+{
+  const struct function_table_entry *entry_p;
+  char openparen = (*stringp)[0];
+  char closeparen = openparen == '(' ? ')' : '}';
+  char *beg = *stringp + 1;
+  char *endref;
+  int count = 0;
+  char *argbeg;
+  register char *p;
+  char **argv, **argvp;
+  int nargs;
 
-	/* this will be closed almost right away */
-	pipedes[1] = _open_osfhandle((long) hChildOutWr, O_APPEND);
-# else /* WINDOWS32 */
-#  ifdef __MSDOS__
-	{
-	  /* MSDOS can't fork, but it has `popen'.
-	     (Bwt, why isn't `popen' used in all the versions?) */
-	  struct variable *sh = lookup_variable ("SHELL", 5);
-	  int e;
-	  extern int dos_command_running, dos_status;
-
-	  /* Make sure not to bother processing an empty line.  */
-	  while (isblank (*text))
-	    ++text;
-	  if (*text == '\0')
-	    break;
+  entry_p = lookup_function (function_table, beg);
 
-	  if (sh)
-	    {
-	      char buf[PATH_MAX + 7];
-	      /* This makes sure $SHELL value is used by $(shell), even
-		 though the target environment is not passed to it.  */
-	      sprintf (buf, "SHELL=%s", sh->value);
-	      putenv (buf);
-	    }
+  if (!entry_p)
+    return 0;
 
-	  e = errno;
-	  errno = 0;
-	  dos_command_running = 1;
-	  dos_status = 0;
-	  fpipe = popen (text, "rt");
-	  dos_command_running = 0;
-	  if (!fpipe || dos_status)
-	    {
-	      pipedes[0] = -1;
-	      pid = -1;
-	      if (dos_status)
-		errno = EINTR;
-	      else if (errno == 0)
-		errno = ENOMEM;
-	      shell_function_completed = -1;
-	    }
-	  else
-	    {
-	      pipedes[0] = fileno (fpipe);
-	      pid = 42;
-	      errno = e;
-	      shell_function_completed = 1;
-	    }
-	}
-	if (pipedes[0] < 0)
-#  else /* ! __MSDOS__ */
-	if (pipe (pipedes) < 0)
-#  endif /* __MSDOS__ */
-	  {
-	    perror_with_name (error_prefix, "pipe");
-	    break;
-	  }
+  /* We have found a call to a builtin function.  Find the end of the
+     arguments, and do the function.  */
 
-#  ifndef  __MSDOS__
-	pid = vfork ();
-	if (pid < 0)
-	  perror_with_name (error_prefix, "fork");
-	else if (pid == 0)
-	  child_execute_job (0, pipedes[1], argv, envp);
-	else
-#  endif /* ! __MSDOS__ */
-# endif /* WINDOWS32 */
-	  {
-	    /* We are the parent.  */
-
-	    char *buffer;
-	    unsigned int maxlen;
-	    int cc;
-#if 0
-	    for (i = 0; envp[i] != 0; ++i)
-	      free (envp[i]);
-	    free ((char *) envp);
-#endif
+  endref = beg + entry_p->len;
 
-	    /* Record the PID for reap_children.  */
-	    shell_function_pid = pid;
-#ifndef  __MSDOS__
-	    shell_function_completed = 0;
+  /* Space after function name isn't part of the args.  */
+  p = next_token (endref);
+  argbeg = p;
 
-	    /* Free the storage only the child needed.  */
-	    free (argv[0]);
-	    free ((char *) argv);
+  /* Find the end of the function invocation, counting nested use of
+     whichever kind of parens we use.  Since we're looking, count commas
+     to get a rough estimate of how many arguments we might have.  The
+     count might be high, but it'll never be low.  */
 
-	    /* Close the write side of the pipe.  */
-	    (void) close (pipedes[1]);
-#endif
+  for (nargs=1; *p != '\0'; ++p)
+    if (*p == ',')
+      ++nargs;
+    else if (*p == openparen)
+      ++count;
+    else if (*p == closeparen && --count < 0)
+      break;
 
-	    /* Set up and read from the pipe.  */
-
-	    maxlen = 200;
-	    buffer = (char *) xmalloc (maxlen + 1);
-
-	    /* Read from the pipe until it gets EOF.  */
-	    i = 0;
-	    do
-	      {
-		if (i == maxlen)
-		  {
-		    maxlen += 512;
-		    buffer = (char *) xrealloc (buffer, maxlen + 1);
-		  }
-
-		errno = 0;
-		cc = read (pipedes[0], &buffer[i], maxlen - i);
-		if (cc > 0)
-		  i += cc;
-	      }
-#ifdef EINTR
-	    while (cc > 0 || errno == EINTR);
-#else
-	    while (cc > 0);
-#endif
+  if (count >= 0)
+    fatal (reading_file,
+	   "unterminated call to function `%s': missing `%c'",
+	   entry_p->name, closeparen);
 
-	    /* Close the read side of the pipe.  */
-#ifdef  __MSDOS__
-	    if (fpipe)
-	      (void) pclose (fpipe);
-#else
-	    (void) close (pipedes[0]);
-#endif
+  /* Get some memory to store the arg pointers.  */
+  argvp = argv = (char **) alloca (sizeof(char *) * (nargs + 2));
 
-	    /* Loop until child_handler sets shell_function_completed
-	       to the status of our child shell.  */
-	    while (shell_function_completed == 0)
-	      reap_children (1, 0);
-
-            if (batch_filename) {
-              if (debug_flag)
-                printf("Cleaning up temporary batch file %s\n", batch_filename);
-              remove(batch_filename);
-              free(batch_filename);
-            }
-	    shell_function_pid = 0;
-
-	    /* The child_handler function will set shell_function_completed
-	       to 1 when the child dies normally, or to -1 if it
-	       dies with status 127, which is most likely an exec fail.  */
-
-	    if (shell_function_completed == -1)
-	      {
-		/* This most likely means that the execvp failed,
-		   so we should just write out the error message
-		   that came in over the pipe from the child.  */
-		fputs (buffer, stderr);
-		fflush (stderr);
-	      }
-	    else
-	      {
-		/* The child finished normally.  Replace all
-		   newlines in its output with spaces, and put
-		   that in the variable output buffer.  */
-		if (i > 0)
-		  {
-		    if (buffer[i - 1] == '\n')
-		      {
-			if (i > 1 && buffer[i - 2] == '\r')
-			  --i;
-			buffer[--i] = '\0';
-		      }
-		    else
-		      buffer[i] = '\0';
-
-		    p = buffer;
-		    for (p2=p; *p != '\0'; ++p)
-		      {
-			if (p[0] == '\r' && p[1] == '\n')
-			  continue;
-			if (*p == '\n')
-			  *p2++ = ' ';
-			else
-			  *p2++ = *p;
-		      }
-		    *p2 = '\0';
-		    o = variable_buffer_output (o, buffer, i);
-		  }
-	      }
-
-	    free (buffer);
-	  }
-#else   /* Amiga */
-	 {
-	   /* Amiga can't fork nor spawn, but I can start a program with
-	      redirection of my choice.  However, this means that we
-	      don't have an opportunity to reopen stdout to trap it.  Thus,
-	      we save our own stdout onto a new descriptor and dup a temp
-	      file's descriptor onto our stdout temporarily.  After we
-	      spawn the shell program, we dup our own stdout back to the
-	      stdout descriptor.  The buffer reading is the same as above,
-	      except that we're now reading from a file.  */
-#include <dos/dos.h>
-#include <proto/dos.h>
+  /* Chop the string into arguments, then store the end pointer and a nul.  */
+  *argvp = argbeg;
+  nargs = 1;
+  while (1)
+    {
+      char *next = find_next_argument (openparen, closeparen, *argvp, p);
 
-	   BPTR child_stdout;
-	   char tmp_output[FILENAME_MAX];
-	   unsigned int maxlen = 200;
-	   int cc;
-	   char * buffer, * ptr;
-	   char ** aptr;
-	   int len = 0;
-
-	   strcpy (tmp_output, "t:MakeshXXXXXXXX");
-	   mktemp (tmp_output);
-	   child_stdout = Open (tmp_output, MODE_NEWFILE);
-
-	   for (aptr=argv; *aptr; aptr++)
-	     {
-	       len += strlen (*aptr) + 1;
-	     }
-
-	   buffer = xmalloc (len + 1);
-	   ptr = buffer;
-
-	   for (aptr=argv; *aptr; aptr++)
-	     {
-	       strcpy (ptr, *aptr);
-	       ptr += strlen (ptr) + 1;
-	       *ptr ++ = ' ';
-	       *ptr = 0;
-	     }
-
-	   ptr[-1] = '\n';
-
-	   Execute (buffer, NULL, child_stdout);
-	   free (buffer);
-
-	   Close (child_stdout);
-
-	   child_stdout = Open (tmp_output, MODE_OLDFILE);
-
-	   buffer = xmalloc (maxlen);
-	   i = 0;
-	   do
-	     {
-	       if (i == maxlen)
-		 {
-		   maxlen += 512;
-		   buffer = (char *) xrealloc (buffer, maxlen + 1);
-		 }
-
-	       cc = Read (child_stdout, &buffer[i], maxlen - i);
-	       if (cc > 0)
-		 i += cc;
-	     } while (cc > 0);
-
-	   Close (child_stdout);
-	   DeleteFile (tmp_output);
-
-	   if (i > 0)
-	     {
-	       if (buffer[i - 1] == '\n')
-		 buffer[--i] = '\0';
-	       else
-		 buffer[i] = '\0';
-	       p = buffer;
-	       while ((p = index (p, '\n')) != 0)
-		 *p++ = ' ';
-	       o = variable_buffer_output (o, buffer, i);
-	     }
-	   free (buffer);
-	 }
-#endif  /* Not Amiga.  */
-
-	free (text);
+      if (!next)
 	break;
-      }
-#endif /* !VMS */
 
-    case function_origin:
-      /* Expand the argument.  */
-      text = expand_argument (text, end);
+      *(++argvp) = next+1;
+      ++nargs;
+    }
 
-      {
-	register struct variable *v = lookup_variable (text, strlen (text));
-	if (v == 0)
-	  o = variable_buffer_output (o, "undefined", 9);
-	else
-	  switch (v->origin)
-	    {
-	    default:
-	    case o_invalid:
-	      abort ();
-	      break;
-	    case o_default:
-	      o = variable_buffer_output (o, "default", 7);
-	      break;
-	    case o_env:
-	      o = variable_buffer_output (o, "environment", 11);
-	      break;
-	    case o_file:
-	      o = variable_buffer_output (o, "file", 4);
-	      break;
-	    case o_env_override:
-	      o = variable_buffer_output (o, "environment override", 20);
-	      break;
-	    case o_command:
-	      o = variable_buffer_output (o, "command line", 12);
-	      break;
-	    case o_override:
-	      o = variable_buffer_output (o, "override", 8);
-	      break;
-	    case o_automatic:
-	      o = variable_buffer_output (o, "automatic", 9);
-	      break;
-	    }
-      }
+  *(++argvp) = p+1;
+  *(++argvp) = 0;
 
-      free (text);
-      break;
+  /* If we should expand, do it.  */
+  if (entry_p->expand_all_arguments)
+    {
+      for (argvp=argv; argvp[1] != 0; ++argvp)
+	*argvp = expand_argument (*argvp, argvp[1]-1);
 
-    case function_sort:
-      /* Expand the argument.  */
-      text = expand_argument (text, end);
+      /* end pointer doesn't make sense for expanded stuff.  */
+      *argvp = 0;
+    }
 
-      {
-	char **words = (char **) xmalloc (10 * sizeof (char *));
-	unsigned int nwords = 10;
-	register unsigned int wordi = 0;
-	char *t;
-
-	/* Chop TEXT into words and put them in WORDS.  */
-	t = text;
-	while ((p = find_next_token (&t, &len)) != 0)
-	  {
-	    if (wordi >= nwords - 1)
-	      {
-		nwords *= 2;
-		words = (char **) xrealloc ((char *) words,
-					    nwords * sizeof (char *));
-	      }
-	    words[wordi++] = savestring (p, len);
-	  }
+  /* Finally!  Run the function...  */
+  *op = expand_builtin_function (*op, nargs, argv, entry_p);
 
-	if (wordi > 0)
-	  {
-	    /* Now sort the list of words.  */
-	    qsort ((char *) words, wordi, sizeof (char *), alpha_compare);
-
-	    /* Now write the sorted list.  */
-	    for (i = 0; i < wordi; ++i)
-	      {
-		len = strlen (words[i]);
-		if (i == wordi - 1 || strlen (words[i + 1]) != len
-		    || strcmp (words[i], words[i + 1]))
-		  {
-		    o = variable_buffer_output (o, words[i], len);
-		    o = variable_buffer_output (o, " ", 1);
-		  }
-		free (words[i]);
-	      }
-	    /* Kill the last space.  */
-	    --o;
-	  }
+  /* If we allocated memory for the expanded args, free it again.  */
+  if (entry_p->expand_all_arguments)
+    for (argvp=argv; *argvp != 0; ++argvp)
+      free (*argvp);
 
-	free ((char *) words);
-      }
+  *stringp = p;
 
-      free (text);
-      break;
+  return 1;
+}
+
 
-    case function_foreach:
-      {
-	/* Get three comma-separated arguments but
-	   expand only the first two.  */
-	char *var, *list;
-	register struct variable *v;
+/* Glob-expand LINE.  The returned pointer is
+   only good until the next call to string_glob.  */
 
-	count = 0;
-	for (p = text; p < end; ++p)
-	  {
-	    if (*p == startparen)
-	      ++count;
-	    else if (*p == endparen)
-	      --count;
-	    else if (*p == ',' && count <= 0)
-	      break;
-	  }
-	if (p == end)
-	  BADARGS ("foreach");
-	var = expand_argument (text, p);
+static char *
+string_glob (line)
+     char *line;
+{
+  static char *result = 0;
+  static unsigned int length;
+  register struct nameseq *chain;
+  register unsigned int idx;
 
-	p2 = p + 1;
-	count = 0;
-	for (p = p2; p < end; ++p)
-	  {
-	    if (*p == startparen)
-	      ++count;
-	    else if (*p == endparen)
-	      --count;
-	    else if (*p == ',' && count <= 0)
-	      break;
-	  }
-	if (p == end)
-	  BADARGS ("foreach");
-	list = expand_argument (p2, p);
+  chain = multi_glob (parse_file_seq
+		      (&line, '\0', sizeof (struct nameseq),
+		       /* We do not want parse_file_seq to strip `./'s.
+			  That would break examples like:
+			  $(patsubst ./%.c,obj/%.o,$(wildcard ./*.c)).  */
 
-	++p;
-	text = savestring (p, end - p);
-
-	push_new_variable_scope ();
-	v = define_variable (var, strlen (var), "", o_automatic, 0);
-        free (v->value);
-        v->value = 0;
-	p3 = list;
-	while ((p = find_next_token (&p3, &len)) != 0)
-	  {
-	    char *result;
-	    char save = p[len];
-	    p[len] = '\0';
-	    v->value = p;
-	    result = allocated_variable_expand (text);
-	    p[len] = save;
-
-	    o = variable_buffer_output (o, result, strlen (result));
-	    o = variable_buffer_output (o, " ", 1);
-	    doneany = 1;
-	    free (result);
-	  }
-	if (doneany)
-	  /* Kill the last space.  */
-	  --o;
+		       /* Yep, and the preceding comment triggers a GCC
+                          warning.  Nothing wrong though.  */
+		       0),
+		      sizeof (struct nameseq));
 
-	v->value = 0;
-	pop_variable_scope ();
+  if (result == 0)
+    {
+      length = 100;
+      result = (char *) xmalloc (100);
+    }
 
-	free (var);
-	free (list);
-	free (text);
-      }
-      break;
+  idx = 0;
+  while (chain != 0)
+    {
+      register char *name = chain->name;
+      unsigned int len = strlen (name);
 
-    case function_filter:
-    case function_filter_out:
-      {
-	struct a_word
-	  {
-	    struct a_word *next;
-	    char *str;
-	    int matched;
-	  } *words, *wordtail, *wp;
-
-	/* Get two comma-separated arguments and expand each one.  */
-	count = 0;
-	for (p = text; p < end; ++p)
-	  {
-	    if (*p == startparen)
-	      ++count;
-	    else if (*p == endparen)
-	      --count;
-	    else if (*p == ',' && count <= 0)
-	      break;
-	  }
-	if (p == end)
-	  BADARGS (function == function_filter ? "filter" : "filter-out");
-	p2 = expand_argument (text, p);
+      struct nameseq *next = chain->next;
+      free ((char *) chain);
+      chain = next;
 
-	text = expand_argument (p + 1, end);
+      /* multi_glob will pass names without globbing metacharacters
+	 through as is, but we want only files that actually exist.  */
+      if (file_exists_p (name))
+	{
+	  if (idx + len + 1 > length)
+	    {
+	      length += (len + 1) * 2;
+	      result = (char *) xrealloc (result, length);
+	    }
+	  bcopy (name, &result[idx], len);
+	  idx += len;
+	  result[idx++] = ' ';
+	}
 
-	/* Chop TEXT up into words and then run each pattern through.  */
-	words = wordtail = 0;
-	p3 = text;
-	while ((p = find_next_token (&p3, &len)) != 0)
-	  {
-	    struct a_word *w = (struct a_word *)alloca(sizeof(struct a_word));
-	    if (words == 0)
-	      words = w;
-	    else
-	      wordtail->next = w;
-	    wordtail = w;
-
-	    if (*p3 != '\0')
-	      ++p3;
-	    p[len] = '\0';
-	    w->str = p;
-	    w->matched = 0;
-	  }
+      free (name);
+    }
 
-	if (words != 0)
-	  {
-	    wordtail->next = 0;
-
-	    /* Run each pattern through the words, killing words.  */
-	    p3 = p2;
-	    while ((p = find_next_token (&p3, &len)) != 0)
-	      {
-		char *percent;
-		char save = p[len];
-		p[len] = '\0';
-
-		percent = find_percent (p);
-		for (wp = words; wp != 0; wp = wp->next)
-		  wp->matched |= (percent == 0 ? streq (p, wp->str)
-				  : pattern_matches (p, percent, wp->str));
-
-		p[len] = save;
-	      }
-
-	    /* Output the words that matched (or didn't, for filter-out).  */
-	    for (wp = words; wp != 0; wp = wp->next)
-	      if (function == function_filter ? wp->matched : !wp->matched)
-		{
-		  o = variable_buffer_output (o, wp->str, strlen (wp->str));
-		  o = variable_buffer_output (o, " ", 1);
-		  doneany = 1;
-		}
-	    if (doneany)
-	      /* Kill the last space.  */
-	      --o;
-	  }
+  /* Kill the last space and terminate the string.  */
+  if (idx == 0)
+    result[0] = '\0';
+  else
+    result[idx - 1] = '\0';
 
-	free (p2);
-	free (text);
-      }
-      break;
+  return result;
+}
+
+/*
+  Builtin functions
+ */
 
-    case function_patsubst:
-      /* Get three comma-separated arguments and expand each one.  */
-      count = 0;
-      for (p = text; p < end; ++p)
-	{
-	  if (*p == startparen)
-	    ++count;
-	  else if (*p == endparen)
-	    --count;
-	  else if (*p == ',' && count <= 0)
-	    break;
-	}
-      if (p == end)
-	BADARGS ("patsubst");
+static char *
+func_patsubst (o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  o = patsubst_expand (o, argv[2], argv[0], argv[1], (char *) 0, (char *) 0);
+  return o;
+}
 
-      p2 = p;
-      count = 0;
-      for (++p; p < end; ++p)
-	{
-	  if (*p == startparen)
-	    ++count;
-	  else if (*p == endparen)
-	    --count;
-	  else if (*p == ',' && count <= 0)
-	    break;
-	}
-      if (p == end)
-	BADARGS ("patsubst");
 
-      text = expand_argument (text, p2);
-      p3 = expand_argument (p2 + 1, p);
-      p2 = expand_argument (p + 1, end);
+static char *
+func_join(o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  int doneany = 0;
+
+  /* Write each word of the first argument directly followed
+     by the corresponding word of the second argument.
+     If the two arguments have a different number of words,
+     the excess words are just output separated by blanks.  */
+  register char *tp;
+  register char *pp;
+  char *list1_iterator = argv[0];
+  char *list2_iterator = argv[1];
+  do
+    {
+      unsigned int len1, len2;
 
-      o = patsubst_expand (o, p2, text, p3, (char *) 0, (char *) 0);
+      tp = find_next_token (&list1_iterator, &len1);
+      if (tp != 0)
+	o = variable_buffer_output (o, tp, len1);
 
-      free (text);
-      free (p3);
-      free (p2);
-      break;
+      pp = find_next_token (&list2_iterator, &len2);
+      if (pp != 0)
+	o = variable_buffer_output (o, pp, len2);
 
-    case function_join:
-      /* Get two comma-separated arguments and expand each one.  */
-      count = 0;
-      for (p = text; p < end; ++p)
+      if (tp != 0 || pp != 0)
 	{
-	  if (*p == startparen)
-	    ++count;
-	  else if (*p == endparen)
-	    --count;
-	  else if (*p == ',' && count <= 0)
-	    break;
+	  o = variable_buffer_output (o, " ", 1);
+	  doneany = 1;
 	}
-      if (p == end)
-	BADARGS ("join");
-      text = expand_argument (text, p);
+    }
+  while (tp != 0 || pp != 0);
+  if (doneany)
+    /* Kill the last blank.  */
+    --o;
+
+  return o;
+}
 
-      p = expand_argument (p + 1, end);
 
+static char *
+func_origin(o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  /* Expand the argument.  */
+  register struct variable *v = lookup_variable (argv[0], strlen (argv[0]));
+  if (v == 0)
+    o = variable_buffer_output (o, "undefined", 9);
+  else
+    switch (v->origin)
       {
-	/* Write each word of the first argument directly followed
-	   by the corresponding word of the second argument.
-	   If the two arguments have a different number of words,
-	   the excess words are just output separated by blanks.  */
-	register char *tp, *pp;
-	p2 = text;
-	p3 = p;
-	do
-	  {
-	    unsigned int tlen, plen;
+      default:
+      case o_invalid:
+	abort ();
+	break;
+      case o_default:
+	o = variable_buffer_output (o, "default", 7);
+	break;
+      case o_env:
+	o = variable_buffer_output (o, "environment", 11);
+	break;
+      case o_file:
+	o = variable_buffer_output (o, "file", 4);
+	break;
+      case o_env_override:
+	o = variable_buffer_output (o, "environment override", 20);
+	break;
+      case o_command:
+	o = variable_buffer_output (o, "command line", 12);
+	break;
+      case o_override:
+	o = variable_buffer_output (o, "override", 8);
+	break;
+      case o_automatic:
+	o = variable_buffer_output (o, "automatic", 9);
+	break;
+      }
 
-	    tp = find_next_token (&p2, &tlen);
-	    if (tp != 0)
-	      o = variable_buffer_output (o, tp, tlen);
+  return o;
+}
 
-	    pp = find_next_token (&p3, &plen);
-	    if (pp != 0)
-	      o = variable_buffer_output (o, pp, plen);
+#ifdef VMS
+#define IS_PATHSEP(c) ((c) == ']')
+#else
+#ifdef __MSDOS__
+#define IS_PATHSEP(c) ((c) == '/' || (c) == '\\')
+#else
+#define IS_PATHSEP(c) ((c) == '/')
+#endif
+#endif
 
-	    if (tp != 0 || pp != 0)
-	      {
-		o = variable_buffer_output (o, " ", 1);
-		doneany = 1;
-	      }
-	  }
-	while (tp != 0 || pp != 0);
-	if (doneany)
-	  /* Kill the last blank.  */
-	  --o;
-      }
 
-      free (text);
-      free (p);
-      break;
+static char *
+func_notdir_suffix(o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  /* Expand the argument.  */
+  char *list_iterator = argv[0];
+  char *p2 =0;
+  int doneany =0;
+  int len=0;
+
+  int is_suffix = streq(funcname, "suffix");
+  int is_notdir = !is_suffix;
+  while ((p2 = find_next_token (&list_iterator, &len)) != 0)
+    {
+      char *p = p2 + len;
 
-    case function_strip:
-      /* Expand the argument.  */
-      text = expand_argument (text, end);
 
-      p2 = text;
-      while (*p2 != '\0')
+      while (p >= p2 && (!is_suffix || *p != '.'))
 	{
-	  while (isspace(*p2))
-	    ++p2;
-	  p = p2;
-	  for (i=0; *p2 != '\0' && !isspace(*p2); ++p2, ++i)
-	    {}
-	  if (!i)
+	  if (IS_PATHSEP (*p))
 	    break;
-	  o = variable_buffer_output (o, p, i);
+	  --p;
+	}
+
+      if (p >= p2)
+	{
+	  if (is_notdir)
+	    ++p;
+	  else if (*p != '.')
+	    continue;
+	  o = variable_buffer_output (o, p, len - (p - p2));
+	}
+#if defined(WINDOWS32) || defined(__MSDOS__)
+      /* Handle the case of "d:foo/bar".  */
+      else if (streq(funcname, "notdir") && p2[0] && p2[1] == ':')
+	{
+	  p = p2 + 2;
+	  o = variable_buffer_output (o, p, len - (p - p2));
+	}
+#endif
+      else if (is_notdir)
+	o = variable_buffer_output (o, p2, len);
+
+      if (is_notdir || p >= p2)
+	{
 	  o = variable_buffer_output (o, " ", 1);
 	  doneany = 1;
 	}
-      if (doneany)
-	/* Kill the last space.  */
+    }
+  if (doneany)
+    /* Kill last space.  */
+    --o;
+
+
+  return o;
+
+}
+
+
+static char *
+func_basename_dir(o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  /* Expand the argument.  */
+  char *p3 = argv[0];
+  char *p2=0;
+  int doneany=0;
+  int len=0;
+  char *p=0;
+  int is_basename= streq(funcname, "basename");
+  int is_dir= !is_basename;
+
+  while ((p2 = find_next_token (&p3, &len)) != 0)
+	{
+	  p = p2 + len;
+	  while (p >= p2 && (!is_basename  || *p != '.'))
+	    {
+	      if (IS_PATHSEP(*p))
+		break;
+	      	    --p;
+	    }
+
+	  if (p >= p2 && (is_dir))
+	    o = variable_buffer_output (o, p2, ++p - p2);
+	  else if (p >= p2 && (*p == '.'))
+	    o = variable_buffer_output (o, p2, p - p2);
+#if defined(WINDOWS32) || defined(__MSDOS__)
+	/* Handle the "d:foobar" case */
+	  else if (p2[0] && p2[1] == ':' && is_dir)
+	    o = variable_buffer_output (o, p2, 2);
+#endif
+	  else if (is_dir)
+#ifdef VMS
+	    o = variable_buffer_output (o, "[]", 2);
+#else
+#ifndef _AMIGA
+	    o = variable_buffer_output (o, "./", 2);
+#else
+	    ; /* Just a nop...  */
+#endif /* AMIGA */
+#endif /* !VMS */
+	  else
+	    /* The entire name is the basename.  */
+	    o = variable_buffer_output (o, p2, len);
+
+	  o = variable_buffer_output (o, " ", 1);
+	  doneany = 1;
+	}
+      if (doneany)
+	/* Kill last space.  */
 	--o;
 
-      free (text);
+
+ return o;
+}
+
+static char *
+func_addsuffix_addprefix(o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  int fixlen = strlen (argv[0]);
+  char *list_iterator = argv[1];
+  int is_addprefix = streq (funcname, "addprefix");
+  int is_addsuffix = !is_addprefix;
+
+  int doneany =0;
+  char *p=0;
+  int len =0;
+
+  while ((p = find_next_token (&list_iterator, &len)) != 0)
+    {
+      if (is_addprefix)
+	o = variable_buffer_output (o, argv[0], fixlen);
+      o = variable_buffer_output (o, p, len);
+      if (is_addsuffix)
+	o = variable_buffer_output (o, argv[0], fixlen);
+      o = variable_buffer_output (o, " ", 1);
+      doneany = 1;
+    }
+
+  if (doneany)
+    /* Kill last space.  */
+    --o;
+
+  return o;
+}
+
+static char *
+func_subst(o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  o = subst_expand (o, argv[2], argv[0], argv[1], strlen (argv[0]),
+		    strlen (argv[1]), 0, 0);
+
+  return o;
+}
+
+
+static char *
+func_firstword(o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  int i=0;
+  char *words = argv[0];
+  char *p = find_next_token (&words, &i);
+
+  if (p != 0)
+    o = variable_buffer_output (o, p, i);
+
+  return o;
+}
+
+
+static char *
+func_words(o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  int i = 0;
+  char *word_iterator = argv[0];
+  char buf[20];
+
+  while (find_next_token (&word_iterator, (unsigned int *) 0) != 0)
+    ++i;
+
+  sprintf (buf, "%d", i);
+  o = variable_buffer_output (o, buf, strlen (buf));
+
+
+  return o;
+}
+
+char *
+strip_whitespace (begpp, endpp)
+     char **begpp;
+     char **endpp;
+{
+  while (isspace (**begpp) && *begpp <= *endpp)
+    (*begpp) ++;
+  while (isspace (**endpp) && *endpp >= *begpp)
+    (*endpp) --;
+  return *begpp;
+}
+
+int
+is_numeric (p)
+     char *p;
+{
+  char *end = p + strlen (p) -1;
+  char *beg = p;
+  strip_whitespace (&p, &end);
+  while (p <= end)
+    {
+      if (!isdigit (*p))
+	return 0;
+
+      p++;
+    }
+
+  return (end - beg >= 0);
+}
+
+void
+check_numeric (s, message)
+     char *s;
+     char *message;
+{
+  if (!is_numeric (s))
+    fatal (reading_file, message);
+}
+
+
+
+static char *
+func_word(o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  char *end_p=0;
+  int i=0;
+  char *p=0;
+
+  /* Check the first argument.  */
+  check_numeric (argv[0], "non-numeric first argument to `word' function");
+  i =  atoi (argv[0]);
+
+  if (i == 0)
+    fatal (reading_file, "the `word' function takes a positive index argument");
+
+
+  end_p = argv[1];
+  while ((p = find_next_token (&end_p, 0)) != 0)
+    if (--i == 0)
       break;
 
-    case function_wildcard:
-      text = expand_argument (text, end);
+  if (i == 0)
+    o = variable_buffer_output (o, p, end_p - p);
+
+  return o;
+}
+
+static char *
+func_wordlist (o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  int i=0;
+  int j=0;
+
+  /* Check the first argument.  */
+  check_numeric (argv[0],
+		 "non-numeric first argument to `wordlist' function");
+  i =atoi(argv[0]);
+  check_numeric (argv[1],
+		 "non-numeric second argument to `wordlist' function");
+
+  j = atoi(argv[1]);
+
+
+  {
+    char *p;
+    char *end_p = argv[2];
+
+    int start = (i < j) ? i : j;
+    int count = j -i ;
+    if (count < 0)
+      count = - count;
+    count ++;
+
+
+
+    while (((p = find_next_token (&end_p, 0)) != 0) && --start)
+      {}
+    if (p)
+      {
+	while (--count && (find_next_token (&end_p, 0) != 0))
+	  {}
+	o = variable_buffer_output (o, p, end_p - p);
+      }
+  }
+  return o;
+}
+
+static char*
+func_findstring(o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  /* Find the first occurrence of the first string in the second.  */
+  int i = strlen (argv[0]);
+  if (sindex (argv[1], 0, argv[0], i) != 0)
+    o = variable_buffer_output (o, argv[0], i);
+
+  return o;
+}
+
+static char *
+func_foreach (o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  /* expand only the first two.  */
+  char *varname = expand_argument (argv[0], argv[1] -1);
+  char *list = expand_argument (argv[1], argv[2] -1);
+  char *body = savestring (argv[2], argv[3] - argv[2] -1 );
+
+  int len =0;
+  char *list_iterator = list;
+  char *p;
+  register struct variable *var=0;
+  int doneany =0;
+
+  push_new_variable_scope ();
+  var = define_variable (varname, strlen (varname), "", o_automatic, 0);
+
+  /* loop through LIST,  put the value in VAR and expand BODY */
+  while ((p = find_next_token (&list_iterator, &len)) != 0)
+    {
+      char *result = 0;
+
+      {
+	char save = p[len];
+
+	p[len] = '\0';
+	free (var->value);
+	var->value = (char *) xstrdup ((char*) p);
+	p[len] = save;
+      }
+
+      result = allocated_variable_expand (body);
+
+      o = variable_buffer_output (o, result, strlen (result));
+      o = variable_buffer_output (o, " ", 1);
+      doneany = 1;
+      free (result);
+    }
+
+  if (doneany)
+    /* Kill the last space.  */
+    --o;
+
+  pop_variable_scope ();
+  free (varname);
+  free (list);
+  free (body);
+
+  return o;
+}
+
+struct a_word
+{
+  struct a_word *next;
+  char *str;
+  int matched;
+};
+
+static char *
+func_filter_filterout (o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  struct  a_word   *wordhead =0;
+  struct  a_word *wordtail =0;
+
+  int is_filter = streq (funcname, "filter");
+  char *patterns = argv[0];
+
+
+  char *p;
+  int len;
+  char *word_iterator = argv[1];
+
+  /* Chop ARGV[1] up into words and then run each pattern through.  */
+  while ((p = find_next_token (&word_iterator, &len)) != 0)
+    {
+      struct a_word *w = (struct a_word *)alloca(sizeof(struct a_word));
+      if (wordhead == 0)
+	wordhead = w;
+      else
+	wordtail->next = w;
+      wordtail = w;
+
+      if (*word_iterator != '\0')
+	++word_iterator;
+      p[len] = '\0';
+      w->str = p;
+      w->matched = 0;
+    }
+
+  if (wordhead != 0)
+    {
+      struct  a_word *wp =0;
+      char *pat_iterator = patterns;
+      int doneany = 0;
+
+      wordtail->next = 0;
+
+
+      /* Run each pattern through the words, killing words.  */
+      while ((p = find_next_token (&pat_iterator, &len)) != 0)
+	{
+	  char *percent;
+	  char save = p[len];
+	  p[len] = '\0';
+
+	  percent = find_percent (p);
+	  for (wp = wordhead; wp != 0; wp = wp->next)
+	    wp->matched |= (percent == 0 ? streq (p, wp->str)
+			    : pattern_matches (p, percent, wp->str));
+
+	  p[len] = save;
+	}
+
+      /* Output the words that matched (or didn't, for filter-out).  */
+      for (wp = wordhead; wp != 0; wp = wp->next)
+	if (is_filter ? wp->matched : !wp->matched)
+	  {
+	    o = variable_buffer_output (o, wp->str, strlen (wp->str));
+	    o = variable_buffer_output (o, " ", 1);
+	    doneany = 1;
+	  }
+
+      if (doneany)
+	/* Kill the last space.  */
+	--o;
+    }
+
+  return o;
+}
+
+
+static char *
+func_strip(o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  char *p = argv[0];
+  int doneany =0;
+
+  while (*p != '\0')
+    {
+      int i=0;
+      char *word_start=0;
+
+      while (isspace(*p))
+	++p;
+      word_start = p;
+      for (i=0; *p != '\0' && !isspace(*p); ++p, ++i)
+	{}
+      if (!i)
+	break;
+      o = variable_buffer_output (o, word_start, i);
+      o = variable_buffer_output (o, " ", 1);
+      doneany = 1;
+    }
+
+  if (doneany)
+    /* Kill the last space.  */
+    --o;
+  return o;
+}
+
+/*
+  Print a warning or fatal message.
+*/
+static char *
+func_error (o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  char **argvp;
+  char *msg, *p;
+  int len;
+
+  /* The arguments will be broken on commas.  Rather than create yet
+     another special case where function arguments aren't broken up,
+     just create a format string that puts them back together.  */
+  for (len=0, argvp=argv; *argvp != 0; ++argvp)
+    len += strlen(*argvp) + 2;
+
+  p = msg = alloca (len + 1);
+
+  for (argvp=argv; argvp[1] != 0; ++argvp)
+    {
+      strcpy(p, *argvp);
+      p += strlen(*argvp);
+      *(p++) = ',';
+      *(p++) = ' ';
+    }
+  strcpy(p, *argvp);
+
+  if (*funcname == 'e')
+    fatal (reading_file, "%s", msg);
+
+  /* The warning function expands to the empty string.  */
+  error (reading_file, "%s", msg);
+
+  return o;
+}
+
+
+/*
+  chop argv[0] into words, and sort them.
+ */
+static char *
+func_sort (o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  char **words = 0;
+  int nwords = 0;
+  register int wordi = 0;
+
+  /* Chop ARGV[0] into words and put them in WORDS.  */
+  char *t = argv[0];
+  char *p=0;
+  int len;
+  while ((p = find_next_token (&t, &len)) != 0)
+    {
+      if (wordi >= nwords - 1)
+	{
+	  nwords = 2* nwords + 5;
+	  words = (char **) xrealloc ((char *) words,
+				      nwords * sizeof (char *));
+	}
+      words[wordi++] = savestring (p, len);
+    }
+
+  if (wordi > 0)
+    {
+      int i;
+      /* Now sort the list of words.  */
+      qsort ((char *) words, wordi, sizeof (char *), alpha_compare);
+
+      /* Now write the sorted list.  */
+      for (i = 0; i < wordi; ++i)
+	{
+	  len = strlen (words[i]);
+	  if (i == wordi - 1 || strlen (words[i + 1]) != len
+	      || strcmp (words[i], words[i + 1]))
+	    {
+	      o = variable_buffer_output (o, words[i], len);
+	      o = variable_buffer_output (o, " ", 1);
+	    }
+	  free (words[i]);
+	}
+      /* Kill the last space.  */
+      --o;
+    }
+
+  free ((char *) words);
+  return o;
+}
+
+static char *
+func_wildcard(o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
 
 #ifdef _AMIGA
-      o = wildcard_expansion (text, o);
+   o = wildcard_expansion (argv[0], o);
 #else
-      p = string_glob (text);
-      o = variable_buffer_output (o, p, strlen (p));
+   char *p = string_glob (argv[0]);
+   o = variable_buffer_output (o, p, strlen (p));
 #endif
+   return o;
+}
 
-      free (text);
-      break;
+/*
+  \r  is replaced on UNIX as well. Is this desirable?
+ */
+void
+fold_newlines (buffer, length)
+     char *buffer;
+     int *length;
+{
+  char *dst = buffer;
+  char *src = buffer;
+  char *last_nonnl = buffer -1;
+  src[*length] = 0;
+  for (; *src != '\0'; ++src)
+    {
+      if (src[0] == '\r' && src[1] == '\n')
+	continue;
+      if (*src == '\n')
+	{
+	  *dst++ = ' ';
+	}
+      else
+	{
+	  last_nonnl = dst;
+	  *dst++ = *src;
+	}
+    }
+  *(++last_nonnl) = '\0';
+  *length = last_nonnl - buffer;
+}
+
+
+
+int shell_function_pid = 0, shell_function_completed;
+
+
+#ifdef WINDOWS32
+/*untested*/
+
+#include <windows.h>
+#include <io.h>
+#include "sub_proc.h"
+
+
+void
+windows32_openpipe (int *pipedes, int *pid_p, char **command_argv, char **envp)
+{
+  SECURITY_ATTRIBUTES saAttr;
+  HANDLE hIn;
+  HANDLE hErr;
+  HANDLE hChildOutRd;
+  HANDLE hChildOutWr;
+  HANDLE hProcess;
+
+
+  saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
+  saAttr.bInheritHandle = TRUE;
+  saAttr.lpSecurityDescriptor = NULL;
+
+  if (DuplicateHandle(GetCurrentProcess(),
+		      GetStdHandle(STD_INPUT_HANDLE),
+		      GetCurrentProcess(),
+		      &hIn,
+		      0,
+		      TRUE,
+		      DUPLICATE_SAME_ACCESS) == FALSE) {
+    fatal (NILF, "create_child_process: DuplicateHandle(In) failed (e=%d)\n",
+	   GetLastError());
+
+  }
+  if (DuplicateHandle(GetCurrentProcess(),
+		      GetStdHandle(STD_ERROR_HANDLE),
+		      GetCurrentProcess(),
+		      &hErr,
+		      0,
+		      TRUE,
+		      DUPLICATE_SAME_ACCESS) == FALSE) {
+    fatal (NILF, "create_child_process: DuplicateHandle(Err) failed (e=%d)\n",
+	   GetLastError());
+  }
+
+  if (!CreatePipe(&hChildOutRd, &hChildOutWr, &saAttr, 0))
+    fatal (NILF, "CreatePipe() failed (e=%d)\n", GetLastError());
+
+
+
+  hProcess = process_init_fd(hIn, hChildOutWr, hErr);
+
+  if (!hProcess)
+    fatal (NILF, "windows32_openpipe (): process_init_fd() failed\n");
+
+  else
+    process_register(hProcess);
+
+  /* make sure that CreateProcess() has Path it needs */
+  sync_Path_environment();
+
+  if (!process_begin(hProcess, command_argv, envp, command_argv[0], NULL))
+    *pid_p = (int) hProcess;
+  else
+    fatal (NILF, "windows32_openpipe (): unable to launch process (e=%d)\n",
+	   process_last_err(hProcess));
+
+  /* set up to read data from child */
+  pipedes[0] = _open_osfhandle((long) hChildOutRd, O_RDONLY);
+
+  /* this will be closed almost right away */
+  pipedes[1] = _open_osfhandle((long) hChildOutWr, O_APPEND);
+}
+#endif
+
+
+#ifdef __MSDOS__
+/*
+  untested
+*/
+int
+msdos_openpipe (int* pipedes, int *pidp, char *text)
+{
+  FILE *fpipe=0;
+  /* MSDOS can't fork, but it has `popen'.
+     (Bwt, why isn't `popen' used in all the versions?) */
+  struct variable *sh = lookup_variable ("SHELL", 5);
+  int e;
+  extern int dos_command_running, dos_status;
+
+  /* Make sure not to bother processing an empty line.  */
+  while (isblank (*text))
+    ++text;
+  if (*text == '\0')
+    return 0;
+
+  if (sh)
+    {
+      char buf[PATH_MAX + 7];
+      /* This makes sure $SHELL value is used by $(shell), even
+	 though the target environment is not passed to it.  */
+      sprintf (buf, "SHELL=%s", sh->value);
+      putenv (buf);
+    }
+
+  e = errno;
+  errno = 0;
+  dos_command_running = 1;
+  dos_status = 0;
+  fpipe = popen (text, "rt");
+  dos_command_running = 0;
+  if (!fpipe || dos_status)
+    {
+      pipedes[0] = -1;
+      *pidp = -1;
+      if (dos_status)
+	errno = EINTR;
+      else if (errno == 0)
+	errno = ENOMEM;
+      shell_function_completed = -1;
+    }
+  else
+    {
+      pipedes[0] = fileno (fpipe);
+      *pidp = 42;		/* uh? The meaning of Life?*/
+      errno = e;
+      shell_function_completed = 1;
+    }
+  return fpipe;
+}
+#endif
+
+/*
+  Do shell spawning, with the naughty bits for different OSes.
+ */
+
+#ifdef VMS
+
+/* VMS can't do $(shell ...)  */
+#define func_shell 0
+
+#else
+#ifndef _AMIGA
+static char *
+func_shell (o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  char* batch_filename = NULL;
+  int i;
+
+#ifdef __MSDOS__
+  FILE *fpipe;
+#endif
+  char **command_argv;
+  char *error_prefix;
+  char **envp;
+  int pipedes[2];
+  int pid;
+
+#ifndef __MSDOS__
+  /* Construct the argument list.  */
+  command_argv = construct_command_argv (argv[0],
+					 (char **) NULL, (struct file *) 0,
+                                         &batch_filename);
+  if (command_argv == 0)
+    return o;
+#endif
+
+  /* Using a target environment for `shell' loses in cases like:
+     export var = $(shell echo foobie)
+     because target_environment hits a loop trying to expand $(var)
+     to put it in the environment.  This is even more confusing when
+     var was not explicitly exported, but just appeared in the
+     calling environment.  */
+
+  envp = environ;
+
+  /* For error messages.  */
+  if (reading_file != 0)
+    {
+       error_prefix = (char *) alloca (strlen(reading_file->filenm)+100);
+
+      sprintf (error_prefix,
+	       "%s:%lu: ", reading_file->filenm, reading_file->lineno);
+
+    }
+  else
+    error_prefix = "";
+
+#ifdef WINDOWS32
+  windows32_openpipe (pipedes, &pid, command_argv, envp);
+#else /* WINDOWS32 */
+
+# ifdef __MSDOS__
+  fpipe = msdos_openpipe (pipedes, argv[0], command_argv, envp);
+  if (!fpipe || pipedes[0] < 0)
+    {
+      	perror_with_name (error_prefix, "pipe");
+	return o;
+    }
+# else
+  if (pipe (pipedes) < 0)
+    {
+      perror_with_name (error_prefix, "pipe");
+      return o;
+    }
 
-    case function_subst:
-      /* Get three comma-separated arguments and expand each one.  */
-      count = 0;
-      for (p = text; p < end; ++p)
-	{
-	  if (*p == startparen)
-	    ++count;
-	  else if (*p == endparen)
-	    --count;
-	  else if (*p == ',' && count <= 0)
-	    break;
-	}
-      if (p == end)
-	BADARGS ("subst");
+  pid = vfork ();
+  if (pid < 0)
+    perror_with_name (error_prefix, "fork");
+  else if (pid == 0)
+    child_execute_job (0, pipedes[1], command_argv, envp);
+  else
+# endif /* ! __MSDOS__ */
 
-      p2 = p;
-      count = 0;
-      for (++p; p < end; ++p)
-	{
-	  if (*p == startparen)
-	    ++count;
-	  else if (*p == endparen)
-	    --count;
-	  else if (*p == ',' && count <= 0)
-	    break;
-	}
-      if (p == end)
-	BADARGS ("subst");
+#endif /* WINDOWS32 */
+    {
+      /* We are the parent.  */
 
-      text = expand_argument (text, p2);
-      p3 = expand_argument (p2 + 1, p);
-      p2 = expand_argument (p + 1, end);
+      char *buffer;
+      unsigned int maxlen;
+      int cc;
 
-      o = subst_expand (o, p2, text, p3, strlen (text), strlen (p3), 0, 0);
+      /* Record the PID for reap_children.  */
+      shell_function_pid = pid;
+#ifndef  __MSDOS__
+      shell_function_completed = 0;
 
-      free (text);
-      free (p3);
-      free (p2);
-      break;
+      /* Free the storage only the child needed.  */
+      free (command_argv[0]);
+      free ((char *) command_argv);
 
-    case function_firstword:
-      /* Expand the argument.  */
-      text = expand_argument (text, end);
+      /* Close the write side of the pipe.  */
+      (void) close (pipedes[1]);
+#endif
 
-      /* Find the first word in TEXT.  */
-      p2 = text;
-      p = find_next_token (&p2, &i);
-      if (p != 0)
-	o = variable_buffer_output (o, p, i);
+      /* Set up and read from the pipe.  */
 
-      free (text);
-      break;
+      maxlen = 200;
+      buffer = (char *) xmalloc (maxlen + 1);
 
-    case function_word:
-      /* Get two comma-separated arguments and expand each one.  */
-      count = 0;
-      for (p = text; p < end; ++p)
+      /* Read from the pipe until it gets EOF.  */
+      i = 0;
+      do
 	{
-	  if (*p == startparen)
-	    ++count;
-	  else if (*p == endparen)
-	    --count;
-	  else if (*p == ',' && count <= 0)
-	    break;
+	  if (i == maxlen)
+	    {
+	      maxlen += 512;
+	      buffer = (char *) xrealloc (buffer, maxlen + 1);
+	    }
+
+	  errno = 0;
+	  cc = read (pipedes[0], &buffer[i], maxlen - i);
+	  if (cc > 0)
+	    i += cc;
 	}
-      if (p == end)
-	BADARGS ("word");
-      text = expand_argument (text, p);
-
-      p3 = expand_argument (p + 1, end);
-
-      /* Check the first argument.  */
-      for (p2 = text; *p2 != '\0'; ++p2)
-	if (*p2 < '0' || *p2 > '9')
-          fatal (reading_file,
-                 "non-numeric first argument to `word' function");
-
-      i = (unsigned int) atoi (text);
-      if (i == 0)
-        fatal (reading_file,
-               "the `word' function takes a one-origin index argument");
-
-      p2 = p3;
-      while ((p = find_next_token (&p2, &len)) != 0)
-	if (--i == 0)
-	  break;
-      if (i == 0)
-	o = variable_buffer_output (o, p, len);
-
-      free (text);
-      free (p3);
-      break;
+#ifdef EINTR
+      while (cc > 0 || errno == EINTR);
+#else
+      while (cc > 0);
+#endif
 
-    case function_words:
-      /* Expand the argument.  */
-      text = expand_argument (text, end);
+      /* Close the read side of the pipe.  */
+#ifdef  __MSDOS__
+      if (fpipe)
+	(void) pclose (fpipe);
+#else
+      (void) close (pipedes[0]);
+#endif
 
-      i = 0;
-      p2 = text;
-      while (find_next_token (&p2, (unsigned int *) 0) != 0)
-	++i;
+      /* Loop until child_handler sets shell_function_completed
+	 to the status of our child shell.  */
+      while (shell_function_completed == 0)
+	reap_children (1, 0);
 
-      {
-	char buf[20];
-	sprintf (buf, "%d", i);
-	o = variable_buffer_output (o, buf, strlen (buf));
+      if (batch_filename) {
+	if (debug_flag)
+	  printf("Cleaning up temporary batch file %s\n", batch_filename);
+	remove(batch_filename);
+	free(batch_filename);
       }
+      shell_function_pid = 0;
 
-      free (text);
-      break;
+      /* The child_handler function will set shell_function_completed
+	 to 1 when the child dies normally, or to -1 if it
+	 dies with status 127, which is most likely an exec fail.  */
 
-    case function_wordlist:
-      /* Get two comma-separated arguments and expand each one.  */
-      count = 0;
-      for (p = text; p < end; ++p)
-	{
-	  if (*p == startparen)
-	    ++count;
-	  else if (*p == endparen)
-	    --count;
-	  else if (*p == ',' && count <= 0)
-	    break;
-	}
-      if (p == end)
-	BADARGS ("wordlist");
-      text = expand_argument (text, p);
-
-      /* Check the first argument.  */
-      for (p2 = text; *p2 != '\0'; ++p2)
-	if (*p2 < '0' || *p2 > '9')
-          fatal (reading_file,
-                 "non-numeric first argument to `wordlist' function");
-      i = (unsigned int)atoi(text);
-      free (text);
-
-      /* Check the next argument */
-      for (p2 = p + 1; isblank(*p2); ++p2)
-	{}
-      count = 0;
-      for (p = p2; p < end; ++p)
+      if (shell_function_completed == -1)
 	{
-	  if (*p == startparen)
-	    ++count;
-	  else if (*p == endparen)
-	    --count;
-	  else if (*p == ',' && count <= 0)
-	    break;
+	  /* This most likely means that the execvp failed,
+	     so we should just write out the error message
+	     that came in over the pipe from the child.  */
+	  fputs (buffer, stderr);
+	  fflush (stderr);
 	}
-      if (p == end)
-	BADARGS ("wordlist");
-      text = expand_argument (p2, p);
-
-      for (p2 = text; *p2 != '\0'; ++p2)
-	if (*p2 < '0' || *p2 > '9')
-          fatal (reading_file,
-                 "non-numeric second argument to `wordlist' function");
-      j = (unsigned int)atoi(text);
-      free (text);
-
-      if (j > i)
-	j -= i;
       else
 	{
-	  unsigned int k;
-	  k = j;
-	  j = i - j;
-	  i = k;
+	  /* The child finished normally.  Replace all
+	     newlines in its output with spaces, and put
+	     that in the variable output buffer.  */
+	  fold_newlines (buffer, &i);
+	  o = variable_buffer_output (o, buffer, i);
 	}
-      ++j;
 
-      /* Extract the requested words */
-      text = expand_argument (p + 1, end);
-      p2 = text;
+      free (buffer);
+    }
 
-      while (((p = find_next_token (&p2, &len)) != 0) && --i)
-	{}
-      if (p)
-	{
-	  while (--j && (find_next_token (&p2, &len) != 0))
-	    {}
-	  o = variable_buffer_output (o, p, p2 - p);
-	}
+  return o;
+}
 
-      free (text);
-      break;
+#else	/* _AMIGA */
 
-    case function_findstring:
-      /* Get two comma-separated arguments and expand each one.  */
-      count = 0;
-      for (p = text; p < end; ++p)
-	{
-	  if (*p == startparen)
-	    ++count;
-	  else if (*p == endparen)
-	    --count;
-	  else if (*p == ',' && count <= 0)
-	    break;
-	}
-      if (p == end)
-	BADARGS ("findstring");
-      text = expand_argument (text, p);
+/* Do the Amiga version of func_shell.  */
 
-      p = expand_argument (p + 1, end);
+static char *
+func_shell (char *o, char **argv, const char *funcname)
+{
+  /* Amiga can't fork nor spawn, but I can start a program with
+     redirection of my choice.  However, this means that we
+     don't have an opportunity to reopen stdout to trap it.  Thus,
+     we save our own stdout onto a new descriptor and dup a temp
+     file's descriptor onto our stdout temporarily.  After we
+     spawn the shell program, we dup our own stdout back to the
+     stdout descriptor.  The buffer reading is the same as above,
+     except that we're now reading from a file.  */
 
-      /* Find the first occurrence of the first string in the second.  */
-      i = strlen (text);
-      if (sindex (p, 0, text, i) != 0)
-	o = variable_buffer_output (o, text, i);
+#include <dos/dos.h>
+#include <proto/dos.h>
 
-      free (p);
-      free (text);
-      break;
+  BPTR child_stdout;
+  char tmp_output[FILENAME_MAX];
+  unsigned int maxlen = 200;
+  int cc, i;
+  char * buffer, * ptr;
+  char ** aptr;
+  int len = 0;
+  char* batch_filename = NULL;
 
-    case function_addsuffix:
-    case function_addprefix:
-      /* Get two comma-separated arguments and expand each one.  */
-      count = 0;
-      for (p = text; p < end; ++p)
-	{
-	  if (*p == startparen)
-	    ++count;
-	  else if (*p == endparen)
-	    --count;
-	  else if (*p == ',' && count <= 0)
-	    break;
-	}
-      if (p == end)
-	BADARGS (function == function_addsuffix ? "addsuffix" : "addprefix");
-      text = expand_argument (text, p);
-      i = strlen (text);
+  /* Construct the argument list.  */
+  command_argv = construct_command_argv (argv[0], (char **) NULL,
+                                         (struct file *) 0, &batch_filename);
+  if (command_argv == 0)
+    return o;
 
-      p2 = expand_argument (p + 1, end);
 
-      p3 = p2;
-      while ((p = find_next_token (&p3, &len)) != 0)
-	{
-	  if (function == function_addprefix)
-	    o = variable_buffer_output (o, text, i);
-	  o = variable_buffer_output (o, p, len);
-	  if (function == function_addsuffix)
-	    o = variable_buffer_output (o, text, i);
-	  o = variable_buffer_output (o, " ", 1);
-	  doneany = 1;
-	}
-      if (doneany)
-	/* Kill last space.  */
-	--o;
+  strcpy (tmp_output, "t:MakeshXXXXXXXX");
+  mktemp (tmp_output);
+  child_stdout = Open (tmp_output, MODE_NEWFILE);
 
-      free (p2);
-      free (text);
-      break;
+  for (aptr=command_argv; *aptr; aptr++)
+    len += strlen (*aptr) + 1;
 
-    case function_dir:
-    case function_basename:
-      /* Expand the argument.  */
-      text = expand_argument (text, end);
+  buffer = xmalloc (len + 1);
+  ptr = buffer;
 
-      p3 = text;
-      while ((p2 = find_next_token (&p3, &len)) != 0)
-	{
-	  p = p2 + len;
-#ifdef VMS
-	  while (p >= p2 && *p != ']'
-		 && (function != function_basename || *p != '.'))
-#else
-# ifdef __MSDOS__
-	  while (p >= p2 && *p != '/' && *p != '\\'
-		 && (function != function_basename || *p != '.'))
-# else
-	  while (p >= p2 && *p != '/'
-		 && (function != function_basename || *p != '.'))
-# endif
-#endif
-	    --p;
-	  if (p >= p2 && (function == function_dir))
-	    o = variable_buffer_output (o, p2, ++p - p2);
-	  else if (p >= p2 && (*p == '.'))
-	    o = variable_buffer_output (o, p2, p - p2);
-#if defined(WINDOWS32) || defined(__MSDOS__)
-	/* Handle the "d:foobar" case */
-	  else if (p2[0] && p2[1] == ':' && function == function_dir)
-	    o = variable_buffer_output (o, p2, 2);
-#endif
-	  else if (function == function_dir)
-#ifdef VMS
-	    o = variable_buffer_output (o, "[]", 2);
-#else
-#ifndef _AMIGA
-	    o = variable_buffer_output (o, "./", 2);
-#else
-	    /* o = o */; /* Just a nop...  */
-#endif /* AMIGA */
-#endif /* !VMS */
-	  else
-	    /* The entire name is the basename.  */
-	    o = variable_buffer_output (o, p2, len);
+  for (aptr=command_argv; *aptr; aptr++)
+    {
+      strcpy (ptr, *aptr);
+      ptr += strlen (ptr) + 1;
+      *ptr ++ = ' ';
+      *ptr = 0;
+    }
 
-	  o = variable_buffer_output (o, " ", 1);
-	  doneany = 1;
-	}
-      if (doneany)
-	/* Kill last space.  */
-	--o;
+  ptr[-1] = '\n';
 
-      free (text);
-      break;
+  Execute (buffer, NULL, child_stdout);
+  free (buffer);
 
-    case function_notdir:
-    case function_suffix:
-      /* Expand the argument.  */
-      text = expand_argument (text, end);
+  Close (child_stdout);
 
-      p3 = text;
-      while ((p2 = find_next_token (&p3, &len)) != 0)
-	{
-	  p = p2 + len;
-#ifdef VMS
-	  while (p >= p2 && *p != ']'
-		 && (function != function_suffix || *p != '.'))
-#else
-# ifdef __MSDOS__
-	  while (p >= p2 && *p != '/' && *p != '\\'
-		 && (function != function_suffix || *p != '.'))
-# else
-	  while (p >= p2 && *p != '/'
-		 && (function != function_suffix || *p != '.'))
-# endif
-#endif
-	    --p;
-	  if (p >= p2)
-	    {
-	      if (function == function_notdir)
-		++p;
-	      else if (*p != '.')
-		continue;
-	      o = variable_buffer_output (o, p, len - (p - p2));
-	    }
-#if defined(WINDOWS32) || defined(__MSDOS__)
-	  /* Handle the case of "d:foo/bar".  */
-	  else if (function == function_notdir && p2[0] && p2[1] == ':')
-	    {
-	      p = p2 + 2;
-	      o = variable_buffer_output (o, p, len - (p - p2));
-	    }
-#endif
-	  else if (function == function_notdir)
-	    o = variable_buffer_output (o, p2, len);
+  child_stdout = Open (tmp_output, MODE_OLDFILE);
 
-	  if (function == function_notdir || p >= p2)
-	    {
-	      o = variable_buffer_output (o, " ", 1);
-	      doneany = 1;
-	    }
+  buffer = xmalloc (maxlen);
+  i = 0;
+  do
+    {
+      if (i == maxlen)
+	{
+	  maxlen += 512;
+	  buffer = (char *) xrealloc (buffer, maxlen + 1);
 	}
-      if (doneany)
-	/* Kill last space.  */
-	--o;
 
-      free (text);
-      break;
-    }
+      cc = Read (child_stdout, &buffer[i], maxlen - i);
+      if (cc > 0)
+	i += cc;
+    } while (cc > 0);
+
+  Close (child_stdout);
 
+  fold_newlines (buffer, &i);
+  o = variable_buffer_output (o, buffer, i);
+  free (buffer);
   return o;
 }
-
-/* Check for a function invocation in *STRINGP.  *STRINGP points at the
-   opening ( or { and is not null-terminated.  If a function invocation
-   is found, expand it into the buffer at *OP, updating *OP, incrementing
-   *STRINGP past the reference and returning nonzero.  If not, return zero.  */
+#endif  /* _AMIGA */
+#endif  /* !VMS */
 
-int
-handle_function (op, stringp)
-     char **op;
-     char **stringp;
+#ifdef EXPERIMENTAL
 
+/*
+  equality. Return is string-boolean, ie, the empty string is false.
+ */
+static char *
+func_eq (char* o, char **argv, char *funcname)
 {
-  register unsigned int code;
-  unsigned int maxlen;
-  char *beg = *stringp + 1;
-  char *endref;
+  int result = ! strcmp (argv[0], argv[1]);
+  o = variable_buffer_output (o,  result ? "1" : "", result);
+  return o;
+}
 
-  endref = lindex (beg, beg + MAXFUNCTIONLEN, '\0');
-  maxlen = endref != 0 ? endref - beg : MAXFUNCTIONLEN;
 
-  for (code = 0; function_table[code].name != 0; ++code)
-    {
-      if (maxlen < function_table[code].len)
-	continue;
-      endref = beg + function_table[code].len;
-      if (isblank (*endref)
-	  && !strncmp (function_table[code].name, beg,
-		       function_table[code].len))
-	break;
-    }
-  if (function_table[code].name != 0)
-    {
-      /* We have found a call to an expansion-time function.
-	 Find the end of the arguments, and do the function.  */
+/*
+  string-boolean not operator.
+ */
+static char *
+func_not (char* o, char **argv, char *funcname)
+{
+  char * s = argv[0];
+  int result = 0;
+  while (isspace (*s))
+    s++;
+  result = ! (*s);
+  o = variable_buffer_output (o,  result ? "1" : "", result);
+  return o;
+}
 
-      char openparen = beg[-1], closeparen = openparen == '(' ? ')' : '}';
-      int count = 0;
-      char *argbeg;
-      register char *p;
 
-      /* Space after function name isn't part of the args.  */
-      p = next_token (endref);
-      argbeg = p;
 
-      /* Count nested use of whichever kind of parens we use,
-	 so that nested calls and variable refs work.  */
+/*
+ This is an experimental conditional function.
 
-      for (; *p != '\0'; ++p)
-	{
-	  if (*p == openparen)
-	    ++count;
-	  else if (*p == closeparen && --count < 0)
-	    break;
-	}
+ Syntax:
 
-      if (count >= 0)
-        fatal (reading_file,
-               "unterminated call to function `%s': missing `%c'",
-               function_table[code].name, closeparen);
+    $(if condition, true-part, false-part)
 
-      /* We found the end; expand the function call.  */
+ This is fully not consistent with make's syntax, but more in line
+ with `normal' programming languages.
 
-      *op = expand_function (*op, function_table[code].function, argbeg, p);
-      *stringp = p;
-      return 1;
-    }
+ Semantics:
 
-  return 0;
-}
-
-/* Glob-expand LINE.  The returned pointer is
-   only good until the next call to string_glob.  */
+ - CONDITION is false iff it evaluates to an empty string.  White
+ space before and after condition are stripped before evaluation.
+
+ - If CONDITION is true, then TRUE-PART is evaluated, otherwise
+ FALSE-PART is evaluated.  Because only one of the two PARTs is
+ evaluated, you can use $(if ) to create side-effects with the
+ $(shell ) function
 
+ */
 static char *
-string_glob (line)
-     char *line;
+func_if (char* o, char **argv, char *funcname)
 {
-  static char *result = 0;
-  static unsigned int length;
-  register struct nameseq *chain;
-  register unsigned int idx;
+  char *begp = argv[0];
+  char *endp = argv[1]-2;
+  char *expansion =0;
+  int result = 0;
 
-  chain = multi_glob (parse_file_seq
-		      (&line, '\0', sizeof (struct nameseq),
-		       /* We do not want parse_file_seq to strip `./'s.
-			  That would break examples like:
-			  $(patsubst ./%.c,obj/%.o,$(wildcard ./*.c)).  */
-		       0),
-		      sizeof (struct nameseq));
+  strip_whitespace (&begp, &endp);
+  if(begp <= endp)
+    expansion = expand_argument (begp, endp + 1);
 
-  if (result == 0)
-    {
-      length = 100;
-      result = (char *) xmalloc (100);
-    }
+  result = expansion
+    ? strlen (expansion)
+    : 0;
 
-  idx = 0;
-  while (chain != 0)
+  result = !result;
+  free (expansion);
+
+  expansion = expand_argument (argv[1 + result], argv[2+result] -1);
+  o = variable_buffer_output (o, expansion, strlen (expansion));
+
+  return o;
+}
+#endif
+
+/* This might not be very useful, but the code was simple to
+  implement, I just had to do it.
+
+  Here goes anyway
+
+  Apply & User defined functions.
+
+  SYNTAX
+
+    $(apply funcname, arg1, arg2, .. )
+
+  SEMANTICS
+
+  You can specify a builtin function, for funcname, eg
+
+    f = addprefix
+    $(apply addprefix,a, b c d)
+
+  This will result in
+
+    ab ac ad
+
+  You can specify your own functions, eg
+
+    funcname=BODY
+
+  BODY contains $(1) .. $(N) as argument markers.
+  upon expansions the strings ARG1 .. ARGN are substituted for $(1) .. $(N)
+  into BODY
+
+  Because the funcname is computed as well you can combine this do some
+  funky things, eg
+
+    map=$(foreach a, $(2), $(apply $(1), $(a)))
+
+
+  LIMITATIONS.
+
+  Make has no support for nested lists (or tuples), so you can't do
+  stuff like (Haskell notation):
+
+    f :: (a,b) -> c                   -- type of F
+    map :: (a->b) -> [a] -> b         -- type of MAP
+
+    map f [(1,2), (2,3)]              -- map F over list containing (1,2) and (2,3)
+
+  to get
+
+    [f (1, 2), f (2, 3)]
+
+
+  If only we had nested lists and quotes, we could duplicate LISP in make by
+  transforming
+
+    $(a, b, c) <->  (a b c)
+    $(quote $(a, b, c)) <-> '(a b c)
+
+  (or something alike ;-) (We could have automatic integration of
+  GUILE and make :-)
+
+  [Actually -- why should this be a joke?  If we could somehow integrate the
+  rules and targets into a functional model make could be a lot cleaner in
+  concept. ]
+
+*/
+char *
+func_apply (o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  char *userfunc_name;
+  int func_len;
+  char *body = 0;
+  char *expanded_body = 0;
+  int i;
+  const struct function_table_entry *entry_p;
+
+  userfunc_name = argv[0];
+  while (isspace (*userfunc_name))
+    ++userfunc_name;
+
+  entry_p = lookup_function (function_table, userfunc_name);
+
+  /* builtin function? */
+  if (entry_p)
     {
-      register char *name = chain->name;
-      unsigned int len = strlen (name);
+      for (i=0; argv[i+1]; i++)
+	;
 
-      struct nameseq *next = chain->next;
-      free ((char *) chain);
-      chain = next;
+      o = expand_builtin_function (o, i, argv + 1, entry_p);
+      return o;
+    }
 
-      /* multi_glob will pass names without globbing metacharacters
-	 through as is, but we want only files that actually exist.  */
-      if (file_exists_p (name))
-	{
-	  if (idx + len + 1 > length)
-	    {
-	      length += (len + 1) * 2;
-	      result = (char *) xrealloc (result, length);
-	    }
-	  bcopy (name, &result[idx], len);
-	  idx += len;
-	  result[idx++] = ' ';
-	}
+  func_len = strlen (userfunc_name);
+  body = xmalloc (func_len + 4);
+  strcpy (body + 2, userfunc_name);
+  body [func_len+2]=')';
+  body [func_len+3]= 0;
+  body [1]='(';
+  body [0]='$';
 
-      free (name);
+  push_new_variable_scope ();
+
+  /* set up arguments $(1) .. $(N) */
+  for (i=0; argv[i]; i++)
+    {
+      char num[10];
+      struct variable* var;
+      sprintf (num, "%d", i);
+      var = define_variable (num, strlen (num), argv[i], o_automatic, 0);
     }
 
-  /* Kill the last space and terminate the string.  */
-  if (idx == 0)
-    result[0] = '\0';
-  else
-    result[idx - 1] = '\0';
+  expanded_body =  allocated_variable_expand (body);
+  o = variable_buffer_output (o, expanded_body, strlen (expanded_body));
+  free (expanded_body);
+  pop_variable_scope ();
 
-  return result;
+  free (body);
+  return o;
 }
+
+
+#define STRING_SIZE_TUPLE(s) (s), (sizeof(s)-1)
+
+/* Lookup table for builtin functions.
+
+   This doesn't have to be sorted; we use a straight lookup.  We might gain
+   some efficiency by moving most often used functions to the start of the
+   table.
+
+   REQUIRED_ARGUMENTS is the minimum number of arguments.  A function
+   can have more, but they will be ignored.
+
+   EXPAND_ALL_ARGUMENTS means that all arguments should be expanded
+   before invocation.  Functions that do namespace tricks (foreach)
+   don't automatically expand.  */
+
+static struct function_table_entry function_table[] =
+{
+ /* Name/size */                    /* ARG EXP? Function */
+  { STRING_SIZE_TUPLE("addprefix"),     2,  1,  func_addsuffix_addprefix},
+  { STRING_SIZE_TUPLE("addsuffix"),     2,  1,  func_addsuffix_addprefix},
+  { STRING_SIZE_TUPLE("basename"),      1,  1,  func_basename_dir},
+  { STRING_SIZE_TUPLE("dir"),           1,  1,  func_basename_dir},
+  { STRING_SIZE_TUPLE("notdir"),        1,  1,  func_notdir_suffix},
+  { STRING_SIZE_TUPLE("subst"),         3,  1,  func_subst},
+  { STRING_SIZE_TUPLE("suffix"),        1,  1,  func_notdir_suffix},
+  { STRING_SIZE_TUPLE("filter"),        2,  1,  func_filter_filterout},
+  { STRING_SIZE_TUPLE("filter-out"),    2,  1,  func_filter_filterout},
+  { STRING_SIZE_TUPLE("findstring"),    2,  1,  func_findstring},
+  { STRING_SIZE_TUPLE("firstword"),     1,  1,  func_firstword},
+  { STRING_SIZE_TUPLE("join"),          2,  1,  func_join},
+  { STRING_SIZE_TUPLE("patsubst"),      3,  1,  func_patsubst},
+  { STRING_SIZE_TUPLE("shell"),         1,  1,  func_shell},
+  { STRING_SIZE_TUPLE("sort"),          1,  1,  func_sort},
+  { STRING_SIZE_TUPLE("strip"),         1,  1,  func_strip},
+  { STRING_SIZE_TUPLE("wildcard"),      1,  1,  func_wildcard},
+  { STRING_SIZE_TUPLE("word"),          2,  1,  func_word},
+  { STRING_SIZE_TUPLE("wordlist"),      3,  1,  func_wordlist},
+  { STRING_SIZE_TUPLE("words"),         1,  1,  func_words},
+  { STRING_SIZE_TUPLE("origin"),        1,  1,  func_origin},
+  { STRING_SIZE_TUPLE("error"),         1,  1,  func_error},
+  { STRING_SIZE_TUPLE("warning"),       1,  1,  func_error},
+  { STRING_SIZE_TUPLE("foreach"),       3,  0,  func_foreach},
+#ifdef EXPERIMENTAL
+  { STRING_SIZE_TUPLE("apply"),         1,  1,  func_apply},
+  { STRING_SIZE_TUPLE("eq"),            2,  1,  func_eq},
+  { STRING_SIZE_TUPLE("if"),            3,  0,  func_if},
+  { STRING_SIZE_TUPLE("not"),           1,  1,  func_not},
+#endif
+  { 0 }
+};
