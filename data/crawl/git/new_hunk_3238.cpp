		dir = get_ref_dir(entry);
		data.skip = skip;
		sort_ref_dir(dir);
		if (!do_for_each_entry_in_dir(dir, 0, nonmatching_ref_fn, &data)) {
			ret = 1;
			goto cleanup;
		}

		error("'%s' exists; cannot create '%s'",
		      data.conflicting_refname, refname);
		goto cleanup;
	}

	ret = 1;

cleanup:
	strbuf_release(&dirname);
	return ret;
}

struct packed_ref_cache {