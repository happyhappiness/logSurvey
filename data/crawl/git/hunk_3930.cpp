 		print_ref_status('!', "[rejected]", ref, ref->peer_ref,
 						 "already exists", porcelain);
 		break;
+	case REF_STATUS_REJECT_FETCH_FIRST:
+		print_ref_status('!', "[rejected]", ref, ref->peer_ref,
+						 "fetch first", porcelain);
+		break;
+	case REF_STATUS_REJECT_NEEDS_FORCE:
+		print_ref_status('!', "[rejected]", ref, ref->peer_ref,
+						 "needs force", porcelain);
+		break;
 	case REF_STATUS_REMOTE_REJECT:
 		print_ref_status('!', "[remote rejected]", ref,
 						 ref->deletion ? NULL : ref->peer_ref,
