	send_file("application/x-git-packed-objects-toc", name);
}

static int show_text_ref(const char *name, const unsigned char *sha1,
	int flag, void *cb_data)
{
