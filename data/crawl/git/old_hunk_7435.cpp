	info->message_id = strbuf_detach(&buf, NULL);
}

static const char *clean_message_id(const char *msg_id)
{
	char ch;
