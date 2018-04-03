                curr->loc = xstrdup("none");
                state = sDOC;
            } else {
                std::cerr << "Error on line " << linenum << std::endl <<
                    "--> " << buff << std::endl;
                exit(1);
            }

