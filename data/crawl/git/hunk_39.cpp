 		die("Objects must be of the same type.\n"
 		    "'%s' points to a replaced object of type '%s'\n"
 		    "while '%s' points to a replacement object of type '%s'.",
-		    object_ref, typename(obj_type),
-		    replace_ref, typename(repl_type));
+		    object_ref, type_name(obj_type),
+		    replace_ref, type_name(repl_type));
 
 	check_ref_valid(object, &prev, &ref, force);
 
