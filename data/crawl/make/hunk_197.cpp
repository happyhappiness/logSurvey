       /* Still no?  Then fail.  */
       if (! dlp)
         {
+          const char *err = dlerror ();
           if (noerror)
-            DB (DB_BASIC, ("%s", dlerror ()));
+            DB (DB_BASIC, ("%s", err));
           else
-            error (flocp, "%s", dlerror ());
+            OS (error, flocp, "%s", err);
           return NULL;
         }
 
       /* Assert that the GPL license symbol is defined.  */
       symp = (load_func_t) dlsym (dlp, "plugin_is_GPL_compatible");
       if (! symp)
-        fatal (flocp, _("Loaded object %s is not declared to be GPL compatible"),
-               ldname);
+        OS (fatal, flocp,
+             _("Loaded object %s is not declared to be GPL compatible"),
+             ldname);
 
       symp = (load_func_t) dlsym (dlp, symname);
       if (! symp)
-        fatal (flocp, _("Failed to load symbol %s from %s: %s"),
-               symname, ldname, dlerror ());
+        {
+          const char *err = dlerror ();
+          OSSS (fatal, flocp, _("Failed to load symbol %s from %s: %s"),
+                symname, ldname, err);
+        }
 
       /* Add this symbol to a trivial lookup table.  This is not efficient but
          it's highly unlikely we'll be loading lots of objects, and we only
