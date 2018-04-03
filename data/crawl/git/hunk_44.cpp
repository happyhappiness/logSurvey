 		return error("%s: unable to read file.", name);
 	if (type != OBJ_COMMIT)
 		return error("%s: cannot verify a non-commit object of type %s.",
-				name, typename(type));
+				name, type_name(type));
 
 	ret = run_gpg_verify(&oid, buf, size, flags);
 
