			if (get_oid_hex(line + 8, &oid))
				die("protocol error: expected shallow sha, got '%s'",
				    line + 8);
			oid_array_append(shallow, &oid);
			continue;
		}

