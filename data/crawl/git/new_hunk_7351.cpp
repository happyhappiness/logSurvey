				if (!lookup_object(sha1))
					die("object not found: %s", line);
				/* make sure that it is parsed as shallow */
				if (!parse_object(sha1))
					die("error in object: %s", line);
				if (unregister_shallow(sha1))
					die("no shallow found: %s", line);
				continue;