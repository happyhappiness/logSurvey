
static void get_info_refs(char *arg)
{
	struct strbuf buf = STRBUF_INIT;

	for_each_ref(show_text_ref, &buf);
	hdr_nocache();
	send_strbuf("text/plain", &buf);
	strbuf_release(&buf);
}

