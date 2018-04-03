    FILENAME and LINENO are the filename and line number in the
    current makefile.  They are used for error messages.
 
-   Value is -1 if the line is invalid,
+   Value is -2 if the line is not a conditional at all,
+   -1 if the line is an invalid conditional,
    0 if following text should be interpreted,
    1 if following text should be ignored.  */
 
 static int
-conditional_line (char *line, const struct floc *flocp)
+conditional_line (char *line, int len, const struct floc *flocp)
 {
-  int notdef;
   char *cmdname;
-  register unsigned int i;
-
-  if (*line == 'i')
-    {
-      /* It's an "if..." command.  */
-      notdef = line[2] == 'n';
-      if (notdef)
-	{
-	  cmdname = line[3] == 'd' ? "ifndef" : "ifneq";
-	  line += cmdname[3] == 'd' ? 7 : 6;
-	}
-      else
-	{
-	  cmdname = line[2] == 'd' ? "ifdef" : "ifeq";
-	  line += cmdname[2] == 'd' ? 6 : 5;
-	}
-    }
+  enum { c_ifdef, c_ifndef, c_ifeq, c_ifneq, c_else, c_endif } cmdtype;
+  unsigned int i;
+  unsigned int o;
+
+  /* Compare a word, both length and contents. */
+#define	word1eq(s)      (len == sizeof(s)-1 && strneq (s, line, sizeof(s)-1))
+#define	chkword(s, t)   if (word1eq (s)) { cmdtype = (t); cmdname = (s); }
+
+  /* Make sure this line is a conditional.  */
+  chkword ("ifdef", c_ifdef)
+  else chkword ("ifndef", c_ifndef)
+  else chkword ("ifeq", c_ifeq)
+  else chkword ("ifneq", c_ifneq)
+  else chkword ("else", c_else)
+  else chkword ("endif", c_endif)
   else
-    {
-      /* It's an "else" or "endif" command.  */
-      notdef = line[1] == 'n';
-      cmdname = notdef ? "endif" : "else";
-      line += notdef ? 5 : 4;
-    }
+    return -2;
+
+  /* Found one: skip past it and any whitespace after it.  */
+  line = next_token (line + len);
 
-  line = next_token (line);
+#define EXTRANEOUS() error (flocp, _("Extraneous text after `%s' directive"), cmdname)
 
-  if (*cmdname == 'e')
+  /* An 'endif' cannot contain extra text, and reduces the if-depth by 1  */
+  if (cmdtype == c_endif)
     {
       if (*line != '\0')
-	error (flocp, _("Extraneous text after `%s' directive"), cmdname);
-      /* "Else" or "endif".  */
-      if (conditionals->if_cmds == 0)
+	EXTRANEOUS ();
+
+      if (!conditionals->if_cmds)
+	fatal (flocp, _("extraneous `%s'"), cmdname);
+
+      --conditionals->if_cmds;
+
+      goto DONE;
+    }
+
+  /* An 'else' statement can either be simple, or it can have another
+     conditional after it.  */
+  if (cmdtype == c_else)
+    {
+      const char *p;
+
+      if (!conditionals->if_cmds)
 	fatal (flocp, _("extraneous `%s'"), cmdname);
-      /* NOTDEF indicates an `endif' command.  */
-      if (notdef)
-	--conditionals->if_cmds;
-      else if (conditionals->seen_else[conditionals->if_cmds - 1])
-	fatal (flocp, _("only one `else' per conditional"));
+
+      o = conditionals->if_cmds - 1;
+
+      if (conditionals->seen_else[o])
+        fatal (flocp, _("only one `else' per conditional"));
+
+      /* Change the state of ignorance.  */
+      switch (conditionals->ignoring[o])
+        {
+          case 0:
+            /* We've just been interpreting.  Never do it again.  */
+            conditionals->ignoring[o] = 2;
+            break;
+          case 1:
+            /* We've never interpreted yet.  Maybe this time!  */
+            conditionals->ignoring[o] = 0;
+            break;
+        }
+
+      /* It's a simple 'else'.  */
+      if (*line == '\0')
+        {
+          conditionals->seen_else[o] = 1;
+          goto DONE;
+        }
+
+      /* The 'else' has extra text.  That text must be another conditional
+         and cannot be an 'else' or 'endif'.  */
+
+      /* Find the length of the next word.  */
+      for (p = line+1; *p != '\0' && !isspace ((unsigned char)*p); ++p)
+        ;
+      len = p - line;
+
+      /* If it's 'else' or 'endif' or an illegal conditional, fail.  */
+      if (word1eq("else") || word1eq("endif")
+          || conditional_line (line, len, flocp) < 0)
+	EXTRANEOUS ();
       else
-	{
-	  /* Toggle the state of ignorance.  */
-	  conditionals->ignoring[conditionals->if_cmds - 1]
-	    = !conditionals->ignoring[conditionals->if_cmds - 1];
-	  /* Record that we have seen an `else' in this conditional.
-	     A second `else' will be erroneous.  */
-	  conditionals->seen_else[conditionals->if_cmds - 1] = 1;
-	}
-      for (i = 0; i < conditionals->if_cmds; ++i)
-	if (conditionals->ignoring[i])
-	  return 1;
-      return 0;
+        {
+          /* conditional_line() created a new level of conditional.
+             Raise it back to this level.  */
+          if (conditionals->ignoring[o] < 2)
+            conditionals->ignoring[o] = conditionals->ignoring[o+1];
+          --conditionals->if_cmds;
+        }
+
+      goto DONE;
     }
 
   if (conditionals->allocated == 0)
