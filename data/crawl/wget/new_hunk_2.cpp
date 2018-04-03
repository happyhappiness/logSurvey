
static bool check_user_specified_header (const char *);

#ifdef HAVE_LIBZ
static bool
cmd_spec_compression (const char *com, const char *val, void *place)
{
  static const struct decode_item choices[] = {
    { "auto", compression_auto },
    { "gzip", compression_gzip },
    { "none", compression_none },
  };
  int ok = decode_string (val, choices, countof (choices), place);
  if (!ok)
    {
      fprintf (stderr, _("%s: %s: Invalid value %s.\n"), exec_name, com,
               quote (val));
    }
  return ok;
}
#endif

static bool
cmd_spec_dirstruct (const char *com, const char *val, void *place_ignored _GL_UNUSED)
{
