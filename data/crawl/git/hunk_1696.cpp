 
 	if (verbose)
 		fprintf(stderr, "Checking %s %s\n",
-			typename(obj->type), oid_to_hex(&obj->oid));
+			typename(obj->type), describe_object(obj));
 
 	if (fsck_walk(obj, NULL, &fsck_obj_options))
 		objerror(obj, "broken links");
