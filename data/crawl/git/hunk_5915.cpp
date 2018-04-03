 				       LOCK_DIE_ON_ERROR);
 	cbdata.refs_file = fdopen(fd, "w");
 	if (!cbdata.refs_file)
-		die("unable to create ref-pack file structure (%s)",
-		    strerror(errno));
+		die_errno("unable to create ref-pack file structure");
 
 	/* perhaps other traits later as well */
 	fprintf(cbdata.refs_file, "# pack-refs with: peeled \n");
