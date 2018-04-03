 
   home = home_dir ();
   if (home)
-    return aprintf ("%s/.wget-hsts", home);
+    {
+      char *dir = aprintf ("%s/.wget-hsts", home);
+      xfree(home);
+      return dir;
+    }
 
   return NULL;
 }
