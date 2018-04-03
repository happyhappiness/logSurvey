	strbuf_release(&key);
	return childenv;
}
#endif

static inline void set_cloexec(int fd)
{
