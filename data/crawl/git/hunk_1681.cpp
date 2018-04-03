 		struct check_connected_options opt = CHECK_CONNECTED_INIT;
 
 		opt.transport = transport;
+		opt.progress = transport->progress;
 
-		if (transport->progress)
-			fprintf(stderr, _("Checking connectivity... "));
 		if (check_connected(iterate_ref_map, &rm, &opt))
 			die(_("remote did not send all necessary objects"));
-		if (transport->progress)
-			fprintf(stderr, _("done.\n"));
 	}
 
 	if (refs) {