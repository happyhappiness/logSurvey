 
 const char *current_config_origin_type(void)
 {
-	return cf && cf->origin_type ? cf->origin_type : "command line";
+	if (!cf)
+		die("BUG: current_config_origin_type called outside config callback");
+	return cf->origin_type ? cf->origin_type : "command line";
 }
 
 const char *current_config_name(void)
 {
-	return cf && cf->name ? cf->name : "";
+	if (!cf)
+		die("BUG: current_config_name called outside config callback");
+	return cf->name ? cf->name : "";
 }