#define COMM_REUSEADDR		0x04
#define COMM_TRANSPARENT	0x08

#define safe_free(x)	if (x) { xxfree(x); x = NULL; }

#define DISK_OK                   (0)
