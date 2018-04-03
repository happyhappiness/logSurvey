 
 		if (check_ref_format(argv[2]))
 			exit(1);
-		if (normalize_path_copy(refname, argv[2]))
-			die("Could not normalize ref name '%s'", argv[2]);
+		collapse_slashes(refname, argv[2]);
 		printf("%s\n", refname);
 		exit(0);
 	}