			 */
			sprintf(temp->mode, "%06o", one->mode);
		}
		return temp;
	}
	else {
		if (diff_populate_filespec(one, 0))
			die("cannot read data blob for %s", one->path);
		prep_temp_blob(temp, one->data, one->size,
			       one->sha1, one->mode);
	}
	return temp;
}

/* An external diff command takes:
