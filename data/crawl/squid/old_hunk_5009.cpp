        path = pathbuf;
    }

    if (stat(path, &sb) < 0)
        fatalf("%s %s: %s", name, path, xstrerror());
}

char *
