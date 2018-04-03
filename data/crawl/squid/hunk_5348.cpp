 }
 
 ACLTimeData::ACLTimeData () : weekbits (0), start (0), stop (0), next (NULL) {}
- 
-ACLTimeData::ACLTimeData(ACLTimeData const &old) : weekbits(old.weekbits), start (old.start), stop (old.stop), next (NULL) 
+
+ACLTimeData::ACLTimeData(ACLTimeData const &old) : weekbits(old.weekbits), start (old.start), stop (old.stop), next (NULL)
 {
     if (old.next)
-	next = (ACLTimeData *)old.next->clone();
+        next = (ACLTimeData *)old.next->clone();
 }
 
 ACLTimeData&
