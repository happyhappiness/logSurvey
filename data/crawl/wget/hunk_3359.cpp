 cmd_boolean (const char *com, const char *val, void *closure)
 {
   int bool_value;
-  const char *v = val;
-#define LC(x) TOLOWER(x)
-
-  if ((LC(v[0]) == 'o' && LC(v[1]) == 'n' && !v[2])
-      ||
-      (LC(v[0]) == 'y' && LC(v[1]) == 'e' && LC(v[2]) == 's' && !v[3])
-      ||
-      (v[0] == '1' && !v[1]))
+
+  if (CMP2 (val, 'o', 'n') || CMP3 (val, 'y', 'e', 's') || CMP1 (val, '1'))
     /* "on", "yes" and "1" mean true. */
     bool_value = 1;
-  else if ((LC(v[0]) == 'o' && LC(v[1]) == 'f' && LC(v[2]) == 'f' && !v[3])
-	   ||
-	   (LC(v[0]) == 'n' && LC(v[1]) == 'o' && !v[2])
-	   ||
-	   (v[0] == '0' && !v[1]))
+  else if (CMP3 (val, 'o', 'f', 'f') || CMP2 (val, 'n', 'o') || CMP1 (val, '0'))
     /* "off", "no" and "0" mean false. */
     bool_value = 0;
   else
     {
-      fprintf (stderr, _("%s: %s: Please specify on or off.\n"),
-	       exec_name, com);
+      fprintf (stderr,
+	       _("%s: %s: Invalid boolean `%s', use `on' or `off'.\n"),
+	       exec_name, com, val);
       return 0;
     }
 
