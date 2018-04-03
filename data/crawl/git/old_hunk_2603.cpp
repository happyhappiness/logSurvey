				/* fall-through */
			case FETCH_HEAD_MERGE:
				fprintf(fp, "%s\t%s\t%s",
					sha1_to_hex(rm->old_sha1),
					merge_status_marker,
					note.buf);
				for (i = 0; i < url_len; ++i)
