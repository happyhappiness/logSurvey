		if (!get_tree_entry(tree_sha1, fullname,
				    sha1, &mode)) {
			die("Path '%s' exists, but not '%s'.\n"
			    "Did you mean '%s:%s' aka '%s:./%s'?",
			    fullname,
			    filename,
			    object_name,
			    fullname,
			    object_name,
			    filename);
		}
		die("Path '%s' does not exist in '%s'",
		    filename, object_name);
	}
}

