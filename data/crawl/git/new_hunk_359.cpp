- '%Creset': reset color
- '%C(...)': color specification, as described under Values in the
  "CONFIGURATION FILE" section of linkgit:git-config[1];
  adding `auto,` at the beginning (e.g. `%C(auto,red)`) will emit
  color only when colors are enabled for log output (by `color.diff`,
  `color.ui`, or `--color`, and respecting the `auto` settings of the
  former if we are going to a terminal). `auto` alone (i.e.
  `%C(auto)`) will turn on auto coloring on the next placeholders
  until the color is switched again.
- '%m': left (`<`), right (`>`) or boundary (`-`) mark
- '%n': newline
- '%%': a raw '%'