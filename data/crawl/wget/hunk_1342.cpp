         }
       return xstrdup (env);
     }
-
-  /* If that failed, try $HOME/.wgetrc.  */
-  home = home_dir ();
+  return NULL;
+}
+/* Check for the existance of '$HOME/.wgetrc' and return it's path
+   if it exists and is set.  */
+char *
+wgetrc_user_file_name (void) 
+{
+  char *home = home_dir();
+  char *file = NULL;
   if (home)
     file = aprintf ("%s/.wgetrc", home);
   xfree_null (home);
+  if (!file)
+    return NULL;
+  if (!file_exists_p (file))
+    {
+      xfree (file);
+      return NULL;
+    }
+  return file;
+}
+/* Return the path to the user's .wgetrc.  This is either the value of
+   `WGETRC' environment variable, or `$HOME/.wgetrc'.
+
+   Additionally, for windows, look in the directory where wget.exe 
+   resides.  */
+char *
+wgetrc_file_name (void)
+{
+  char *file = wgetrc_env_file_name ();
+  if (file && *file)
+    return file;
+
+  file = wgetrc_user_file_name ();
 
 #ifdef WINDOWS
   /* Under Windows, if we still haven't found .wgetrc, look for the file
