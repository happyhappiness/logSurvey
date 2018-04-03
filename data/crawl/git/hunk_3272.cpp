 that easily could have gone undetected in another system. The result
 still compiled, but would have caused an interesting bug (that would
 have been blamed on some random commit).
+
+
+The adventure continues...
+--------------------------
+
+I ended up doing this again! Same entity, new hardware. The assumption
+at this point is that the old disk corrupted the packfile, and then the
+corruption was migrated to the new hardware (because it was done by
+rsync or similar, and no fsck was done at the time of migration).
+
+This time, the affected blob was over 20 megabytes, which was far too
+large to do a brute-force on. I followed the instructions above to
+create the `zlib` file. I then used the `inflate` program below to pull
+the corrupted data from that. Examining that output gave me a hint about
+where in the file the corruption was. But now I was working with the
+file itself, not the zlib contents. So knowing the sha1 of the object
+and the approximate area of the corruption, I used the `sha1-munge`
+program below to brute-force the correct byte.
+
+Here's the inflate program (it's essentially `gunzip` but without the
+`.gz` header processing):
+
+--------------------------
+#include <stdio.h>
+#include <string.h>
+#include <zlib.h>
+#include <stdlib.h>
+
+int main(int argc, char **argv)
+{
+	/*
+	 * oversized so we can read the whole buffer in;
+	 * this could actually be switched to streaming
+	 * to avoid any memory limitations
+	 */
+	static unsigned char buf[25 * 1024 * 1024];
+	static unsigned char out[25 * 1024 * 1024];
+	int len;
+	z_stream z;
+	int ret;
+
+	len = read(0, buf, sizeof(buf));
+	memset(&z, 0, sizeof(z));
+	inflateInit(&z);
+
+	z.next_in = buf;
+	z.avail_in = len;
+	z.next_out = out;
+	z.avail_out = sizeof(out);
+
+	ret = inflate(&z, 0);
+	if (ret != Z_OK && ret != Z_STREAM_END)
+		fprintf(stderr, "initial inflate failed (%d)\n", ret);
+
+	fprintf(stderr, "outputting %lu bytes", z.total_out);
+	fwrite(out, 1, z.total_out, stdout);
+	return 0;
+}
+--------------------------
+
+And here is the `sha1-munge` program:
+
+--------------------------
+#include <stdio.h>
+#include <unistd.h>
+#include <string.h>
+#include <signal.h>
+#include <openssl/sha.h>
+#include <stdlib.h>
+
+/* eye candy */
+static int counter = 0;
+static void progress(int sig)
+{
+	fprintf(stderr, "\r%d", counter);
+	alarm(1);
+}
+
+static const signed char hexval_table[256] = {
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 00-07 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 08-0f */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 10-17 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 18-1f */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 20-27 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 28-2f */
+	  0,  1,  2,  3,  4,  5,  6,  7,		/* 30-37 */
+	  8,  9, -1, -1, -1, -1, -1, -1,		/* 38-3f */
+	 -1, 10, 11, 12, 13, 14, 15, -1,		/* 40-47 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 48-4f */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 50-57 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 58-5f */
+	 -1, 10, 11, 12, 13, 14, 15, -1,		/* 60-67 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 68-67 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 70-77 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 78-7f */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 80-87 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 88-8f */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 90-97 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* 98-9f */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* a0-a7 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* a8-af */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* b0-b7 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* b8-bf */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* c0-c7 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* c8-cf */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* d0-d7 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* d8-df */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* e0-e7 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* e8-ef */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* f0-f7 */
+	 -1, -1, -1, -1, -1, -1, -1, -1,		/* f8-ff */
+};
+
+static inline unsigned int hexval(unsigned char c)
+{
+return hexval_table[c];
+}
+
+static int get_sha1_hex(const char *hex, unsigned char *sha1)
+{
+	int i;
+	for (i = 0; i < 20; i++) {
+		unsigned int val;
+		/*
+		 * hex[1]=='\0' is caught when val is checked below,
+		 * but if hex[0] is NUL we have to avoid reading
+		 * past the end of the string:
+		 */
+		if (!hex[0])
+			return -1;
+		val = (hexval(hex[0]) << 4) | hexval(hex[1]);
+		if (val & ~0xff)
+			return -1;
+		*sha1++ = val;
+		hex += 2;
+	}
+	return 0;
+}
+
+int main(int argc, char **argv)
+{
+	/* oversized so we can read the whole buffer in */
+	static unsigned char buf[25 * 1024 * 1024];
+	char header[32];
+	int header_len;
+	unsigned char have[20], want[20];
+	int start, len;
+	SHA_CTX orig;
+	unsigned i, j;
+
+	if (!argv[1] || get_sha1_hex(argv[1], want)) {
+		fprintf(stderr, "usage: sha1-munge <sha1> [start] <file.in\n");
+		return 1;
+	}
+
+	if (argv[2])
+		start = atoi(argv[2]);
+	else
+		start = 0;
+
+	len = read(0, buf, sizeof(buf));
+	header_len = sprintf(header, "blob %d", len) + 1;
+	fprintf(stderr, "using header: %s\n", header);
+
+	/*
+	 * We keep a running sha1 so that if you are munging
+	 * near the end of the file, we do not have to re-sha1
+	 * the unchanged earlier bytes
+	 */
+	SHA1_Init(&orig);
+	SHA1_Update(&orig, header, header_len);
+	if (start)
+		SHA1_Update(&orig, buf, start);
+
+	signal(SIGALRM, progress);
+	alarm(1);
+
+	for (i = start; i < len; i++) {
+		unsigned char c;
+		SHA_CTX x;
+
+#if 0
+		/*
+		 * deletion -- this would not actually work in practice,
+		 * I think, because we've already committed to a
+		 * particular size in the header. Ditto for addition
+		 * below. In those cases, you'd have to do the whole
+		 * sha1 from scratch, or possibly keep three running
+		 * "orig" sha1 computations going.
+		 */
+		memcpy(&x, &orig, sizeof(x));
+		SHA1_Update(&x, buf + i + 1, len - i - 1);
+		SHA1_Final(have, &x);
+		if (!memcmp(have, want, 20))
+			printf("i=%d, deletion\n", i);
+#endif
+
+		/*
+		 * replacement -- note that this tries each of the 256
+		 * possible bytes. If you suspect a single-bit flip,
+		 * it would be much shorter to just try the 8
+		 * bit-flipped variants.
+		 */
+		c = buf[i];
+		for (j = 0; j <= 0xff; j++) {
+			buf[i] = j;
+
+			memcpy(&x, &orig, sizeof(x));
+			SHA1_Update(&x, buf + i, len - i);
+			SHA1_Final(have, &x);
+			if (!memcmp(have, want, 20))
+				printf("i=%d, j=%02x\n", i, j);
+		}
+		buf[i] = c;
+
+#if 0
+		/* addition */
+		for (j = 0; j <= 0xff; j++) {
+			unsigned char extra = j;
+			memcpy(&x, &orig, sizeof(x));
+			SHA1_Update(&x, &extra, 1);
+			SHA1_Update(&x, buf + i, len - i);
+			SHA1_Final(have, &x);
+			if (!memcmp(have, want, 20))
+				printf("i=%d, addition=%02x", i, j);
+		}
+#endif
+
+		SHA1_Update(&orig, buf + i, 1);
+		counter++;
+	}
+
+	alarm(0);
+	fprintf(stderr, "\r%d\n", counter);
+	return 0;
+}
+--------------------------