		struct bitmapped_commit *stored = &writer.selected[i];

		int commit_pos =
			sha1_pos(stored->commit->object.sha1, index, index_nr, sha1_access);

		if (commit_pos < 0)
			die("BUG: trying to write commit not in index");
