	return !!err;
}

static const struct transport_ops curl_transport = {
	/* set_option */	NULL,
	/* push */		curl_transport_push
};

static const struct transport_ops bundle_transport = {
};

struct git_transport_data {
	unsigned thin : 1;

	const char *receivepack;
};

static int set_git_option(struct transport *connection,
			  const char *name, const char *value)
{
	struct git_transport_data *data = connection->data;
	if (!strcmp(name, TRANS_OPT_RECEIVEPACK)) {
		data->receivepack = value;
		return 0;
	} else if (!strcmp(name, TRANS_OPT_THIN)) {
		data->thin = !!value;
		return 0;
	}
	return 1;
}

static int git_transport_push(struct transport *transport, int refspec_nr, const char **refspec, int flags) {
	struct git_transport_data *data = transport->data;
	const char **argv;
