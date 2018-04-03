 	request->state = RUN_FETCH_LOOSE;
 	if (!start_active_slot(slot)) {
 		fprintf(stderr, "Unable to start GET request\n");
-		remote->can_update_info_refs = 0;
+		repo->can_update_info_refs = 0;
 		release_request(request);
 	}
 }
