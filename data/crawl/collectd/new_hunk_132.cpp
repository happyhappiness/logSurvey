
#define END_TEST exit ((fail_count__ == 0) ? 0 : 1);

#define LOG(result, text) \
  printf ("%s %i - %s\n", result ? "ok" : "not ok", ++check_count__, text)

#define OK1(cond, text) do { \
  _Bool result = (cond); \
  LOG (result, text); \
  if (!result) { return -1; } \
} while (0)
#define OK(cond) OK1(cond, #cond)
