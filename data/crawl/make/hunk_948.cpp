   switch (v->origin)
     {
     case o_default:
-      origin = "default";
+      origin = _("default");
       break;
     case o_env:
-      origin = "environment";
+      origin = _("environment");
       break;
     case o_file:
-      origin = "makefile";
+      origin = _("makefile");
       break;
     case o_env_override:
-      origin = "environment under -e";
+      origin = _("environment under -e");
       break;
     case o_command:
-      origin = "command line";
+      origin = _("command line");
       break;
     case o_override:
-      origin = "`override' directive";
+      origin = _("`override' directive");
       break;
     case o_automatic:
-      origin = "automatic";
+      origin = _("automatic");
       break;
     case o_invalid:
     default:
       abort ();
     }
-  printf ("# %s\n", origin);
-
+  fputs ("# ", stdout);
+  fputs (origin, stdout);
+  if (v->fileinfo.filenm)
+    printf (" (from `%s', line %lu)", v->fileinfo.filenm, v->fileinfo.lineno);
+  putchar ('\n');
   fputs (prefix, stdout);
 
   /* Is this a `define'?  */
