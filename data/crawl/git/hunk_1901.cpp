 				continue;
 			if (starts_with(line, "unshallow "))
 				continue;
-			die("git fetch-pack: expected shallow list");
+			die(_("git fetch-pack: expected shallow list"));
 		}
 	}
 }
