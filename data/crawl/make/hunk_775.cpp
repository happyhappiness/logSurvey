               unsigned int slen, unsigned int rlen, int by_word)
 {
   char *t = text;
-  unsigned int tlen = strlen (text);
   char *p;
 
   if (slen == 0 && !by_word)
     {
       /* The first occurrence of "" in any string is its end.  */
-      o = variable_buffer_output (o, t, tlen);
+      o = variable_buffer_output (o, t, strlen (t));
       if (rlen > 0)
 	o = variable_buffer_output (o, replace, rlen);
       return o;
