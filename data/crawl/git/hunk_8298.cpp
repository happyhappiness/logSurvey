 	return ref;
 }
 
-static int match_explicit_refs(struct ref *src, struct ref *dst,
-			       struct ref ***dst_tail, struct refspec *rs,
-			       int rs_nr)
+static int match_explicit(struct ref *src, struct ref *dst,
+			  struct ref ***dst_tail,
+			  struct refspec *rs,
+			  int errs)
 {
-	int i, errs;
-	for (i = errs = 0; i < rs_nr; i++) {
-		struct ref *matched_src, *matched_dst;
+	struct ref *matched_src, *matched_dst;
 
-		const char *dst_value = rs[i].dst;
+	const char *dst_value = rs->dst;
 
-		if (rs[i].pattern)
-			continue;
+	if (rs->pattern)
+		return errs;
 
-		if (dst_value == NULL)
-			dst_value = rs[i].src;
+	if (dst_value == NULL)
+		dst_value = rs->src;
 
-		matched_src = matched_dst = NULL;
-		switch (count_refspec_match(rs[i].src, src, &matched_src)) {
-		case 1:
-			break;
-		case 0:
-			/* The source could be in the get_sha1() format
-			 * not a reference name.  :refs/other is a
-			 * way to delete 'other' ref at the remote end.
-			 */
-			matched_src = try_explicit_object_name(rs[i].src);
-			if (matched_src)
-				break;
-			errs = 1;
-			error("src refspec %s does not match any.",
-			      rs[i].src);
-			break;
-		default:
-			errs = 1;
-			error("src refspec %s matches more than one.",
-			      rs[i].src);
-			break;
-		}
-		switch (count_refspec_match(dst_value, dst, &matched_dst)) {
-		case 1:
-			break;
-		case 0:
-			if (!memcmp(dst_value, "refs/", 5)) {
-				int len = strlen(dst_value) + 1;
-				matched_dst = xcalloc(1, sizeof(*dst) + len);
-				memcpy(matched_dst->name, dst_value, len);
-				link_dst_tail(matched_dst, dst_tail);
-			}
-			else if (!strcmp(rs[i].src, dst_value) &&
-				 matched_src) {
-				/* pushing "master:master" when
-				 * remote does not have master yet.
-				 */
-				int len = strlen(matched_src->name) + 1;
-				matched_dst = xcalloc(1, sizeof(*dst) + len);
-				memcpy(matched_dst->name, matched_src->name,
-				       len);
-				link_dst_tail(matched_dst, dst_tail);
-			}
-			else {
-				errs = 1;
-				error("dst refspec %s does not match any "
-				      "existing ref on the remote and does "
-				      "not start with refs/.", dst_value);
-			}
-			break;
-		default:
-			errs = 1;
-			error("dst refspec %s matches more than one.",
-			      dst_value);
+	matched_src = matched_dst = NULL;
+	switch (count_refspec_match(rs->src, src, &matched_src)) {
+	case 1:
+		break;
+	case 0:
+		/* The source could be in the get_sha1() format
+		 * not a reference name.  :refs/other is a
+		 * way to delete 'other' ref at the remote end.
+		 */
+		matched_src = try_explicit_object_name(rs->src);
+		if (matched_src)
 			break;
+		errs = 1;
+		error("src refspec %s does not match any.",
+		      rs->src);
+		break;
+	default:
+		errs = 1;
+		error("src refspec %s matches more than one.",
+		      rs->src);
+		break;
+	}
+	switch (count_refspec_match(dst_value, dst, &matched_dst)) {
+	case 1:
+		break;
+	case 0:
+		if (!memcmp(dst_value, "refs/", 5)) {
+			int len = strlen(dst_value) + 1;
+			matched_dst = xcalloc(1, sizeof(*dst) + len);
+			memcpy(matched_dst->name, dst_value, len);
+			link_dst_tail(matched_dst, dst_tail);
 		}
-		if (errs)
-			continue;
-		if (matched_dst->peer_ref) {
-			errs = 1;
-			error("dst ref %s receives from more than one src.",
-			      matched_dst->name);
+		else if (!strcmp(rs->src, dst_value) &&
+			 matched_src) {
+			/* pushing "master:master" when
+			 * remote does not have master yet.
+			 */
+			int len = strlen(matched_src->name) + 1;
+			matched_dst = xcalloc(1, sizeof(*dst) + len);
+			memcpy(matched_dst->name, matched_src->name,
+			       len);
+			link_dst_tail(matched_dst, dst_tail);
 		}
 		else {
-			matched_dst->peer_ref = matched_src;
-			matched_dst->force = rs[i].force;
+			errs = 1;
+			error("dst refspec %s does not match any "
+			      "existing ref on the remote and does "
+			      "not start with refs/.", dst_value);
 		}
+		break;
+	default:
+		errs = 1;
+		error("dst refspec %s matches more than one.",
+		      dst_value);
+		break;
+	}
+	if (errs)
+		return errs;
+	if (matched_dst->peer_ref) {
+		errs = 1;
+		error("dst ref %s receives from more than one src.",
+		      matched_dst->name);
 	}
+	else {
+		matched_dst->peer_ref = matched_src;
+		matched_dst->force = rs->force;
+	}
+	return errs;
+}
+
+static int match_explicit_refs(struct ref *src, struct ref *dst,
+			       struct ref ***dst_tail, struct refspec *rs,
+			       int rs_nr)
+{
+	int i, errs;
+	for (i = errs = 0; i < rs_nr; i++)
+		errs |= match_explicit(src, dst, dst_tail, &rs[i], errs);
 	return -errs;
 }
 
