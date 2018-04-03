            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
          };
          time_t tstamp = f->tstamp;
          struct tm *ptm = localtime (&tstamp);

          fprintf (fp, "%d %s %02d ", ptm->tm_year + 1900, months[ptm->tm_mon],
                  ptm->tm_mday);
src/ChangeLog | 5 +++++
src/http.c    | 2 +-
2 files changed, 6 insertions(+), 1 deletion(-)
