   char *new;
   int ret;
 
-  ret = idna_to_unicode_8zlz (host, &new, 0);
+  ret = idna_to_unicode_8zlz (host, &new, IDNA_FLAGS);
   if (ret != IDNA_SUCCESS)
     {
       logprintf (LOG_VERBOSE, "idn_decode failed (%d): %s\n", ret,
 changed
 src/iri.c | 30 ++++++++++++++++++++++++------
 1 file changed, 24 insertions(+), 6 deletions(-)
