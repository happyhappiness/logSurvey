 		if (deco->base && deco->base->type == 1) {
 			mark = ptr_to_mark(deco->decoration);
 			if (fprintf(f, ":%"PRIu32" %s\n", mark,
-				sha1_to_hex(deco->base->sha1)) < 0) {
+				oid_to_hex(&deco->base->oid)) < 0) {
 			    e = 1;
 			    break;
 			}
