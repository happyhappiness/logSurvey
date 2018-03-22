 }
 
 
-static void
-tar_help (struct argp_state *state)
+static char *
+tar_help_filter (int key, const char *text, void *input)
 {
-  argp_fmtstream_t fs;
-  state->flags |= ARGP_NO_EXIT;
-  argp_state_help (state, state->out_stream,
-		   ARGP_HELP_STD_HELP & ~ARGP_HELP_BUG_ADDR);
-  /* FIXME: use struct uparams.rmargin (from argp-help.c) instead of 79 */
-  fs = argp_make_fmtstream (state->out_stream, 0, 79, 0);
-
-  argp_fmtstream_printf (fs, "\n%s\n\n",
-		       _("Valid arguments for --quoting-style options are:"));
-  tar_list_quoting_styles (fs, "  ");
-
-  argp_fmtstream_puts (fs, _("\n*This* tar defaults to:\n"));
-  show_default_settings_fs (fs);
-  argp_fmtstream_putc (fs, '\n');
-  argp_fmtstream_printf (fs, _("Report bugs to %s.\n"),
-			 argp_program_bug_address);
-  argp_fmtstream_free (fs);
+  struct obstack stk;
+  char *s;
+
+  if (key != ARGP_KEY_HELP_EXTRA)
+    return (char*) text;
+
+  obstack_init (&stk);
+  s = _("Valid arguments for the --quoting-style option are:");
+  obstack_grow (&stk, s, strlen (s));
+  obstack_grow (&stk, "\n\n", 2);
+  tar_list_quoting_styles (&stk, "  ");
+  s = _("\n*This* tar defaults to:\n");
+  obstack_grow (&stk, s, strlen (s));
+  s = format_default_settings ();
+  obstack_grow (&stk, s, strlen (s));
+  obstack_1grow (&stk, '\n');
+  obstack_1grow (&stk, 0);
+  s = xstrdup (obstack_finish (&stk));
+  obstack_free (&stk, NULL);
+  return s;
 }
 
 static error_t
