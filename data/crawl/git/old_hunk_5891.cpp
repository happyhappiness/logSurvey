		}
		if (!ret)
			die("sha1 file '%s' write error. Out of diskspace", f->name);
		die("sha1 file '%s' write error (%s)", f->name, strerror(errno));
	}
}
