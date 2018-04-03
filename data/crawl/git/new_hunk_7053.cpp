	err |= verify_packfile(p, &w_curs);
	unuse_pack(&w_curs);

	return err;
}
