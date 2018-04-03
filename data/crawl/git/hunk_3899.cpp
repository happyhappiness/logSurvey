 {
 	struct object *o = lookup_unknown_object(sha1);
 
-	if (ref_is_hidden(refname))
+	if (ref_is_hidden(refname)) {
+		o->flags |= HIDDEN_REF;
 		return 1;
+	}
 	if (!o)
 		die("git upload-pack: cannot find object %s:", sha1_to_hex(sha1));
 	o->flags |= OUR_REF;
