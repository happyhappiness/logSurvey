 static void
 self_destruct(void)
 {
-    snprintf(fatal_str, BUFSIZ, "Bungled %s line %d: %s",
+    fatalf("Bungled %s line %d: %s",
 	cfg_filename, config_lineno, config_input_line);
-    fatal(fatal_str);
 }
 
 void
