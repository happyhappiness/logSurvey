 		die("BUG: current_config_name called outside config callback");
 	return name ? name : "";
 }
+
+enum config_scope current_config_scope(void)
+{
+	if (current_config_kvi)
+		return current_config_kvi->scope;
+	else
+		return current_parsing_scope;
+}
