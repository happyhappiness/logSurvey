#define SVNDUMP_H_

int svndump_init(const char *filename);
int svndump_init_fd(int in_fd, int back_fd);
void svndump_read(const char *url);
void svndump_deinit(void);
void svndump_reset(void);