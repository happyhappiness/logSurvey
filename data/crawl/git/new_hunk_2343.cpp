		die("Bad value: %s\n", input);
}

struct test_data {
	const char *from;  /* input:  transform from this ... */
	const char *to;    /* output: ... to this.            */
};

static int test_function(struct test_data *data, char *(*func)(char *input),
	const char *funcname)
{
	int failed = 0, i;
	char buffer[1024];
	char *to;

	for (i = 0; data[i].to; i++) {
		if (!data[i].from)
			to = func(NULL);
		else {
			strcpy(buffer, data[i].from);
			to = func(buffer);
		}
		if (strcmp(to, data[i].to)) {
			error("FAIL: %s(%s) => '%s' != '%s'\n",
				funcname, data[i].from, to, data[i].to);
			failed = 1;
		}
	}
	return failed;
}

static struct test_data basename_data[] = {
	/* --- POSIX type paths --- */
	{ NULL,              "."    },
	{ "",                "."    },
	{ ".",               "."    },
	{ "..",              ".."   },
	{ "/",               "/"    },
#if defined(__CYGWIN__) && !defined(NO_LIBGEN_H)
	{ "//",              "//"   },
	{ "///",             "//"   },
	{ "////",            "//"   },
#else
	{ "//",              "/"    },
	{ "///",             "/"    },
	{ "////",            "/"    },
#endif
	{ "usr",             "usr"  },
	{ "/usr",            "usr"  },
	{ "/usr/",           "usr"  },
	{ "/usr//",          "usr"  },
	{ "/usr/lib",        "lib"  },
	{ "usr/lib",         "lib"  },
	{ "usr/lib///",      "lib"  },

#if defined(__MINGW32__) || defined(_MSC_VER)

	/* --- win32 type paths --- */
	{ "\\usr",           "usr"  },
	{ "\\usr\\",         "usr"  },
	{ "\\usr\\\\",       "usr"  },
	{ "\\usr\\lib",      "lib"  },
	{ "usr\\lib",        "lib"  },
	{ "usr\\lib\\\\\\",  "lib"  },
	{ "C:/usr",          "usr"  },
	{ "C:/usr",          "usr"  },
	{ "C:/usr/",         "usr"  },
	{ "C:/usr//",        "usr"  },
	{ "C:/usr/lib",      "lib"  },
	{ "C:usr/lib",       "lib"  },
	{ "C:usr/lib///",    "lib"  },
	{ "C:",              "."    },
	{ "C:a",             "a"    },
	{ "C:/",             "/"    },
	{ "C:///",           "/"    },
#if defined(NO_LIBGEN_H)
	{ "\\",              "\\"   },
	{ "\\\\",            "\\"   },
	{ "\\\\\\",          "\\"   },
#else

	/* win32 platform variations: */
#if defined(__MINGW32__)
	{ "\\",              "/"    },
	{ "\\\\",            "/"    },
	{ "\\\\\\",          "/"    },
#endif

#if defined(_MSC_VER)
	{ "\\",              "\\"   },
	{ "\\\\",            "\\"   },
	{ "\\\\\\",          "\\"   },
#endif

#endif
#endif
	{ NULL,              NULL   }
};

static struct test_data dirname_data[] = {
	/* --- POSIX type paths --- */
	{ NULL,              "."      },
	{ "",                "."      },
	{ ".",               "."      },
	{ "..",              "."      },
	{ "/",               "/"      },
	{ "//",              "//"     },
#if defined(__CYGWIN__) && !defined(NO_LIBGEN_H)
	{ "///",             "//"     },
	{ "////",            "//"     },
#else
	{ "///",             "/"      },
	{ "////",            "/"      },
#endif
	{ "usr",             "."      },
	{ "/usr",            "/"      },
	{ "/usr/",           "/"      },
	{ "/usr//",          "/"      },
	{ "/usr/lib",        "/usr"   },
	{ "usr/lib",         "usr"    },
	{ "usr/lib///",      "usr"    },

#if defined(__MINGW32__) || defined(_MSC_VER)

	/* --- win32 type paths --- */
	{ "\\",              "\\"     },
	{ "\\\\",            "\\\\"   },
	{ "\\usr",           "\\"     },
	{ "\\usr\\",         "\\"     },
	{ "\\usr\\\\",       "\\"     },
	{ "\\usr\\lib",      "\\usr"  },
	{ "usr\\lib",        "usr"    },
	{ "usr\\lib\\\\\\",  "usr"    },
	{ "C:a",             "C:."    },
	{ "C:/",             "C:/"    },
	{ "C:///",           "C:/"    },
	{ "C:/usr",          "C:/"    },
	{ "C:/usr/",         "C:/"    },
	{ "C:/usr//",        "C:/"    },
	{ "C:/usr/lib",      "C:/usr" },
	{ "C:usr/lib",       "C:usr"  },
	{ "C:usr/lib///",    "C:usr"  },
	{ "\\\\\\",          "\\"     },
	{ "\\\\\\\\",        "\\"     },
#if defined(NO_LIBGEN_H)
	{ "C:",              "C:."    },
#else

	/* win32 platform variations: */
#if defined(__MINGW32__)
	/* the following is clearly wrong ... */
	{ "C:",              "."      },
#endif

#if defined(_MSC_VER)
	{ "C:",              "C:."    },
#endif

#endif
#endif
	{ NULL,              NULL     }
};

int main(int argc, char **argv)
{
	if (argc == 3 && !strcmp(argv[1], "normalize_path_copy")) {
