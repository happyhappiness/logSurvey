#ifdef ENABLE_IRI
  if (opt.enable_iri)
    {
      if (!opt.locale)
        opt.locale = find_locale ();

      /* sXXXav : check given locale and remote encoding */

      logprintf (LOG_VERBOSE, "Locale = %s\n", quote (opt.locale));
    }
src/ChangeLog | 2 +-
1 file changed, 1 insertion(+), 1 deletion(-)
