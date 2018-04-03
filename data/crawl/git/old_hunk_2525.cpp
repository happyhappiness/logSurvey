			continue;
		case commit_error:
			die("Failed to simplify parents of commit %s",
			    sha1_to_hex(commit->object.sha1));
		default:
			if (revs->track_linear)
				track_linear(revs, commit);
