            ++ndir;

            j += SD->callback();

            if (j > 100)
                fatal ("too much io\n");
        }
    } while (j > 0);

