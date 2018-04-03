 			die("remote-helpers do not support ref deletion");
 		}
 
-		if (ref->peer_ref)
+		if (ref->peer_ref) {
+			if (strcmp(ref->peer_ref->name, ref->name))
+				die("remote-helpers do not support old:new syntax");
 			string_list_append(&revlist_args, ref->peer_ref->name);
-
+		}
 	}
 
 	if (get_exporter(transport, &exporter, &revlist_args))