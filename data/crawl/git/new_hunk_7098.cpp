	} while (1);
	inflateEnd(&stream);

	close_sha1_file(local);
	SHA1_Final(real_sha1, &c);
	if (ret != Z_STREAM_END) {
		unlink(tmpfile);