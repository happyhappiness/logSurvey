 * MemBuf buf;
 * 
 * -- required init with optional size tuning (see #defines for defaults)
 * memBufInit(&buf, initial-size, absolute-maximum);
 * 
 * -- "pack" (no need to handle offsets or check for overflows)
 * memBufPrintf(&buf, ...);
 * ...
 * 
 * -- write
 * comm_write_mbuf(fd, buf, handler, data);
 *
 * -- *iff* you did not give the buffer away, free it yourself
 * -- memBufClean(&buf);
 * }
 */
/* if you have configure you can use this */
