 	const char *name = patch->old_name ? patch->old_name : patch->new_name;
 	unsigned ws_rule = patch->ws_rule;
 	unsigned inaccurate_eof = patch->inaccurate_eof;
+	int nth = 0;
 
 	if (patch->is_binary)
 		return apply_binary(img, patch);
 
 	while (frag) {
-		if (apply_one_fragment(img, frag, inaccurate_eof, ws_rule)) {
+		nth++;
+		if (apply_one_fragment(img, frag, inaccurate_eof, ws_rule, nth)) {
 			error("patch failed: %s:%ld", name, frag->oldpos);
 			if (!apply_with_reject)
 				return -1;