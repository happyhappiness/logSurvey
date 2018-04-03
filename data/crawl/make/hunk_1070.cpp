 ar_touch (name)
      char *name;
 {
-  error (NILF, "touch archive member is not available on VMS");
+  error (NILF, _("touch archive member is not available on VMS"));
   return -1;
 }
 #else
