          else
            {
              logprintf (LOG_NOTQUIET, _("%s ERROR %d: %s.\n"),
                         tms, hstat.statcode,
                         quotearg_style (escape_quoting_style, hstat.error));
            }
          logputs (LOG_VERBOSE, "\n");
same for a global and a local one
src/iri.c | 37 +++++++++++++++++++++++--------------
1 file changed, 23 insertions(+), 14 deletions(-)
