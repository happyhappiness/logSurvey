			email++;
			timestamp = strchr(email, '>');
			if (!timestamp)
				die ("Could not extract author email from %s",
					sha1_to_hex(commit->object.sha1));
			*timestamp = '\0';
			for (timestamp++; *timestamp && isspace(*timestamp);