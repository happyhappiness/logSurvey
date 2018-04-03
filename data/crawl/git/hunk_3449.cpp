 			struct ref *ref = NULL;
 			const char *merge_status_marker = "";
 
+			if (rm->status == REF_STATUS_REJECT_SHALLOW) {
+				if (want_status == FETCH_HEAD_MERGE)
+					warning(_("reject %s because shallow roots are not allowed to be updated"),
+						rm->peer_ref ? rm->peer_ref->name : rm->name);
+				continue;
+			}
+
 			commit = lookup_commit_reference_gently(rm->old_sha1, 1);
 			if (!commit)
 				rm->fetch_head_status = FETCH_HEAD_NOT_FOR_MERGE;
