 * MemBuf buf;
 * 
 * -- required init with optional size tuning (see #defines for defaults)
 * buf.init(initial-size, absolute-maximum);
 * 
 * -- "pack" (no need to handle offsets or check for overflows)
 * buf.Printf(...);
 * ...
 * 
 * -- write
 * comm_write_mbuf(fd, buf, handler, data);
 *
 * -- *iff* you did not give the buffer away, free it yourself
 * -- buf.clean();
 * }
 */
/* if you have configure you can use this */
