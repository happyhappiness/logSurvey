	}
}

struct write_shallow_data {
	struct strbuf *out;
	int use_pack_protocol;
	int count;
};

static int write_one_shallow(const struct commit_graft *graft, void *cb_data)
{
	struct write_shallow_data *data = cb_data;
	const char *hex = sha1_to_hex(graft->sha1);
	data->count++;
	if (data->use_pack_protocol)
		packet_buf_write(data->out, "shallow %s", hex);
	else {
		strbuf_addstr(data->out, hex);
		strbuf_addch(data->out, '\n');
	}
	return 0;
}

static int write_shallow_commits(struct strbuf *out, int use_pack_protocol)
{
	struct write_shallow_data data;
	data.out = out;
	data.use_pack_protocol = use_pack_protocol;
	data.count = 0;
	for_each_commit_graft(write_one_shallow, &data);
	return data.count;
}

static enum ack_type get_ack(int fd, unsigned char *result_sha1)
{
	int len;
