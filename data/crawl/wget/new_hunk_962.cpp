    }

  /* Try to not encode in UTF-8 if fetching failed */
  if (!(*dt & RETROKF) && utf8_encoded)
    {
      utf8_encoded = false;
      /*printf ("[Fallbacking to non-utf8 for `%s'\n", url);*/
UGLY :)
src/html-url.c | 14 +++++++++-----
src/iri.c      | 27 +++++++++++++++++++++++++++
src/iri.h      | 10 ++++++++++
src/main.c     |  1 +
src/recur.c    | 17 +++++++++++------
src/retr.c     | 26 +++++++++++++++-----------
src/url.c      | 12 +++++++-----
src/url.h      |  2 +-
8 files changed, 81 insertions(+), 28 deletions(-)
