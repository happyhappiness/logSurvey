 
 	ref->value = xcalloc(sizeof(struct atom_value), used_atom_cnt);
 
-	buf = get_obj(ref->objectname, &obj, &size, &eaten);
-	if (!buf)
-		die("missing object %s for %s",
-		    sha1_to_hex(ref->objectname), ref->refname);
-	if (!obj)
-		die("parse_object_buffer failed on %s for %s",
-		    sha1_to_hex(ref->objectname), ref->refname);
-
 	/* Fill in specials first */
 	for (i = 0; i < used_atom_cnt; i++) {
 		const char *name = used_atom[i];
