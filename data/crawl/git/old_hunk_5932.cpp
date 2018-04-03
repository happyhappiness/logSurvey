			if (sz == 0)
				break;
			if (sz < 0)
				die("test-sha1: %s", strerror(errno));
			this_sz += sz;
			cp += sz;
			room -= sz;
