 		line = packet_read_line(0, &len);
 		if (!line)
 			break;
+
+		if (len == 48 && !prefixcmp(line, "shallow ")) {
+			if (get_sha1_hex(line + 8, old_sha1))
+				die("protocol error: expected shallow sha, got '%s'", line + 8);
+			sha1_array_append(shallow, old_sha1);
+			continue;
+		}
+
 		if (len < 83 ||
 		    line[40] != ' ' ||
 		    line[81] != ' ' ||
