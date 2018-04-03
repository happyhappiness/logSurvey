 
 	if (remote_name) {
 		remote = remote_get(remote_name);
-		if (!remote_has_uri(remote, dest)) {
+		if (!remote_has_url(remote, dest)) {
 			die("Destination %s is not a uri for %s",
 			    dest, remote_name);
 		}