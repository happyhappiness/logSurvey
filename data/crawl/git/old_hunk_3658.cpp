					strbuf_addf(&note, "%s ", kind);
				strbuf_addf(&note, "'%s' of ", what);
			}
			fprintf(fp, "%s\t%s\t%s",
				sha1_to_hex(rm->old_sha1),
				rm->merge ? "" : "not-for-merge",
				note.buf);
			for (i = 0; i < url_len; ++i)
				if ('\n' == url[i])
					fputs("\\n", fp);
				else
					fputc(url[i], fp);
			fputc('\n', fp);

			strbuf_reset(&note);
			if (ref) {
