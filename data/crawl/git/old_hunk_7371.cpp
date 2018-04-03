static uint32_t input_crc32;
static int input_fd, output_fd, pack_fd;

/* Discard current buffer used content. */
static void flush(void)
{
