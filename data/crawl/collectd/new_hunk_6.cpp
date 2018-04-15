
  return 0;
}
#endif

int main(void) {
  int ret = 0;

  int status;
  if ((status = test_network_parse())) {
    ret = status;
