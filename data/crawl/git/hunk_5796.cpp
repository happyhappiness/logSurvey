 		}
 		strcat(quickref, status_abbrev(ref->new_sha1));
 
-		print_ref_status(type, quickref, ref, ref->peer_ref, msg);
+		print_ref_status(type, quickref, ref, ref->peer_ref, msg, porcelain);
 	}
 }
 
-static int print_one_push_status(struct ref *ref, const char *dest, int count)
+static int print_one_push_status(struct ref *ref, const char *dest, int count, int porcelain)
 {
 	if (!count)
 		fprintf(stderr, "To %s\n", dest);
 
 	switch(ref->status) {
 	case REF_STATUS_NONE:
-		print_ref_status('X', "[no match]", ref, NULL, NULL);
+		print_ref_status('X', "[no match]", ref, NULL, NULL, porcelain);
 		break;
 	case REF_STATUS_REJECT_NODELETE:
 		print_ref_status('!', "[rejected]", ref, NULL,
-				"remote does not support deleting refs");
+						 "remote does not support deleting refs", porcelain);
 		break;
 	case REF_STATUS_UPTODATE:
 		print_ref_status('=', "[up to date]", ref,
-				ref->peer_ref, NULL);
+						 ref->peer_ref, NULL, porcelain);
 		break;
 	case REF_STATUS_REJECT_NONFASTFORWARD:
 		print_ref_status('!', "[rejected]", ref, ref->peer_ref,
-				"non-fast forward");
+						 "non-fast forward", porcelain);
 		break;
 	case REF_STATUS_REMOTE_REJECT:
 		print_ref_status('!', "[remote rejected]", ref,
-				ref->deletion ? NULL : ref->peer_ref,
-				ref->remote_status);
+						 ref->deletion ? NULL : ref->peer_ref,
+						 ref->remote_status, porcelain);
 		break;
 	case REF_STATUS_EXPECTING_REPORT:
 		print_ref_status('!', "[remote failure]", ref,
-				ref->deletion ? NULL : ref->peer_ref,
-				"remote failed to report status");
+						 ref->deletion ? NULL : ref->peer_ref,
+						 "remote failed to report status", porcelain);
 		break;
 	case REF_STATUS_OK:
-		print_ok_ref_status(ref);
+		print_ok_ref_status(ref, porcelain);
 		break;
 	}
 
 	return 1;
 }
 
-static void print_push_status(const char *dest, struct ref *refs, int verbose)
+static void print_push_status(const char *dest, struct ref *refs,
+							  int verbose, int porcelain)
 {
 	struct ref *ref;
 	int n = 0;
 
 	if (verbose) {
 		for (ref = refs; ref; ref = ref->next)
 			if (ref->status == REF_STATUS_UPTODATE)
-				n += print_one_push_status(ref, dest, n);
+				n += print_one_push_status(ref, dest, n, porcelain);
 	}
 
 	for (ref = refs; ref; ref = ref->next)
 		if (ref->status == REF_STATUS_OK)
-			n += print_one_push_status(ref, dest, n);
+			n += print_one_push_status(ref, dest, n, porcelain);
 
 	for (ref = refs; ref; ref = ref->next) {
 		if (ref->status != REF_STATUS_NONE &&
 		    ref->status != REF_STATUS_UPTODATE &&
 		    ref->status != REF_STATUS_OK)
-			n += print_one_push_status(ref, dest, n);
+			n += print_one_push_status(ref, dest, n, porcelain);
 	}
 }
 
