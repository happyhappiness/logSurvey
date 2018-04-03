			result.clean = (merge_status == 0);
		} else if (S_ISGITLINK(a->mode)) {
			result.clean = merge_submodule(result.sha,
						       one->path, one->sha1,
						       a->sha1, b->sha1,
						       !o->call_depth);
		} else if (S_ISLNK(a->mode)) {
			hashcpy(result.sha, a->sha1);

			if (!sha_eq(a->sha1, b->sha1))
				result.clean = 0;
		} else {
			die(_("unsupported object type in the tree"));
