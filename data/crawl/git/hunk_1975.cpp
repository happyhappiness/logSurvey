 
 const char *current_config_origin_type(void)
 {
-	if (!cf)
+	const char *type;
+	if (current_config_kvi)
+		type = current_config_kvi->origin_type;
+	else if(cf)
+		type = cf->origin_type;
+	else
 		die("BUG: current_config_origin_type called outside config callback");
-	return cf->origin_type ? cf->origin_type : "command line";
+	return type ? type : "command line";
 }
 
 const char *current_config_name(void)
 {
-	if (!cf)
+	const char *name;
+	if (current_config_kvi)
+		name = current_config_kvi->filename;
+	else if (cf)
+		name = cf->name;
+	else
 		die("BUG: current_config_name called outside config callback");
-	return cf->name ? cf->name : "";
+	return name ? name : "";
 }
