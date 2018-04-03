       }
 
     /* Assert that the GPL license symbol is defined.  */
-    symp = dlsym (*dlp, "plugin_is_GPL_compatible");
+    symp = dlsym (dlp, "plugin_is_GPL_compatible");
     if (! symp)
       fatal (flocp, _("Loaded object %s is not declared to be GPL compatible"),
              ldname);
 
-    symp = dlsym (*dlp, symname);
+    symp = dlsym (dlp, symname);
     if (! symp)
       fatal (flocp, _("Failed to load symbol %s from %s: %s"),
              symname, ldname, dlerror());
+
+    /* Add this symbol to a trivial lookup table.  This is not efficient but
+       it's highly unlikely we'll be loading lots of objects, and we only need
+       it to look them up on unload, if we rebuild them.  */
+    new = xmalloc (sizeof (struct load_list));
+    new->name = xstrdup (ldname);
+    new->dlp = dlp;
+    new->next = loaded_syms;
+    loaded_syms = new;
   }
 
   return symp;
 }
 
 int
-load_file (const gmk_floc *flocp, const char **ldname, int noerror, void **dlp)
+load_file (const gmk_floc *flocp, const char **ldname, int noerror)
 {
   int nmlen = strlen (*ldname);
   char *new = alloca (nmlen + CSTRLEN (SYMBOL_EXTENSION) + 1);
