    { "IPv6", prefer_ipv6 },
    { "none", prefer_none },
  };
  int prefer_family = prefer_none;
  int ok = decode_string (val, choices, countof (choices), &prefer_family);
  if (!ok)
    fprintf (stderr, _("%s: %s: Invalid value %s.\n"), exec_name, com, quote (val));
src/ChangeLog |  8 ++++++++
src/main.c    | 16 ++++++++--------
2 files changed, 16 insertions(+), 8 deletions(-)
