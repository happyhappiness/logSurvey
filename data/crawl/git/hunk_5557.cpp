 	memset(&po, 0, sizeof(po));
 	po.argv = argv;
 	po.in = -1;
-	po.out = fd;
+	po.out = args->stateless_rpc ? -1 : fd;
 	po.git_cmd = 1;
 	if (start_command(&po))
 		die_errno("git pack-objects failed");
