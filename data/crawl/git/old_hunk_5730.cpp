		return error("packfile %s not found.", arg);

	install_packed_git(pack);
	err = verify_pack(pack);

	if (verbose) {
		if (err)
			printf("%s: bad\n", pack->pack_name);
		else {
			show_pack_info(pack);
			printf("%s: ok\n", pack->pack_name);
		}
	}

	return err;
}

static const char * const verify_pack_usage[] = {
	"git verify-pack [-v|--verbose] <pack>...",
	NULL
};

int cmd_verify_pack(int argc, const char **argv, const char *prefix)
{
	int err = 0;
	int verbose = 0;
	int i;
	const struct option verify_pack_options[] = {
		OPT__VERBOSE(&verbose),
		OPT_END()
	};

