   /* Convert the character to UTF-8.  */
   count = utf8_wctomb ((unsigned char *) inbuf, code);
   if (count < 0)
-    error (1, 0, _("U+%04X: character out of range"), code);
+    {
+      errno = EILSEQ;
+      return failure (code, callback_arg);
+    }
 
   if (is_utf8)
     {
-      callback (inbuf, count, callback_arg);
+      return success (inbuf, count, callback_arg);
     }
   else
     {
