 		die("internal error: dst already matched.");
 
 	src = rename_src[src_index].one;
+	src->rename_used++;
 	src->count++;
 
 	dst = rename_dst[dst_index].two;
