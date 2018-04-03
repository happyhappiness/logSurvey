#define TOUCH_ERROR(call) return (perror_with_name (call, file->name), 1)

static int
touch_file (struct file *file)
{
  if (!silent_flag)
    message (0, "touch %s", file->name);
