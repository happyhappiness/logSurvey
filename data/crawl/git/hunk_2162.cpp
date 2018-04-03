 
 	expanded = expand_user_path(path);
 	if (!expanded)
-		return error("Could not expand include path '%s'", path);
+		return error("could not expand include path '%s'", path);
 	path = expanded;
 
 	/*
