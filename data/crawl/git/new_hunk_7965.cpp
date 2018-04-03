		 * way to delete 'other' ref at the remote end.
		 */
		matched_src = try_explicit_object_name(rs->src);
		if (!matched_src)
			error("src refspec %s does not match any.", rs->src);
		break;
	default:
		matched_src = NULL;
		error("src refspec %s matches more than one.", rs->src);
		break;
	}
