 	if (!value)
 		value = "";
 
-	if (cf && cf->name)
-		die(_("bad numeric config value '%s' for '%s' in %s: %s"),
-		    value, name, cf->name, reason);
+	if (cf && cf->origin_type && cf->name)
+		die(_("bad numeric config value '%s' for '%s' in %s %s: %s"),
+		    value, name, cf->origin_type, cf->name, reason);
 	die(_("bad numeric config value '%s' for '%s': %s"), value, name, reason);
 }
 
