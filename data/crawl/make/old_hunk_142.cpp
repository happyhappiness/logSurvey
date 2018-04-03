			FreeLibrary(hModule);
		}
#else
		fatal(NILF, szMessageBuffer);
#endif
	} else {
		/*
