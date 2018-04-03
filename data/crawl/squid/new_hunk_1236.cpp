                const SBuf t(optarg);
                ::Parser::Tokenizer tok(t);
                const CharacterSet chr = CharacterSet::ALPHA+CharacterSet::DIGIT;
                if (!tok.prefix(service_name, chr))
                    fatalf("Expected alphanumeric service name for the -n option but got: %s", optarg);
                if (!tok.atEnd())
                    fatalf("Garbage after alphanumeric service name in the -n option value: %s", optarg);
                if (service_name.length() > 32)
                    fatalf("Service name (-n option) must be limited to 32 characters but got %u", service_name.length());
                opt_signal_service = true;