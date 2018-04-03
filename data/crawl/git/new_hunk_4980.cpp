		die("unable to allocate any listen sockets on port %u",
		    listen_port);

	drop_privileges(cred);

	return service_loop(&socklist);
}
