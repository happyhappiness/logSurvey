   if (!silent)
     logprintf (LOG_NOTQUIET,
                _("Syntax error in Set-Cookie: %s at position %d.\n"),
-               escnonprint (set_cookie), (int) (ptr - set_cookie));
+               quotearg_style (escape_quoting_style, set_cookie), 
+               (int) (ptr - set_cookie));
   delete_cookie (cookie);
   return NULL;
 }
