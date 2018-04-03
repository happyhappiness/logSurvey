			return -1;
		}

		utb.actime = sb.st_atime;
		utb.modtime = set_eq ? set_time : sb.st_mtime + set_time;
