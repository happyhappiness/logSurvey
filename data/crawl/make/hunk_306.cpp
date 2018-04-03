 }
 
 static void
-decode_trace_flags (void)
-{
-  const char **pp;
-
-  if (!trace_option)
-    return;
-
-  for (pp=trace_option->list; *pp; ++pp)
-    {
-      const char *p = *pp;
-
-      if (streq (p, "none"))
-        trace_flag = TRACE_NONE;
-      else if (streq (p, "rule"))
-        trace_flag |= TRACE_RULE;
-      else if (streq (p, "dir"))
-        trace_flag |= TRACE_DIRECTORY;
-      else
-        fatal (NILF, _("unknown trace mode '%s'"), p);
-    }
-}
-
-static void
 decode_output_sync_flags (void)
 {
   const char **pp;
