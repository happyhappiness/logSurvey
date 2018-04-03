	size_t state_len = 0;

	if (args->stateless_rpc && multi_ack == 1)
		die(_("--stateless-rpc requires multi_ack_detailed"));
	if (marked)
		for_each_ref(clear_marks, NULL);
	marked = 1;
