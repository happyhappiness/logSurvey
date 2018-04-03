        }
    }

    // look for and load stylesheet into global MemBuf for it.
    if(Config.errorStylesheet) {
        error_page_stylesheet_content = errorLoadText(Config.errorStylesheet);
    }
}

