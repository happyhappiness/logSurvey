       unsigned int c;
 
       if (pattern != 0)
-        fatal (flocp, _("mixed implicit and static pattern rules"));
+        O (fatal, flocp, _("mixed implicit and static pattern rules"));
 
       /* Count the targets to create an array of target names.
          We already have the first one.  */
