			pattern[j - i] = p;
		}
	}
	remote = remote_get(dest);
	if (!remote->url_nr)
		die("remote %s has no configured URL", dest);
	transport = transport_get(remote, remote->url[0]);
	if (uploadpack != NULL)
		transport_set_option(transport, TRANS_OPT_UPLOADPACK, uploadpack);

