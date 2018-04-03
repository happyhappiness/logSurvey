 			     const char *path)
 {
 	if (!o->show_all_errors)
-		return error(ERRORMSG(o, e), path);
+		return error(ERRORMSG(o, e), super_prefixed(path));
 
 	/*
 	 * Otherwise, insert in a list for future display by
