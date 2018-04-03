		ip.git_cmd = 1;
		if (start_command(&ip))
			return "index-pack fork failed";
		pack_lockfile = index_pack_lockfile(ip.out);
		status = finish_command(&ip);
		if (!status) {
			reprepare_packed_git();