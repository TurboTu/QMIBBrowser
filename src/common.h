#ifndef COMMON_H
#define COMMON_H

#include <snmp_pp/snmp_pp.h>
#include <QString>


typedef int Status;
#define Status_SUCCESS      0       //Operation Success
#define Status_FAILED       1       //Operation Failed

typedef int Operation;
#define OperationGet        0       //Operation GetRequest
#define OperationGetNext    1       //Operation GetNextRequest
#define OperationSet        2       //Operation SetRequest

typedef struct {
    UdpAddress address;             //Udp Address including port
    Vb data;                        //oid and value
    Operation operation;            //Request Operation
    std::string community;                //community
    snmp_version version;           //snmp version
    int retry;                      //retry time
    int timeout;                    //timeout number
} Request;

typedef struct {
    QString ip;
    QString port;
    QString oid;
    QString community;
    int retry;
    int timeout;
    snmp_version version;
} RequestInfo;

#endif // COMMON_H