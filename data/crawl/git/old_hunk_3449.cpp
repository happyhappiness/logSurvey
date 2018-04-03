			struct ref *ref = NULL;
			const char *merge_status_marker = "";

			commit = lookup_commit_reference_gently(rm->old_sha1, 1);
			if (!commit)
				rm->fetch_head_status = FETCH_HEAD_NOT_FOR_MERGE;
