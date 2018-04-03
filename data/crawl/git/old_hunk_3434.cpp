		die("shallow file was changed during fetch");
}

struct write_shallow_data {
	struct strbuf *out;
	int use_pack_protocol;
	int count;
};

static int write_one_shallow(const struct commit_graft *graft, void *cb_data)
