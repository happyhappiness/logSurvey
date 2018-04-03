		die("unable to allocate any listen sockets on port %u",
		    listen_port);

	if (pass && gid &&
	    (initgroups(pass->pw_name, gid) || setgid (gid) ||
	     setuid(pass->pw_uid)))
		die("cannot drop privileges");

	return service_loop(&socklist);
}
