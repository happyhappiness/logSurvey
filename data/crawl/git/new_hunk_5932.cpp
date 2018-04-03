			if (sz == 0)
				break;
			if (sz < 0)
				die_errno("test-sha1");
			this_sz += sz;
			cp += sz;
			room -= sz;
