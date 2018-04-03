	err |= verify_packfile(p, &w_curs);
	unuse_pack(&w_curs);

	if (verbose) {
		if (err)
			printf("%s: bad\n", p->pack_name);
		else {
			show_pack_info(p);
			printf("%s: ok\n", p->pack_name);
		}
	}

	return err;
}
