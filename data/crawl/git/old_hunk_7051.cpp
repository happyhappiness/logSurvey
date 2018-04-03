		return error("packfile %s not found.", arg);

	install_packed_git(pack);
	err = verify_pack(pack, verbose);

	return err;
}
