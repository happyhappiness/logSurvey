   return true;
 }
 
+
+static bool
+cmd_use_askpass (const char *com _GL_UNUSED, const char *val, void *place)
+{
+  char *env_name = "WGET_ASKPASS";
+  char *env;
+
+  if (val && *val)
+    {
+      if (!file_exists_p (val))
+        {
+          fprintf (stderr, _("%s does not exist.\n"), val);
+          exit (WGET_EXIT_GENERIC_ERROR);
+        }
+      return cmd_string (com, val, place);
+    }
+
+  env = getenv (env_name);
+  if (!(env && *env))
+    {
+      env_name = "SSH_ASKPASS";
+      env = getenv (env_name);
+    }
+
+  if (!(env && *env))
+    {
+      fprintf (stderr, _("use-askpass requires a string or either environment variable WGET_ASKPASS or SSH_ASKPASS to be set.\n"));
+      exit (WGET_EXIT_GENERIC_ERROR);
+    }
+
+  if (!file_exists_p (env))
+    {
+      fprintf (stderr, _("%s points to %s, which does not exist.\n"),
+              env_name, env);
+      exit (WGET_EXIT_GENERIC_ERROR);
+    }
+
+  return cmd_string (com, env, place);
+}
+
 #ifdef HAVE_SSL
 static bool
 cmd_cert_type (const char *com, const char *val, void *place)
