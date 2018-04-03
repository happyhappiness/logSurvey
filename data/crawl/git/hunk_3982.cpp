 - '%Cgreen': switch color to green
 - '%Cblue': switch color to blue
 - '%Creset': reset color
+- '%C(...)': color specification, as described in color.branch.* config option;
+  adding `auto,` at the beginning will emit color only when colors are
+  enabled for log output (by `color.diff`, `color.ui`, or `--color`, and
+  respecting the `auto` settings of the former if we are going to a
+  terminal)
 - '%m': left, right or boundary mark
 - '%n': newline
 - '%%': a raw '%'
