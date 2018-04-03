 	if (i != argc)
 		usage(builtin_pack_refs_usage);
 
-	fd = hold_lock_file_for_update(&packed, git_path("packed-refs"), 1);
-	cbdata.refs_file = fdopen(fd, "w");
-	if (!cbdata.refs_file)
-		die("unable to create ref-pack file structure (%s)",
-		    strerror(errno));
-
-	/* perhaps other traits later as well */
-	fprintf(cbdata.refs_file, "# pack-refs with: peeled \n");
-
-	for_each_ref(handle_one_ref, &cbdata);
-	fflush(cbdata.refs_file);
-	fsync(fd);
-	fclose(cbdata.refs_file);
-	if (commit_lock_file(&packed) < 0)
-		die("unable to overwrite old ref-pack file (%s)", strerror(errno));
-	if (cbdata.prune)
-		prune_refs(cbdata.ref_to_prune);
-	return 0;
+	return pack_refs(flags);
 }