      at this time, since they won't get snapped and we'll get core dumps.
      See Savannah bug # 12124.  */
   if (snapped_deps)
-    fatal (flocp, _("prerequisites cannot be defined in command scripts"));
+    fatal (flocp, _("prerequisites cannot be defined in recipes"));
 
   if (commands_idx > 0)
     {
