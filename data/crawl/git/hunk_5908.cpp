 		} else
 			output_fd = open(pack_name, O_CREAT|O_EXCL|O_RDWR, 0600);
 		if (output_fd < 0)
-			die("unable to create %s: %s", pack_name, strerror(errno));
+			die_errno("unable to create '%s'", pack_name);
 		pack_fd = output_fd;
 	} else {
 		input_fd = open(pack_name, O_RDONLY);
 		if (input_fd < 0)
-			die("cannot open packfile '%s': %s",
-			    pack_name, strerror(errno));
+			die_errno("cannot open packfile '%s'", pack_name);
 		output_fd = -1;
 		pack_fd = input_fd;
 	}
