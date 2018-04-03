				die("protocol error: expected shallow sha-1, got '%s'", arg);
			if (!shallow_points)
				die("repository on the other end cannot be shallow");
			oid_array_append(shallow_points, &old_oid);
			continue;
		}

