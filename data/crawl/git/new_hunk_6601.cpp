			hunk_no++;
			hunk = RR_CONTEXT;
			if (out) {
				ferr_puts("<<<<<<<\n", out, &wrerror);
				ferr_write(one.buf, one.len, out, &wrerror);
				ferr_puts("=======\n", out, &wrerror);
				ferr_write(two.buf, two.len, out, &wrerror);
				ferr_puts(">>>>>>>\n", out, &wrerror);
			}
			if (sha1) {
				git_SHA1_Update(&ctx, one.buf ? one.buf : "",
