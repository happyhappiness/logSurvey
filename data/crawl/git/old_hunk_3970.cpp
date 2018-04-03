			object = parse_object(sha1);
			if (!object)
				die("did not find object for %s", line);
			object->flags |= CLIENT_SHALLOW;
			add_object_array(object, NULL, &shallows);
			continue;