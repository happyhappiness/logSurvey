               unsigned int slen, unsigned int rlen,
               int by_word, int suffix_only)
 {
-  register char *t = text;
-  register char *p;
+  char *t = text;
+  unsigned int tlen = strlen (text);
+  char *p;
 
   if (slen == 0 && !by_word && !suffix_only)
     {
       /* The first occurrence of "" in any string is its end.  */
-      o = variable_buffer_output (o, t, strlen (t));
+      o = variable_buffer_output (o, t, tlen);
       if (rlen > 0)
 	o = variable_buffer_output (o, replace, rlen);
       return o;
