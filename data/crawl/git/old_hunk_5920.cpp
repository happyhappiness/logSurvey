		}
		if (!ret)
			die("write error (disk full?)");
		die("write error (%s)", strerror(errno));
	}
	return nn;
}
