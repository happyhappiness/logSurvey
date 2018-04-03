 {
 	if (!strcmp(var, "format.headers")) {
 		if (!value)
-			die("format.headers without value");
+			die(_("format.headers without value"));
 		add_header(value);
 		return 0;
 	}
