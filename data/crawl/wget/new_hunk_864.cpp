  if (opt.enable_iri)
    {
      if (!opt.locale)
        opt.locale = find_locale ();

      /* sXXXav : check given locale and remote encoding */

      logprintf (LOG_VERBOSE, "Locale = %s\n", quote (opt.locale));
    }
#else
  if (opt.enable_iri || opt.locale || opt.encoding_remote)
iri.c
src/ChangeLog | 8 ++++++++
src/init.c    | 8 ++++++++
src/iri.c     | 4 +++-
3 files changed, 19 insertions(+), 1 deletion(-)
