  fputs (_("\n# files hash-table stats:\n# "), stdout);
  hash_print_stats (&files, stdout);
}

#define EXPANSION_INCREMENT(_l)  ((((_l) / 500) + 1) * 500)

