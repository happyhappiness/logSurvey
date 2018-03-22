}


static char *
tar_help_filter (int key, const char *text, void *input)
{
  struct obstack stk;
  char *s;

  if (key != ARGP_KEY_HELP_EXTRA)
    return (char*) text;

  obstack_init (&stk);
  s = _("Valid arguments for the --quoting-style option are:");
  obstack_grow (&stk, s, strlen (s));
  obstack_grow (&stk, "\n\n", 2);
  tar_list_quoting_styles (&stk, "  ");
  s = _("\n*This* tar defaults to:\n");
  obstack_grow (&stk, s, strlen (s));
  s = format_default_settings ();
  obstack_grow (&stk, s, strlen (s));
  obstack_1grow (&stk, '\n');
  obstack_1grow (&stk, 0);
  s = xstrdup (obstack_finish (&stk));
  obstack_free (&stk, NULL);
  return s;
}

static error_t
