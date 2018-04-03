        if (!Config.Addrs.snmp_outgoing.IsNoAddr()) {
            Config.Addrs.snmp_outgoing.SetPort(Config.Port.snmp);

            AsyncCall::Pointer call = asyncCall(49, 2,
                                                "snmpOutgoingConnectionOpened",
                                                SnmpListeningStartedDialer(&snmpOutgoingConnectionOpened));