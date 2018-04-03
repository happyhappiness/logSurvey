 		} elsif ($line eq "\n") {
 			return @refs;
 		} else {
-			die("Invalid command in a '$cmd' batch: ". $_);
+			die("Invalid command in a '$cmd' batch: $_\n");
 		}
 	}
 	return;
