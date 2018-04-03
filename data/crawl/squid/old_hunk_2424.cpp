            }

            // enforce width limits if configured
            const bool haveMaxWidth = fmt->precision && !doint && !dooff;
            if (haveMaxWidth || fmt->width) {
                const int minWidth = fmt->width ?
                                     static_cast<int>(fmt->width) : 0;
                const int maxWidth = haveMaxWidth ?
                                     static_cast<int>(fmt->precision) : strlen(out);

                if (fmt->left)
                    mb.Printf("%-*.*s", minWidth, maxWidth, out);
