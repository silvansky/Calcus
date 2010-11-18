#ifndef CALCUSDLG_H
#define CALCUSDLG_H

#include <QDialog>
#include <Qt>
#include <QtScript>
#include "logoutput.h"

namespace Ui {
class CalcusDlg;
}

class CalcusDlg : public QDialog
{
	Q_OBJECT
	friend QScriptValue printToLog(QScriptContext* sc, QScriptEngine* se);
public:
	explicit CalcusDlg(QWidget *parent = 0);
	~CalcusDlg();

protected:
	void changeEvent(QEvent *e);
	bool eventFilter(QObject *, QEvent *);
	void closeEvent(QCloseEvent *);
	void addTextToHistory(const QString& text, Qt::Alignment align);
	void addLineToHistory();

private slots:
	void on_calc_clicked();
	void exprChanged();

private:
	Ui::CalcusDlg *ui;
	QList<QString> exprHistory;
	int exprHistoryIndex;
	static LogOutput * log;
	static CalcusDlg * instance;
};

#endif // CALCUSDLG_H
