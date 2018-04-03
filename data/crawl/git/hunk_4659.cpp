 		const char *rb = strchr(force_author, '>');
 
 		if (!lb || !rb)
-			die("malformed --author parameter");
+			die(_("malformed --author parameter"));
 		name = xstrndup(force_author, lb - force_author);
 		email = xstrndup(lb + 2, rb - (lb + 2));
 	}
