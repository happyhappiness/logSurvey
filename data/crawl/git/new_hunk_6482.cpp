				list = get_ref_dir(ref, list);
				continue;
			}
			if (!resolve_ref(ref, sha1, 1, &flag))
				hashclr(sha1);
			list = add_ref(ref, sha1, flag, list, NULL);
		}
		free(ref);
