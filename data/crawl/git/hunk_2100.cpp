 				if (errno || inleft) {
 					/*
 					 * iconv() failed and errno could be E2BIG, EILSEQ, EINVAL, EBADF
-					 * MacOS X avoids illegal byte sequemces.
+					 * MacOS X avoids illegal byte sequences.
 					 * If they occur on a mounted drive (e.g. NFS) it is not worth to
 					 * die() for that, but rather let the user see the original name
 					*/
