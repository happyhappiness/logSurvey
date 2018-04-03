 {
 	xpparam_t xpp;
 
+	if (buffer_is_binary(orig->ptr, orig->size) ||
+			buffer_is_binary(src1->ptr, src1->size) ||
+			buffer_is_binary(src2->ptr, src2->size))
+		return error("Cannot merge binary files: %s vs. %s\n",
+			name1, name2);
+
 	memset(&xpp, 0, sizeof(xpp));
 	return xdl_merge(orig,
 			 src1, name1,
