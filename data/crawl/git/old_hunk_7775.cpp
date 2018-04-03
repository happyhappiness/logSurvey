			print_ref_status('!', "[rejected]", ref, ref->peer_ref,
					"non-fast forward");
			break;
		case REF_STATUS_OK:
			print_ok_ref_status(ref);
			break;
