       if (home)
         file = aprintf ("%s/wget.ini", home);
     }
+  xfree_null (home);
 #endif /* WINDOWS */
 
   if (!file)
