 		struct remote *remote = remote_get(argv[0]);
 		struct transport *transport = transport_get(remote, argv[0]);
 
+		if (!transport->get_refs_list || !transport->fetch)
+			die("Don't know how to clone %s", transport->url);
+
 		transport_set_option(transport, TRANS_OPT_KEEP, "yes");
 
 		if (option_depth)