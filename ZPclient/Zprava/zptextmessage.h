#ifndef ZPTEXTMESSAGE_H
#define ZPTEXTMESSAGE_H

#include <QString>
#include <QGridLayout>
#include <QLabel>
#include <QFile>
#include <QStyle>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include "zpmessage.h"
#include "zpglobals.h"

extern qint64 TIMESPEC;

class ZpTextMessage : public ZpMessage
{
public:
    ZpTextMessage(ZpUser* _opponent, bool _amIpublisher, int _pk);
    virtual void handle_reply(QString _reply) override;
    virtual void slot_menu_triggered(QAction*menu_action) override;
    QString text;

protected slots:
    void updating() override;

private:
    //widget
    QGridLayout* grid;
    QLabel* forward;
    QLabel* text_label;
    QLabel* datetime_label;
    //STYLESHEET
    QFile File;
    QString FormStyleSheet;
    QString text_process(int &max_lenght, int &num_lines);

};

#endif // ZPTEXTMESSAGE_H
