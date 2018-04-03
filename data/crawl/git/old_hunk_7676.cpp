
			free(result_buf.ptr);
			result.clean = (merge_status == 0);
		} else {
			if (!(S_ISLNK(a->mode) || S_ISLNK(b->mode)))
				die("cannot merge modes?");

			hashcpy(result.sha, a->sha1);

			if (!sha_eq(a->sha1, b->sha1))
				result.clean = 0;
		}
	}
