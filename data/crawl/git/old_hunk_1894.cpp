
	if ((args->depth > 0 || is_repository_shallow()) && !server_supports("shallow"))
		die(_("Server does not support shallow clients"));
	if (args->depth > 0)
		args->deepen = 1;
	if (server_supports("multi_ack_detailed")) {
		print_verbose(args, _("Server supports multi_ack_detailed"));
