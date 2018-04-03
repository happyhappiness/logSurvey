 
 #define SYMBOL_EXTENSION        "_gmk_setup"
 
-static void *global_dl = NULL;
-
 #include "debug.h"
 #include "filedef.h"
 #include "variable.h"
 
-static int
-init_symbol (const gmk_floc *flocp, const char *ldname, load_func_t symp)
+static load_func_t
+load_object (const gmk_floc *flocp, int noerror,
+             const char *ldname, const char *symname)
 {
-  int r;
-  const char *p;
-  int nmlen = strlen (ldname);
-  char *loaded = allocated_variable_expand("$(.LOADED)");
+  static void *global_dl = NULL;
+  load_func_t symp;
 
-  /* If it's already been loaded don't do it again.  */
-  p = strstr (loaded, ldname);
-  r = p && (p==loaded || p[-1]==' ') && (p[nmlen]=='\0' || p[nmlen]==' ');
-  free (loaded);
-  if (r)
-    return 1;
+  if (! global_dl)
+    {
+      global_dl = dlopen (NULL, RTLD_NOW|RTLD_GLOBAL);
+      if (! global_dl)
+        fatal (flocp, _("Failed to open global symbol table: %s"), dlerror());
+    }
 
-  /* Now invoke the symbol.  */
-  r = (*symp) (flocp);
+  symp = (load_func_t) dlsym (global_dl, symname);
+  if (! symp) {
+    void *dlp = NULL;
 
-  /* If it succeeded, add the symbol to the loaded variable.  */
-  if (r > 0)
-    do_variable_definition (flocp, ".LOADED", ldname, o_default, f_append, 0);
+    /* If the path has no "/", try the current directory first.  */
+    if (! strchr (ldname, '/'))
+      dlp = dlopen (concat (2, "./", ldname), RTLD_LAZY|RTLD_GLOBAL);
 
-  return r;
+    /* If we haven't opened it yet, try the default search path.  */
+    if (! dlp)
+      dlp = dlopen (ldname, RTLD_LAZY|RTLD_GLOBAL);
+
+    /* Still no?  Then fail.  */
+    if (! dlp)
+      {
+        if (noerror)
+          DB (DB_BASIC, ("%s", dlerror()));
+        else
+          error (flocp, "%s", dlerror());
+        return NULL;
+      }
+
+    symp = dlsym (dlp, symname);
+    if (! symp)
+      fatal (flocp, _("Failed to load symbol %s from %s: %s"),
+             symname, ldname, dlerror());
+  }
+
+  return symp;
 }
 
 int
 load_file (const gmk_floc *flocp, const char **ldname, int noerror)
 {
-  load_func_t symp;
-  const char *fp;
+  int nmlen = strlen (*ldname);
+  char *new = alloca (nmlen + CSTRLEN (SYMBOL_EXTENSION) + 1);
   char *symname = NULL;
-  char *new = alloca (strlen (*ldname) + CSTRLEN (SYMBOL_EXTENSION) + 1);
-
-  if (! global_dl)
-    {
-      global_dl = dlopen (NULL, RTLD_NOW|RTLD_GLOBAL);
-      if (! global_dl)
-        fatal (flocp, _("Failed to open global symbol table: %s"), dlerror());
-    }
+  char *loaded;
+  const char *fp;
+  int r;
+  load_func_t symp;
 
-  /* If a symbol name was provided, use it.  */
+  /* Break the input into an object file name and a symbol name.  If no symbol
+     name was provided, compute one from the object file name.  */
   fp = strchr (*ldname, '(');
   if (fp)
     {
