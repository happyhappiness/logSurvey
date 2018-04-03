		}
	}
	remote = remote_get(dest);
	if (!remote->url_nr)
		die("remote %s has no configured URL", dest);
	transport = transport_get(remote, NULL);
