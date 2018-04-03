       return xstrdup (env);
     }
 
-  /* If that failed, try $HOME/.wgetrc.  */
+  /* If that failed, try $HOME/.wgetrc (or equivalent).  */
+
+#ifdef __VMS
+  file = "SYS$LOGIN:.wgetrc";
+#else /* def __VMS */
   home = home_dir ();
   if (home)
     file = aprintf ("%s/.wgetrc", home);
   xfree_null (home);
+#endif /* def __VMS [else] */
 
 #ifdef WINDOWS
   /* Under Windows, if we still haven't found .wgetrc, look for the file
