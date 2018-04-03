            const char *value = TheConfig.client_username_encode ? old_base64_encode(name) : name;
            buf.Printf("%s: %s\r\n", TheConfig.client_username_header, value);
        }
    }
#endif
}