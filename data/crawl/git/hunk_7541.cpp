 	return 0;
 }
 
-static int apply_fragments(struct strbuf *buf, struct patch *patch)
+static int apply_fragments(struct image *img, struct patch *patch)
 {
 	struct fragment *frag = patch->fragments;
 	const char *name = patch->old_name ? patch->old_name : patch->new_name;
 	unsigned ws_rule = patch->ws_rule;
 	unsigned inaccurate_eof = patch->inaccurate_eof;
 
 	if (patch->is_binary)
-		return apply_binary(buf, patch);
+		return apply_binary(img, patch);
 
 	while (frag) {
-		if (apply_one_fragment(buf, frag, inaccurate_eof, ws_rule)) {
+		if (apply_one_fragment(img, frag, inaccurate_eof, ws_rule)) {
 			error("patch failed: %s:%ld", name, frag->oldpos);
 			if (!apply_with_reject)
 				return -1;
