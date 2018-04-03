     1 - success
     0 - failure
    -1 - empty */
-int
-parse_line (const char *line, char **com, char **val)
+
+static int
+parse_line (const char *line, char **com, char **val, int *comind)
 {
-  const char *p = line;
-  const char *orig_comptr, *end;
-  char *new_comptr;
+  const char *p;
+  const char *end = line + strlen (line);
+  const char *cmdstart, *cmdend;
+  const char *valstart, *valend;
 
-  /* Skip whitespace.  */
-  while (*p && ISSPACE (*p))
-    ++p;
+  char *cmdcopy;
+  int ind;
+
+  /* Skip leading and trailing whitespace.  */
+  while (*line && ISSPACE (*line))
+    ++line;
+  while (end > line && ISSPACE (end[-1]))
+    --end;
 
-  /* Don't process empty lines.  */
-  if (!*p || *p == '#')
+  /* Skip empty lines and comments.  */
+  if (!*line || *line == '#')
     return -1;
 
-  for (orig_comptr = p; ISALPHA (*p) || *p == '_' || *p == '-'; p++)
-    ;
-  /* The next char should be space or '='.  */
-  if (!ISSPACE (*p) && (*p != '='))
+  p = line;
+
+  cmdstart = p;
+  while (p < end && (ISALPHA (*p) || *p == '_' || *p == '-'))
+    ++p;
+  cmdend = p;
+
+  /* Skip '=', as well as any space before or after it. */
+  while (p < end && ISSPACE (*p))
+    ++p;
+  if (p == end || *p != '=')
     return 0;
-  /* Here we cannot use strdupdelim() as we normally would because we
-     want to skip the `-' and `_' characters in the input string.  */
-  *com = (char *)xmalloc (p - orig_comptr + 1);
-  for (new_comptr = *com; orig_comptr < p; orig_comptr++)
-    {
-      if (*orig_comptr == '_' || *orig_comptr == '-')
-	continue;
-      *new_comptr++ = *orig_comptr;
-    }
-  *new_comptr = '\0';
-  /* If the command is invalid, exit now.  */
-  if (comind (*com) == -1)
-    {
-      xfree (*com);
-      return 0;
-    }
+  ++p;
+  while (p < end && ISSPACE (*p))
+    ++p;
 
-  /* Skip spaces before '='.  */
-  for (; ISSPACE (*p); p++);
-  /* If '=' not found, bail out.  */
-  if (*p != '=')
-    {
-      xfree (*com);
-      return 0;
-    }
-  /* Skip spaces after '='.  */
-  for (++p; ISSPACE (*p); p++);
-  /* Get the ending position for VAL by starting with the end of the
-     line and skipping whitespace.  */
-  end = line + strlen (line) - 1;
-  while (end > p && ISSPACE (*end))
-    --end;
-  *val = strdupdelim (p, end + 1);
+  valstart = p;
+  valend   = end;
+
+  /* The line now known to be syntactically correct.  Check whether
+     the command is valid.  */
+  BOUNDED_TO_ALLOCA (cmdstart, cmdend, cmdcopy);
+  dehyphen (cmdcopy);
+  ind = findcmd (cmdcopy);
+  if (ind == -1)
+    return 0;
+
+  /* The command is valid.  Now fill in the values and report success
+     to the caller.  */
+  *comind = ind;
+  *com = strdupdelim (cmdstart, cmdend);
+  *val = strdupdelim (valstart, valend);
   return 1;
 }
 
-/* Set COM to VAL.  This is the meat behind processing `.wgetrc'.  No
-   fatals -- error signal prints a warning and resets to default
-   value.  All error messages are printed to stderr, *not* to
-   opt.lfile, since opt.lfile wasn't even generated yet.  */
-int
-setval (const char *com, const char *val)
+/* Run commands[comind].action. */
+
+static int
+setval_internal (int comind, const char *com, const char *val)
 {
-  int ind;
+  assert (0 <= comind && comind < countof (commands));
+  return ((*commands[comind].action) (com, val, commands[comind].closure));
+}
 
-  if (!com || !val)
-    return 0;
-  ind = comind (com);
-  if (ind == -1)
+/* Run command COM with value VAL.  If running the command produces an
+   error, report the error and exit.
+
+   This is intended to be called from main() with commands not
+   provided by the user, therefore it aborts when an unknown command
+   is encountered.  Once the COMIND's are exported to init.h, this
+   function will be changed to accept COMIND directly.  */
+
+void
+setoptval (const char *com, const char *val)
+{
+  int comind = findcmd (com);
+  assert (comind != -1);
+  if (!setval_internal (comind, com, val))
+    exit (2);
+}
+
+void
+run_command (const char *opt)
+{
+  char *com, *val;
+  int comind;
+  int status = parse_line (opt, &com, &val, &comind);
+  if (status == 1)
     {
-      /* #### Should I just abort()?  */
-#ifdef DEBUG
-      fprintf (stderr, _("%s: BUG: unknown command `%s', value `%s'.\n"),
-	       exec_name, com, val);
-#endif
-      return 0;
+      if (!setval_internal (comind, com, val))
+	exit (2);
+      xfree (com);
+      xfree (val);
+    }
+  else if (status == 0)
+    {
+      fprintf (stderr, "Invalid command `%s'\n", opt);
+      exit (2);
     }
-  return ((*commands[ind].action) (com, val, commands[ind].closure));
 }
 
 /* Generic helper functions, for use with `commands'. */
