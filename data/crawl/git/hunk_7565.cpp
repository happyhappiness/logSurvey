 
 	/* Verify DAV compliance/lock support */
 	if (!locking_available()) {
-		fprintf(stderr, "Error: no DAV locking support on remote repo %s\n", remote->url);
 		rc = 1;
 		goto cleanup;
 	}