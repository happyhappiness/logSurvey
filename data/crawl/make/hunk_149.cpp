 
   if (! (status & 1))
     {
-      error (NILF, _("unable to open library '%s' to lookup member '%s'"),
-             archive, (char *)arg);
+      OSS (error, NILF, _("unable to open library '%s' to lookup member '%s'"),
+           archive, arg);
       return -1;
     }
 
-  VMS_saved_memname = (char *)arg;
+  VMS_saved_memname = arg;
 
   /* For comparison, delete .obj from arg name.  */
 
