      if (host_lookup_failed)
        {
          request_free (req);
          logprintf(LOG_NOTQUIET,
                    _("%s: unable to resolve host address `%s'\n"),
                    exec_name, relevant->host);
          return HOSTERR;
        }

src/http.c | 12 ++++--------
1 file changed, 4 insertions(+), 8 deletions(-)
