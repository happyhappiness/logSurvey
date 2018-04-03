				list = get_ref_dir(ref, list);
				continue;
			}
			if (!resolve_ref(ref, sha1, 1, &flag)) {
				error("%s points nowhere!", ref);
				continue;
			}
			list = add_ref(ref, sha1, flag, list, NULL);
		}
		free(ref);
