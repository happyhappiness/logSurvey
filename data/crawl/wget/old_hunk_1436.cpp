          else
            {
              logprintf (LOG_NOTQUIET, _("%s ERROR %d: %s.\n"),
                         tms, hstat.statcode, escnonprint (hstat.error));
            }
          logputs (LOG_VERBOSE, "\n");
          ret = WRONGCODE;
src/openssl.c | 14 ++++++++------
1 file changed, 8 insertions(+), 6 deletions(-)
