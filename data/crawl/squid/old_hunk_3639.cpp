        if (ah != NULL) {
            String name, value;
            if (ah->getXxRecord(name, value)) {
                buf.Printf(SQUIDSTRINGPH ": " SQUIDSTRINGPH "\r\n",  
                    SQUIDSTRINGPRINT(name), SQUIDSTRINGPRINT(value));
            }
        }
    }
    

    buf.Printf("Encapsulated: ");

