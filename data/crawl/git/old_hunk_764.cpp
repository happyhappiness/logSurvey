			if (item->command == TODO_EDIT) {
				struct commit *commit = item->commit;
				if (!res)
					warning(_("stopped at %s... %.*s"),
						short_commit_name(commit),
						item->arg_len, item->arg);
				return error_with_patch(commit,