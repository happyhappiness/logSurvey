 			return ACK;
 		}
 	}
-	die(_("git fetch_pack: expected ACK/NAK, got '%s'"), line);
+	die(_("git fetch-pack: expected ACK/NAK, got '%s'"), line);
 }
 
 static void send_request(struct fetch_pack_args *args,