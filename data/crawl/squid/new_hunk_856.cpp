                                     fmt->widthMax : strlen(out);

                if (fmt->left)
                    mb.appendf("%-*.*s", minWidth, maxWidth, out);
                else
                    mb.appendf("%*.*s", minWidth, maxWidth, out);
            } else
                mb.append(out, strlen(out));
        } else {
