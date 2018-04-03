 	if (get_sha1(ref, sha1))
 		die("Could not resolve ref '%s'", ref);
 	object = deref_tag(parse_object(sha1), ref, strlen(ref));
+	if (!object)
+		return NULL;
 	if (object->type == OBJ_TREE)
 		return make_virtual_commit((struct tree*)object,
 			better_branch_name(ref));
