			f = sha1fd(1, "<stdout>");
		} else {
			int fd = open_object_dir_tmp("tmp_pack_XXXXXX");
			pack_tmp_name = xstrdup(tmpname);
			f = sha1fd(fd, pack_tmp_name);
		}
