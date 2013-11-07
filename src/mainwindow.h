#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTableWidget>

#include "common.h"
#include "snmpmanager.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SnmpManager *snmpManager;
    RequestInfo *requestInfo;
    Request *request;

    /*initial Class*/
    void initialRequestInfo(RequestInfo *requestInfo);
    void initialWidgets();
    void initialMIBTreeWidget(QTreeWidget *MIBTreeWidget);
    void initialMIBTableWidget(QTableWidget *MIBTableWidget);
    void initialResultTableWidget(QTableWidget *resultTableWidget);
    void initialConnections(void);

    /*Update Widget Value with the given RequestInfo*/
    void updateWidgetValue(RequestInfo *requestInfo);

    /*Set up Request according to the Operation*/
    Status setUpRequest(Operation operation, Request *request);
    Status setUpRequestGet(Request *request);
    Status setUpRequestGetNext(Request *request);
    Status setUpRequestSet(Request *request);

    /*Check the Request Valid or Not*/
    Status checkRequest(Operation operation, Request *request);

public slots:
    /*connection with AdvancedOptionDialog*/
    void updateRequestInfo(RequestInfo *requestInfo);

private slots:
    void onIPLineEditChanged(const QString &ip);
    void onOidLineEditChanged(const QString &oid);
    void onAdvancedOptionPushButtonClicked();
    void onGoPushButtonClicked();
    /*Reset ResultTableWidget*/
    void resetResultTableWidget();

};

#endif // MAINWINDOW_H
