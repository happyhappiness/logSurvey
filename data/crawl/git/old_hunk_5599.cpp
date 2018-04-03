		free(data->helper);
		data->helper = NULL;
	}
	return 0;
}

static int fetch_with_fetch(struct transport *transport,
			    int nr_heads, const struct ref **to_fetch)
{
	struct helper_data *data = transport->data;
	int i;
	struct strbuf buf = STRBUF_INIT;

	for (i = 0; i < nr_heads; i++) {
		const struct ref *posn = to_fetch[i];
		if (posn->status & REF_STATUS_UPTODATE)
