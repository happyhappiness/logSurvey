		die("Unknown fsck message type: '%s'", str);
}

void fsck_set_msg_type(struct fsck_options *options,
		const char *msg_id, const char *msg_type)
{
