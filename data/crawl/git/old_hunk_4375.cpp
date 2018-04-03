DEFINE_ALLOCATOR(tag, struct tag)
DEFINE_ALLOCATOR(object, union any_object)

#ifdef NO_C99_FORMAT
#define SZ_FMT "%u"
#else
#define SZ_FMT "%zu"
#endif

static void report(const char *name, unsigned int count, size_t size)
{
    fprintf(stderr, "%10s: %8u (" SZ_FMT " kB)\n", name, count, size);
}

#undef SZ_FMT

#define REPORT(name)	\
    report(#name, name##_allocs, name##_allocs*sizeof(struct name) >> 10)

