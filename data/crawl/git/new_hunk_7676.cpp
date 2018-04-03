
			free(result_buf.ptr);
			result.clean = (merge_status == 0);
		} else if (S_ISGITLINK(a->mode)) {
			result.clean = 0;
			hashcpy(result.sha, a->sha1);
		} else if (S_ISLNK(a->mode)) {
			hashcpy(result.sha, a->sha1);

			if (!sha_eq(a->sha1, b->sha1))
				result.clean = 0;
		} else {
			die("unsupported object type in the tree");
		}
	}
