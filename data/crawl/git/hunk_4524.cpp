 		setup_work_tree();
 
 	if (reset_type == MIXED && is_bare_repository())
-		die("%s reset is not allowed in a bare repository",
-		    reset_type_names[reset_type]);
+		die(_("%s reset is not allowed in a bare repository"),
+		    _(reset_type_names[reset_type]));
 
 	/* Soft reset does not touch the index file nor the working tree
 	 * at all, but requires them in a good order.  Other resets reset