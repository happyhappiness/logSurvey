 	struct name_entry entry;
 	struct name_path me;
 
+	if (!tree)
+		die("bad tree object");
 	if (obj->flags & SEEN)
 		return;
 	obj->flags |= SEEN;