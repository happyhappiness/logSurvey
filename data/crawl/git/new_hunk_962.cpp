			namlen = slash - dir;
			restlen -= namlen;
			loginfo("userpath <%s>, request <%s>, namlen %d, restlen %d, slash <%s>", user_path, dir, namlen, restlen, slash);
			rlen = snprintf(rpath, sizeof(rpath), "%.*s/%s%.*s",
					namlen, dir, user_path, restlen, slash);
			if (rlen >= sizeof(rpath)) {
				logerror("user-path too large: %s", rpath);
				return NULL;
			}
			dir = rpath;
		}
	}
