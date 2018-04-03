 		return;
 	}
 
-	o = parse_object(ref->old_oid.hash);
+	o = parse_object(&ref->old_oid);
 	if (!o) {
 		fprintf(stderr,
 			"Unable to parse object %s for remote ref %s\n",
