 		die("tag '%s' already exists", tag);
 
 	if (annotate)
-		create_tag(object, tag, message, sign, object);
+		create_tag(object, tag, &buf, message, sign, object);
 
 	lock = lock_any_ref_for_update(ref, prev, 0);
 	if (!lock)
 		die("%s: cannot lock the ref", ref);
 	if (write_ref_sha1(lock, object, NULL) < 0)
 		die("%s: cannot update the ref", ref);
 
+	strbuf_release(&buf);
 	return 0;
 }
