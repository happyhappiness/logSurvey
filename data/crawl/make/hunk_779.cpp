    each occurrence of SUBST with REPLACE. TEXT is null-terminated.  SLEN is
    the length of SUBST and RLEN is the length of REPLACE.  If BY_WORD is
    nonzero, substitutions are done only on matches which are complete
-   whitespace-delimited words.  If SUFFIX_ONLY is nonzero, substitutions are
-   done only at the ends of whitespace-delimited words.  */
+   whitespace-delimited words.  */
 
 char *
 subst_expand (char *o, char *text, char *subst, char *replace,
-              unsigned int slen, unsigned int rlen,
-              int by_word, int suffix_only)
+              unsigned int slen, unsigned int rlen, int by_word)
 {
   char *t = text;
   unsigned int tlen = strlen (text);
   char *p;
 
-  if (slen == 0 && !by_word && !suffix_only)
+  if (slen == 0 && !by_word)
     {
       /* The first occurrence of "" in any string is its end.  */
       o = variable_buffer_output (o, t, tlen);
