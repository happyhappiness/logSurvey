 		transport_set_option(transport, TRANS_OPT_THIN, "yes");
 
 	if (verbosity > 0)
-		fprintf(stderr, "Pushing to %s\n", transport->url);
+		fprintf(stderr, _("Pushing to %s\n"), transport->url);
 	err = transport_push(transport, refspec_nr, refspec, flags,
 			     &nonfastforward);
 	if (err != 0)
-		error("failed to push some refs to '%s'", transport->url);
+		error(_("failed to push some refs to '%s'"), transport->url);
 
 	err |= transport_disconnect(transport);
 
