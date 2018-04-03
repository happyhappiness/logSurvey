#endif /* ENABLE_NLS */
}

#ifdef HAVE_HSTS
/* make the HSTS store global */
hsts_store_t hsts_store;

static char*
get_hsts_database (void)
{
  char *home;

  if (opt.hsts_file)
    return xstrdup (opt.hsts_file);

  home = home_dir ();
  if (home)
    return aprintf ("%s/.wget-hsts", home);

  return NULL;
}

static void
load_hsts (void)
{
  if (!hsts_store)
    {
      char *filename = get_hsts_database ();

      if (filename)
        {
          hsts_store = hsts_store_open (filename);

          if (!hsts_store)
            logprintf (LOG_NOTQUIET, "ERROR: could not open HSTS store at '%s'. "
                       "HSTS will be disabled.\n",
                       filename);
        }
      else
        logprintf (LOG_NOTQUIET, "ERROR: could not open HSTS store. HSTS will be disabled.\n");

      xfree (filename);
    }
}

static void
save_hsts (void)
{
  if (hsts_store)
    {
      char *filename = get_hsts_database ();

      hsts_store_save (hsts_store, filename);
      hsts_store_close (hsts_store);

      xfree (filename);
    }
}
#endif

/* Definition of command-line options. */

static void _Noreturn print_help (void);
