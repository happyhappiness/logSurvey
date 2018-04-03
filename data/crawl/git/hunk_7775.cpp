 			print_ref_status('!', "[rejected]", ref, ref->peer_ref,
 					"non-fast forward");
 			break;
+		case REF_STATUS_REMOTE_REJECT:
+			if (ref->deletion)
+				print_ref_status('!', "[remote rejected]", ref, NULL, ref->error);
+			else
+				print_ref_status('!', "[remote rejected]", ref, ref->peer_ref, ref->error);
+			break;
 		case REF_STATUS_OK:
 			print_ok_ref_status(ref);
 			break;
