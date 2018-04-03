		die("%s is not a valid object", sha1_to_hex(sha1));
	if (type != expect)
		die("%s is not a valid '%s' object", sha1_to_hex(sha1),
		    type_name(expect));
}

int for_each_file_in_obj_subdir(unsigned int subdir_nr,
