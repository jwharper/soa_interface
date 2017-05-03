#include "qclicklabel.h"

#include <QMouseEvent>

QClickLabel::QClickLabel(QWidget * parent, Qt::WindowFlags f) : QLabel(parent, f), m_Over(false) {}
QClickLabel::QClickLabel(const QString & text, QWidget * parent, Qt::WindowFlags f) : QLabel(text, parent, f), m_Over(false) {}

void QClickLabel::mousePressEvent(QMouseEvent * event){

	(void)event;
	m_Over = true;
	Q_EMIT(Pressed());
}

void QClickLabel::mouseReleaseEvent(QMouseEvent * event){

	m_Over = false;
	if(event->buttons() && Qt::LeftButton) return;

	if(frameGeometry().contains(mapToParent(event->pos()))){
		Q_EMIT(Released());
		Q_EMIT(Clicked());
	}
}

void QClickLabel::mouseMoveEvent(QMouseEvent * event){
	bool currentlyOver;

	currentlyOver = frameGeometry().contains(mapToParent(event->pos()));

	if(event->buttons() && Qt::LeftButton){
		if(currentlyOver && !m_Over){
			Q_EMIT(Pressed());
		}
		if(!currentlyOver && m_Over){
			Q_EMIT(Released());
		}
	}

	m_Over = currentlyOver;
}

void QClickLabel::mouseDoubleClickEvent(QMouseEvent * event){

	(void)event;
	Q_EMIT(DoubleClicked());
}


