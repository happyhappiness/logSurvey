 					"non-fast forward");
 			break;
 		case REF_STATUS_REMOTE_REJECT:
-			if (ref->deletion)
-				print_ref_status('!', "[remote rejected]", ref, NULL, ref->error);
-			else
-				print_ref_status('!', "[remote rejected]", ref, ref->peer_ref, ref->error);
+			print_ref_status('!', "[remote rejected]", ref,
+					ref->deletion ? NULL : ref->peer_ref,
+					ref->remote_status);
+			break;
+		case REF_STATUS_EXPECTING_REPORT:
+			print_ref_status('!', "[remote failure]", ref,
+					ref->deletion ? NULL : ref->peer_ref,
+					"remote failed to report status");
 			break;
 		case REF_STATUS_OK:
 			print_ok_ref_status(ref);
