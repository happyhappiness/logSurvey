  }

  return count;
}

int main (int argc, char **argv) {
  char address[1024] = "unix:"DEFAULT_SOCK;
  char *plugin = NULL;
  char ident_str[1024] = "";
  int timeout = -1;
  char hostname[1024];

  while (42) {
    int c;

    c = getopt (argc, argv, "s:p:i:ht:");

    if (c == -1)
      break;
