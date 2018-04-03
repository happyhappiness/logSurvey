		}
		if (!ret)
			die("write error (disk full?)");
		die_errno("write error");
	}
	return nn;
}
