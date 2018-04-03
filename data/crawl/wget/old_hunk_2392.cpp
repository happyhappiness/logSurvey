      if (host_lookup_failed)
        {
          request_free (req);
          return HOSTERR;
        }

src/http.c | 12 ++++--------
1 file changed, 4 insertions(+), 8 deletions(-)
