#ifndef __QCLICKLABEL__
#define __QCLICKLABEL__

class QString;

#include <QLabel>
#include <QVariant>

class QClickLabel : public QLabel{
	Q_OBJECT

public:
	QClickLabel(QWidget * parent = 0, Qt::WindowFlags f = 0);
	QClickLabel(const QString & text, QWidget * parent = 0, Qt::WindowFlags f = 0);

Q_SIGNALS:
	void Clicked();
	void Pressed();
	void Released();
	void DoubleClicked();

protected:
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);
	virtual void mouseDoubleClickEvent(QMouseEvent * event);
	virtual void mouseMoveEvent(QMouseEvent * event);

protected:
	bool m_Over;
};

#endif
