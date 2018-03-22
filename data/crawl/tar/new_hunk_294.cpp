void
argmatch_invalid (const char *context, const char *value, int problem)
{
  char const *format = (problem == -1
			? _("invalid argument %s for %s")
			: _("ambiguous argument %s for %s"));

  error (0, 0, format, quotearg_n_style (0, ARGMATCH_QUOTING_STYLE, value),
	 quote_n (1, context));
}

/* List the valid arguments for argmatch.
