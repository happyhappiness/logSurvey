			if (revs->max_age != -1 &&
			    (commit->date < revs->max_age))
				continue;
			if (add_parents_to_list(revs, commit, &revs->commits, NULL) < 0)
				die("Failed to traverse parents of commit %s",
				    sha1_to_hex(commit->object.sha1));
		}

		switch (simplify_commit(revs, commit)) {
