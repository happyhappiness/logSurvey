 		if (strlen(name) == toplen &&
 		    !memcmp(name, prefix, toplen)) {
 			if (!S_ISDIR(mode))
-				die("entry %s in tree %s is not a tree",
-				    name, sha1_to_hex(hash1));
-			rewrite_here = (unsigned char *) oid->hash;
+				die("entry %s in tree %s is not a tree", name,
+				    oid_to_hex(oid1));
+			rewrite_here = (struct object_id *)oid;
 			break;
 		}
 		update_tree_entry(&desc);
 	}
 	if (!rewrite_here)
-		die("entry %.*s not found in tree %s",
-		    toplen, prefix, sha1_to_hex(hash1));
+		die("entry %.*s not found in tree %s", toplen, prefix,
+		    oid_to_hex(oid1));
 	if (*subpath) {
-		status = splice_tree(rewrite_here, subpath, hash2, subtree);
+		status = splice_tree(rewrite_here, subpath, oid2, &subtree);
 		if (status)
 			return status;
-		rewrite_with = subtree;
+		rewrite_with = &subtree;
+	} else {
+		rewrite_with = oid2;
 	}
-	else
-		rewrite_with = hash2;
-	hashcpy(rewrite_here, rewrite_with);
-	status = write_sha1_file(buf, sz, tree_type, result);
+	oidcpy(rewrite_here, rewrite_with);
+	status = write_sha1_file(buf, sz, tree_type, result->hash);
 	free(buf);
 	return status;
 }
