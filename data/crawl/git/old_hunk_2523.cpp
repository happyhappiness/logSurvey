				irrelevant_change = 1;
			continue;
		}
		die("bad tree compare for commit %s", sha1_to_hex(commit->object.sha1));
	}

	/*