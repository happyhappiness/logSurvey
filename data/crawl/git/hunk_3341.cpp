 	return strbuf_detach(&buf, NULL);
 }
 
+static int match_explicit_lhs(struct ref *src,
+			      struct refspec *rs,
+			      struct ref **match,
+			      int *allocated_match)
+{
+	switch (count_refspec_match(rs->src, src, match)) {
+	case 1:
+		*allocated_match = 0;
+		return 0;
+	case 0:
+		/* The source could be in the get_sha1() format
+		 * not a reference name.  :refs/other is a
+		 * way to delete 'other' ref at the remote end.
+		 */
+		*match = try_explicit_object_name(rs->src);
+		if (!*match)
+			return error("src refspec %s does not match any.", rs->src);
+		*allocated_match = 1;
+		return 0;
+	default:
+		return error("src refspec %s matches more than one.", rs->src);
+	}
+}
+
 static int match_explicit(struct ref *src, struct ref *dst,
 			  struct ref ***dst_tail,
 			  struct refspec *rs)
 {
 	struct ref *matched_src, *matched_dst;
-	int copy_src;
+	int allocated_src;
 
 	const char *dst_value = rs->dst;
 	char *dst_guess;
