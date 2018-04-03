 		ret = check_symref(argv[0], 1, 0, 0);
 		if (ret)
 			die("Cannot delete %s, not a symbolic ref", argv[0]);
+		if (!strcmp(argv[0], "HEAD"))
+			die("deleting '%s' is not allowed", argv[0]);
 		return delete_ref(argv[0], NULL, REF_NODEREF);
 	}
 
