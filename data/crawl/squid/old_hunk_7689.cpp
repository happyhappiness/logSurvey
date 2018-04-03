}
#endif

#ifdef XMALLOC_COUNT
static void xmalloc_count(p, sign)
	void *p;
	int sign;
{
	size_t sz;
	static size_t total = 0;
	int memoryAccounted();
	int mallinfoTotal();
	sz = mallocblksize(p) * sign;
	total += sz;
	fprintf(stderr, "xmalloc_count=%9d  accounted=%9d  mallinfo=%9d\n",
		(int) total,
		memoryAccounted(),
		mallinfoTotal());
}
#endif /* XMALLOC_COUNT */

