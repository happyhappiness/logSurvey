{
	int msg_type;

	msg_type = msg_id_info[msg_id].msg_type;
	if (options->strict && msg_type == FSCK_WARN)
		msg_type = FSCK_ERROR;

	return msg_type;
}

__attribute__((format (printf, 4, 5)))
static int report(struct fsck_options *options, struct object *object,
	enum fsck_msg_id id, const char *fmt, ...)
