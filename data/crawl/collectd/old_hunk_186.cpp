#define OK1(cond, text) do { \
  _Bool result = (cond); \
  printf ("%s %i - %s\n", result ? "ok" : "not ok", ++check_count__, text); \
} while (0)
#define OK(cond) OK1(cond, #cond)

