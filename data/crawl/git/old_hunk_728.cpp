	if (main_ref_store)
		return main_ref_store;

	return ref_store_init(NULL);
}

struct ref_store *get_ref_store(const char *submodule)
