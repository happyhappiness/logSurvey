	case 0:
		if (!memcmp(dst_value, "refs/", 5))
			matched_dst = make_linked_ref(dst_value, dst_tail);
		else
			error("dst refspec %s does not match any "
			      "existing ref on the remote and does "
			      "not start with refs/.", dst_value);
		break;
	default:
		matched_dst = NULL;
