			result = xmalloc(len + 1);
			while (sz < len) {
				ssize_t done = xread(fd, result+sz, len-sz);
				if (done == 0)
					break;
				if (done < 0)
					die("read error '%s'", elem->path);
				sz += done;
			}