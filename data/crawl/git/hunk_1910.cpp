 			args->check_self_contained_and_connected &&
 			ret == 0;
 	else
-		die("%s failed", cmd_name);
+		die(_("%s failed"), cmd_name);
 	if (use_sideband && finish_async(&demux))
-		die("error in sideband demultiplexer");
+		die(_("error in sideband demultiplexer"));
 	return 0;
 }
 
