 	if (type < 0)
 		die("unable to get object type for %s", oid_to_hex(&old));
 
-	check_ref_valid(&old, &prev, ref, sizeof(ref), force);
+	check_ref_valid(&old, &prev, &ref, force);
+	strbuf_release(&ref);
 
 	export_object(&old, type, raw, tmpfile);
 	if (launch_editor(tmpfile, NULL, NULL) < 0)
