#ifndef LOGOUTPUT_H
#define LOGOUTPUT_H

#include <QTextEdit>

class LogOutput : public QTextEdit
{
    Q_OBJECT
public:
    explicit LogOutput(QWidget *parent = 0);

signals:

public slots:

};

#endif // LOGOUTPUT_H
