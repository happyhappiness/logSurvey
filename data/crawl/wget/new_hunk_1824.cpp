          /* #### This message SUCKS.  We should see what was the
             reason that nothing was retrieved.  */
          logprintf (LOG_VERBOSE, _("No matches on pattern %s.\n"),
                     quote (u->file));
        }
      else /* GLOB_GETONE or GLOB_GETALL */
        {
src/gnutls.c | 8 ++++----
1 file changed, 4 insertions(+), 4 deletions(-)
