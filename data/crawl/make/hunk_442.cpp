     }
 
   /* If a symbol name was provided, use it.  */
-  fp = strchr (ldname, '(');
+  fp = strchr (*ldname, '(');
   if (fp)
     {
       const char *ep;
 
-      /* If there's an open paren, see if there's a close paren: if so use
+      /* There's an open paren, so see if there's a close paren: if so use
          that as the symbol name.  We can't have whitespace: it would have
          been chopped up before this function is called.  */
       ep = strchr (fp+1, ')');
       if (ep && ep[1] == '\0')
         {
-          int l = fp - ldname;;
+          int l = fp - *ldname;;
 
           ++fp;
           if (fp == ep)
-            fatal (flocp, _("Empty symbol name for load: %s"), ldname);
+            fatal (flocp, _("Empty symbol name for load: %s"), *ldname);
 
           /* Make a copy of the ldname part.  */
-          memcpy (new, ldname, l);
+          memcpy (new, *ldname, l);
           new[l] = '\0';
-          ldname = new;
+          *ldname = new;
 
           /* Make a copy of the symbol name part.  */
           symname = new + l + 1;
