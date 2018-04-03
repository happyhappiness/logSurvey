			c = c->parents->item;
		}

		if (hashcmp(c->object.sha1, sb.final->object.sha1))
			die("--reverse --first-parent together require range along first-parent chain");
	}

	if (is_null_sha1(sb.final->object.sha1)) {
		o = sb.final->util;
		sb.final_buf = xmemdupz(o->file.ptr, o->file.size);
		sb.final_buf_size = o->file.size;
