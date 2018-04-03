		if (diff_populate_filespec(one, 0))
			die("cannot read data blob for %s", one->path);
		prep_temp_blob(name, temp, one->data, one->size,
			       &one->oid, one->mode);
	}
	return temp;
}
