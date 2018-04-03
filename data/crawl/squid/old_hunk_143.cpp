    if (it != TheSslErrorShortcuts.end()) {
        // Should not be empty...
        assert(it->second[0] != SSL_ERROR_NONE);
        Ssl::Errors *errors = new Ssl::Errors(it->second[0]);
        for (int i =1; it->second[i] != SSL_ERROR_NONE; ++i) {
            errors->push_back_unique(it->second[i]);
        }
        return errors;
    }

    fatalf("Unknown SSL error name '%s'", name);
    return NULL; // not reached
}

const char *Ssl::GetErrorName(Security::ErrorCode value)
