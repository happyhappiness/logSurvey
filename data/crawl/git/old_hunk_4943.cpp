				die("You have not concluded your previous "
				    "notes merge (%s exists).\nPlease, use "
				    "'git notes merge --commit' or 'git notes "
				    "merge --reset' to commit/abort the "
				    "previous merge before you start a new "
				    "notes merge.", git_path("NOTES_MERGE_*"));
			else
