
            if (fmt->width) {
                if (fmt->left)
                    mb.Printf("%-*s", (int) fmt->width, out);
                else
                    mb.Printf("%*s", (int) fmt->width, out);
            } else
                mb.append(out, strlen(out));
        } else {
            mb.append("-", 1);
        }

        if (fmt->space)
            mb.append(" ", 1);

        sb.clean();

