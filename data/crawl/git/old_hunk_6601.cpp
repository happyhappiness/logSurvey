			hunk_no++;
			hunk = RR_CONTEXT;
			if (out) {
				fputs("<<<<<<<\n", out);
				fwrite(one.buf, one.len, 1, out);
				fputs("=======\n", out);
				fwrite(two.buf, two.len, 1, out);
				fputs(">>>>>>>\n", out);
			}
			if (sha1) {
				git_SHA1_Update(&ctx, one.buf ? one.buf : "",
