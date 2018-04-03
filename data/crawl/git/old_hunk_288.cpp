	int argcount;

	if (submodule) {
		refs = get_submodule_ref_store(submodule);
	} else
		refs = get_main_ref_store();
