			die("Failed to simplify parents of commit %s",
			    sha1_to_hex(commit->object.sha1));
		default:
			return commit;
		}
	} while (revs->commits);
