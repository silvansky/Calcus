#include "logoutput.h"

LogOutput::LogOutput(QWidget *parent) :
    QTextEdit(parent)
{
	setReadOnly(true);
}
