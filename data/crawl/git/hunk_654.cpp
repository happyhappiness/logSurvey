 			return ACK;
 		}
 	}
+	if (skip_prefix(line, "ERR ", &arg))
+		die(_("remote error: %s"), arg);
 	die(_("git fetch-pack: expected ACK/NAK, got '%s'"), line);
 }
 