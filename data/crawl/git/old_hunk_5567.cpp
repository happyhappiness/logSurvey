	return 0;
}

static void upload_pack(void)
{
	reset_timeout();
	head_ref(send_ref, NULL);
	for_each_ref(send_ref, NULL);
	packet_flush(1);
	receive_needs();
	if (want_obj.nr) {
		get_common_commits();
