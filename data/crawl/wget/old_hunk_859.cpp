      char *tmp = strchr (type, ';');
      if (tmp)
        {
          while (tmp > type && c_isspace (tmp[-1]))
            --tmp;
          *tmp = '\0';
        }
    }
  hs->newloc = resp_header_strdup (resp, "Location");
Introduce iri.c and iri.h for achieving it
ChangeLog        |  4 ++++
configure.ac     |  4 ++++
src/ChangeLog    | 15 ++++++++++++
src/Makefile.am  |  8 +++++--
src/build_info.c |  7 ++++++
src/http.c       | 25 ++++----------------
src/init.c       |  6 -----
src/iri.c        | 70 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
src/iri.h        | 43 ++++++++++++++++++++++++++++++++++
src/main.c       | 13 ++++++-----
src/options.h    |  2 --
11 files changed, 161 insertions(+), 36 deletions(-)
create mode 100644 src/iri.c
create mode 100644 src/iri.h
