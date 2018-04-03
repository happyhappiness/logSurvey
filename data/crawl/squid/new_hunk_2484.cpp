                    break;
            }
            if (!entry) {
                std::cerr << "ERROR: '" << directive << "' (" << name << ") depends on '" << dep->name << "'\n";
                exit(1);
            }
        }
        return;
    }
    std::cerr << "ERROR: Dependencies for cf.data type '" << name << "' used in ' " << directive << "' not defined\n" ;
    exit(1);
}

static void
usage(const char *program_name)
{
    std::cerr << "Usage: " << program_name << " cf.data cf.data.depend\n";
    exit(1);
}

int
main(int argc, char *argv[])
{
    char *input_filename;
    const char *output_filename = _PATH_PARSER;
    const char *conf_filename = _PATH_SQUID_CONF;
