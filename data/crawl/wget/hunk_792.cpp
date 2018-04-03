 void set_current_charset (char *charset)
 {
   /*printf("[ current = `%s'\n", charset);*/
-
   if (current)
     xfree (current);
 
 get_ugly_no_encode()
 src/iri.c | 7 +------
 src/iri.h | 1 -
 src/url.c | 2 +-
 3 files changed, 2 insertions(+), 8 deletions(-)
