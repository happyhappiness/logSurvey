 		else
 			new_sha1 = ref->peer_ref->new_sha1;
 
-		if (!shown_dest) {
-			fprintf(stderr, "To %s\n", dest);
-			shown_dest = 1;
-		}
-
-		will_delete_ref = is_null_sha1(new_sha1);
 
-		pretty_ref = prettify_ref(ref->name);
-		if (!will_delete_ref)
-			pretty_peer = prettify_ref(ref->peer_ref->name);
-
-		if (will_delete_ref && !allow_deleting_refs) {
-			fprintf(stderr, " ! %-*s %s (remote does not support deleting refs)\n",
-					SUMMARY_WIDTH, "[rejected]", pretty_ref);
-			ret = -2;
+		ref->deletion = is_null_sha1(new_sha1);
+		if (ref->deletion && !allow_deleting_refs) {
+			ref->status = REF_STATUS_REJECT_NODELETE;
 			continue;
 		}
-		if (!will_delete_ref &&
+		if (!ref->deletion &&
 		    !hashcmp(ref->old_sha1, new_sha1)) {
-			if (args.verbose)
-				fprintf(stderr, " = %-*s %s -> %s\n",
-					SUMMARY_WIDTH, "[up to date]",
-					pretty_peer, pretty_ref);
+			ref->status = REF_STATUS_UPTODATE;
 			continue;
 		}
 
