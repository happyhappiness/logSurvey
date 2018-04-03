	return ret;
}

static int send_pack(int in, int out, struct remote *remote, int nr_refspec, char **refspec)
{
	struct ref *ref;
