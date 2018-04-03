 
 		} else {
 			const char *dst_side = pat->dst ? pat->dst : pat->src;
-			dst_name = xmalloc(strlen(dst_side) +
-					   strlen(src->name) -
-					   strlen(pat->src) + 2);
-			strcpy(dst_name, dst_side);
-			strcat(dst_name, src->name + strlen(pat->src));
+			if (!match_name_with_pattern(pat->src, src->name,
+						     dst_side, &dst_name))
+				die("Didn't think it matches any more");
 		}
 		dst_peer = find_ref_by_name(dst, dst_name);
 		if (dst_peer) {
