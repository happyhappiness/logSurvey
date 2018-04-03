  return true;
}

/* Validate --regex-type and set the choice.  */

static bool
cmd_spec_regex_type (const char *com, const char *val, void *place_ignored)
{
  static const struct decode_item choices[] = {
    { "posix", regex_type_posix },
#ifdef HAVE_LIBPCRE
    { "pcre",  regex_type_pcre },
#endif
  };
  int regex_type = regex_type_posix;
  int ok = decode_string (val, choices, countof (choices), &regex_type);
  if (!ok)
    fprintf (stderr, _("%s: %s: Invalid value %s.\n"), exec_name, com, quote (val));
  opt.regex_type = regex_type;
  return ok;
}

static bool
cmd_spec_restrict_file_names (const char *com, const char *val, void *place_ignored)
{