 
 void self_destruct()
 {
-    sprintf(fatal_str, "Bungled cached.conf line %d: %s",
-	config_lineno, config_input_line);
+    sprintf(fatal_str, "Bungled %s line %d: %s",
+	cfg_filename, config_lineno, config_input_line);
     fatal(fatal_str);
 }
 
