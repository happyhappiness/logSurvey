 		if (len > 4 && !prefixcmp(buffer, "ERR "))
 			die("remote error: %s", buffer + 4);
 
+		if (len == 48 && !prefixcmp(buffer, "shallow ")) {
+			if (get_sha1_hex(buffer + 8, old_sha1))
+				die("protocol error: expected shallow sha-1, got '%s'", buffer + 8);
+			if (!shallow_points)
+				die("repository on the other end cannot be shallow");
+			sha1_array_append(shallow_points, old_sha1);
+			continue;
+		}
+
 		if (len < 42 || get_sha1_hex(buffer, old_sha1) || buffer[40] != ' ')
 			die("protocol error: expected sha/ref, got '%s'", buffer);
 		name = buffer + 41;
