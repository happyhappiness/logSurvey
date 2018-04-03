 		 */
 		matched_src = try_explicit_object_name(rs->src);
 		if (!matched_src)
-			error("src refspec %s does not match any.", rs->src);
+			return error("src refspec %s does not match any.", rs->src);
 		break;
 	default:
-		matched_src = NULL;
-		error("src refspec %s matches more than one.", rs->src);
-		break;
+		return error("src refspec %s matches more than one.", rs->src);
 	}
 
-	if (!matched_src)
-		errs = 1;
-
 	if (!dst_value) {
 		unsigned char sha1[20];
 		int flag;
 
-		if (!matched_src)
-			return errs;
 		dst_value = resolve_ref(matched_src->name, sha1, 1, &flag);
 		if (!dst_value ||
 		    ((flag & REF_ISSYMREF) &&
