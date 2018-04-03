            usage();
            exit(0);
        default:
            std::cerr << program_name << ": FATAL: unknown option: -" <<
                static_cast<char>(optopt) << ". Exiting" << std::endl;
            usage();
            exit(1);
        }
