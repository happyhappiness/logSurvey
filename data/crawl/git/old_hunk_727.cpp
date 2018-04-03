		die("BUG: reference backend %s is unknown", be_name);

	refs = be->init(submodule);
	register_ref_store(refs, submodule);
	return refs;
}

