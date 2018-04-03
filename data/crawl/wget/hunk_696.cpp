   if (!(*dt & RETROKF) && iri->utf8_encode)
     {
       iri->utf8_encode = false;
-      printf ("[Fallbacking to non-utf8 for `%s'\n", url);
+      DEBUGP (("[IRI Fallbacking to non-utf8 for %s\n", quote (url)));
       goto second_try;
     }
 
 src/iri.h | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
