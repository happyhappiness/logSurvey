		     data->alt->base);
}

static int fetch_ref(struct walker *walker, char *ref, unsigned char *sha1)
{
	struct walker_data *data = walker->data;
	return http_fetch_ref(data->alt->base, ref, sha1);
}

static void cleanup(struct walker *walker)
