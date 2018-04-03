       return xstrdup (env);
     }
 
-#ifndef WINDOWS
   /* If that failed, try $HOME/.wgetrc.  */
   home = home_dir ();
   if (home)
-    {
-      file = (char *)xmalloc (strlen (home) + 1 + strlen (".wgetrc") + 1);
-      sprintf (file, "%s/.wgetrc", home);
-    }
+    file = aprintf ("%s/.wgetrc", home);
   xfree_null (home);
-#else  /* WINDOWS */
-  /* Under Windows, "home" is (for the purposes of this function) the
-     directory where `wget.exe' resides, and `wget.ini' will be used
-     as file name.  SYSTEM_WGETRC should not be defined under WINDOWS.
 
-     It is not as trivial as I assumed, because on 95 argv[0] is full
-     path, but on NT you get what you typed in command line.  --dbudor */
-  home = ws_mypath ();
-  if (home)
+#ifdef WINDOWS
+  /* Under Windows, if we still haven't found .wgetrc, look for the file
+     `wget.ini' in the directory where `wget.exe' resides; we do this for
+     backward compatibility with previous versions of Wget.
+     SYSTEM_WGETRC should not be defined under WINDOWS.  */
+  if (!file || !file_exists_p (file))
     {
-      file = (char *)xmalloc (strlen (home) + strlen ("wget.ini") + 1);
-      sprintf (file, "%swget.ini", home);
+      xfree_null (file);
+      file = NULL;
+      home = ws_mypath ();
+      if (home)
+	file = aprintf ("%s/wget.ini", home);
     }
 #endif /* WINDOWS */
 
