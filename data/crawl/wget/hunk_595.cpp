         {
           if (!invalid)
             logprintf (LOG_VERBOSE,
-                      "Incomplete or invalide multibyte sequence encountered\n");
+                      _("Incomplete or invalide multibyte sequence encountered\n"));
 
           invalid++;
           **out = *in;
