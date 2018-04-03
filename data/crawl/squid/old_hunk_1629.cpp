        }
    }

    int insertedCount = 0;
    if (!hasEPRT) {
        filteredHeader.putStr(HDR_FTP_PRE, "\" EPRT\"");
        ++insertedCount;
    }
    if (!hasEPSV) {
        filteredHeader.putStr(HDR_FTP_PRE, "\" EPSV\"");
        ++insertedCount;
    }
