#include "calcusdlg.h"
#include "ui_calcusdlg.h"
#include <QScriptEngine>
#include <QLabel>
#include <QFrame>
#include <QKeyEvent>
#include <QTextDocument>
#include <QScrollBar>
#include "mathwrappers.h"
#include <QDebug>

QScriptValue printToLog(QScriptContext* sc, QScriptEngine* se)
{
	QStringList str;
	for (int i = 0; i < sc->argumentCount(); i++)
		str << sc->argument(i).toString();
	CalcusDlg::log->append(str.join(" "));
	CalcusDlg::log->show();
	CalcusDlg::log->move(CalcusDlg::instance->pos().x() + CalcusDlg::instance->width(), CalcusDlg::instance->pos().y());
	return se->undefinedValue();
}

LogOutput * CalcusDlg::log = NULL;
CalcusDlg * CalcusDlg::instance = NULL;

CalcusDlg::CalcusDlg(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CalcusDlg)
{
	ui->setupUi(this);
	ui->expr->installEventFilter(this);
	//connect(ui->expr, SIGNAL(textChanged()), SLOT(exprChanged()));
	exprHistoryIndex = -1;
	ui->expr->setFocus();
	if (!log)
	{
		log = ui->log;
		log->setParent(NULL);
		log->setWindowTitle("Calcus Output");
	}
	if (!instance)
	{
		instance = this;
	}
}

CalcusDlg::~CalcusDlg()
{
	delete ui;
}

void CalcusDlg::changeEvent(QEvent *e)
{
	QDialog::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

bool CalcusDlg::eventFilter(QObject * obj, QEvent * evt)
{
	if (obj == ui->expr && evt->type() == QEvent::KeyPress)
	{
		QKeyEvent * keyEvent = dynamic_cast<QKeyEvent*>(evt);
		if (keyEvent)
		{
			switch(keyEvent->key())
			{
			case Qt::Key_Up:
				if (exprHistoryIndex == -1)
				{
					// outside history
					if (!ui->expr->text().isEmpty())
						exprHistory.append(ui->expr->text());
					exprHistoryIndex = exprHistory.count() - 1;
					if (exprHistoryIndex >= 0)
						ui->expr->setText(exprHistory[exprHistoryIndex]);
				}
				else
				{
					exprHistoryIndex--;
					if (exprHistoryIndex >= 0)
						ui->expr->setText(exprHistory[exprHistoryIndex]);
					else
						exprHistoryIndex = 0;
				}
				break;
			case Qt::Key_Down:
				if (exprHistoryIndex != -1)
				{
					exprHistoryIndex++;
					if (exprHistoryIndex < exprHistory.count())
						ui->expr->setText(exprHistory[exprHistoryIndex]);
					else
						exprHistoryIndex = exprHistory.count() - 1;
				}
				break;
			case Qt::Key_Return:
			case Qt::Key_Enter:
				if (!(keyEvent->modifiers() & Qt::ShiftModifier))
				{
					ui->calc->click();
					return true;
				}
				break;
			}

		}
	}

	return QDialog::eventFilter(obj, evt);
}

void CalcusDlg::closeEvent(QCloseEvent * evt)
{
	log->close();
	QDialog::closeEvent(evt);
}

void CalcusDlg::addTextToHistory(const QString& text, Qt::Alignment align)
{
	QTextCursor c = ui->history->textCursor();
	c.movePosition(QTextCursor::End);
	ui->history->setTextCursor(c);
	QTextBlockFormat format;
	format.setAlignment(align);
	ui->history->textCursor().insertBlock(format);
	ui->history->textCursor().insertHtml(text);
	ui->history->setTextCursor(c);
	ui->history->ensureCursorVisible();
}

void CalcusDlg::addLineToHistory()
{
	QTextCursor c = ui->history->textCursor();
	c.movePosition(QTextCursor::End);
	ui->history->setTextCursor(c);
	QTextBlockFormat format;
	format.setAlignment(Qt::AlignLeft);
	ui->history->textCursor().insertBlock(format);
	ui->history->textCursor().insertHtml("<hr>");
	ui->history->setTextCursor(c);
	ui->history->ensureCursorVisible();
}

void CalcusDlg::on_calc_clicked()
{
	static QScriptEngine * engine = 0;
	if (!engine)
	{
		engine = new QScriptEngine;
		CalcusMath::registerWrappers(engine);
		engine->globalObject().setProperty("print", engine->newFunction(printToLog));
	}
	QString expr = ui->expr->text();
	if (!expr.length())
		return;
	QScriptValue val = engine->evaluate(expr);
	addTextToHistory(Qt::escape(expr), Qt::AlignLeft);
	if (engine->hasUncaughtException())
	{
		addTextToHistory("<font size=+1 color=red><b>" + Qt::escape(val.toString()) + "</b></font>", Qt::AlignLeft);
	}
	else
	{
		engine->globalObject().setProperty("result", val);
		engine->globalObject().setProperty("res", val);
		addTextToHistory("<font size=+2><b>" + Qt::escape(val.toString()) + "</b></font>", Qt::AlignRight);
		exprHistory.append(expr);
		ui->expr->clear();
		exprHistoryIndex = -1;
	}
	addLineToHistory();
}

void CalcusDlg::exprChanged()
{
	if (exprHistoryIndex != -1)
		exprHistoryIndex = -1;
}
