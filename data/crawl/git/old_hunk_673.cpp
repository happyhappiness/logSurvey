
	refs = (struct files_ref_store *)ref_store;

	if (!submodule_allowed)
		files_assert_main_repository(refs, caller);

	return refs;
}
