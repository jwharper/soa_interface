#include "qsidepanel.h"

#include <QMenu>
#include <QAction>
#include <QPainter>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <assert.h>

#include "qsidepanelcontainer.h"

const long SELECTED_BORDER_WIDTH = 8;
const char FONT_FAMILY[] = "Lucida Console";
const long FONT_SIZE = 8;
const long FONT_SIZE2 = 12;
const long FONT_WEIGHT = QFont::Bold;


QSidePanel::QSidePanel(void * pId, QWidget * parent) : QFrame(parent){

	if(m_SidePanelInstanceCount == 0) SidePanelInit();
	m_SidePanelInstanceCount++;

	m_pId = pId;
	m_pContextMenu = NULL;

	setFrameStyle(QFrame::Box | QFrame::Plain);
	m_Selected = false;
	m_Pinned = false;
	ChangeStatus(Unknown, false);

	m_pPlus = new QClickLabel(tr("Plus"), this);
	m_pMinus = new QClickLabel(tr("Minus"), this);
	m_pPin = new QClickLabel(tr("Pin"), this);
	
	m_pPlus->setPixmap(*m_pPlusPixmap);
	m_pMinus->setPixmap(*m_pMinusPixmap);
	m_pPin->setPixmap(*m_pPinPixmap);

	m_pPlus->setFixedSize(m_pPlusPixmap->size());
	m_pMinus->setFixedSize(m_pMinusPixmap->size());
	m_pPin->setFixedSize(m_pPinPixmap->size());

	ChangeFailingBrush(Qt::yellow);
	ChangeFailedBrush(QColor(255, 180, 180));

    connect(m_pPin, SIGNAL(Clicked()), this, SLOT(PinClicked()));
    connect(m_pPlus, SIGNAL(Clicked()), this, SLOT(IncreaseMode()));
    connect(m_pMinus, SIGNAL(Clicked()), this, SLOT(DecreaseMode()));

	// Move Pin
	m_pPin->move(frameWidth() + 1, frameWidth() + 1);
	setAutoFillBackground(false);
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	if(m_ForcedWidth != -1) setFixedWidth(m_ForcedWidth);
}

QSidePanel::~QSidePanel(){

	m_SidePanelInstanceCount--;
	if(m_SidePanelInstanceCount <= 0){
		m_SidePanelInstanceCount = 0;
		SidePanelShutdown();
	}
}

void QSidePanel::ChangeSelection(bool state){

	m_Selected = state;
	Q_EMIT(SelectionChanged(state));
	update();
}

void QSidePanel::paintEvent(QPaintEvent * event){
	long xPos, yPos;

	QPainter painter(this);

	// Paint the background
	painter.setPen(Qt::NoPen);
	if(m_Status == Unknown || m_Status == Normal || m_Status == Paused || m_Status == Canceled || m_Status == Queued || m_Status == Done || m_Status == Alg){
		painter.setBrush(palette().window());	
	}
	else if(m_Status == Failing){
		painter.setBrush(m_FailingBrush);
	}
	else if(m_Status == Failed){
		painter.setBrush(m_FailedBrush);
	}
	else{
		assert(0);
	}
	painter.drawRect(frameWidth(), frameWidth(), width() - frameWidth(), height() - frameWidth());

	// Draw border
	yPos = height() - frameWidth() - m_pBorderPixmap->height();
	painter.drawPixmap(frameWidth(), yPos, width() - 2 * frameWidth(), m_pBorderPixmap->height(), *m_pBorderPixmap);

	// Draw upper corner
	if (m_Status != Alg)
		painter.drawPixmap(frameWidth(), frameWidth(), *m_pUpperCornerPixmap);

	// Draw lower corner
    if (m_Status != Alg)
    {
		if(!PlusPresent(m_Mode) || !MinusPresent(m_Mode)){
			xPos = width() - frameWidth() - m_pSmallLowerCornerPixmap->width();
			yPos = height() - frameWidth() - m_pSmallLowerCornerPixmap->height();
			painter.drawPixmap(xPos, yPos, *m_pSmallLowerCornerPixmap);
		}
		else{
			xPos = width() - frameWidth() - m_pLowerCornerPixmap->width();
			yPos = height() - frameWidth() - m_pLowerCornerPixmap->height();
			painter.drawPixmap(xPos, yPos, *m_pLowerCornerPixmap);
        }
    }

	painter.end();

	if(m_Selected){
		QPainter painter(this);
		painter.setPen(QPen(Qt::black, SELECTED_BORDER_WIDTH));
		painter.setBrush(Qt::NoBrush);
		painter.drawRect(0, 0, width(), height());
		painter.end();
	}

	QFrame::paintEvent(event);
}

void QSidePanel::mousePressEvent(QMouseEvent * event){

	(void)event;
	m_Over = true;
	Q_EMIT(Pressed());
}

void QSidePanel::mouseReleaseEvent(QMouseEvent * event){

	m_Over = false;
	if(event->buttons() && Qt::LeftButton) return;

	if(frameGeometry().contains(mapToParent(event->pos()))){
		Q_EMIT(Released());
		Q_EMIT(Clicked());
	}
}

void QSidePanel::mouseMoveEvent(QMouseEvent * event){
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

void QSidePanel::mouseDoubleClickEvent(QMouseEvent * event){

	(void)event;
	Q_EMIT(DoubleClicked());
}

void QSidePanel::contextMenuEvent(QContextMenuEvent * pEvent){

	// Execute the panel's context menu.
	if(m_pContextMenu){
		QAction * pAction = m_pContextMenu->exec(pEvent->globalPos());
		if(pAction) Q_EMIT(ContextMenuActionTriggered(pAction));
	}
}

void QSidePanel::PinClicked(){

	ChangePinned(!m_Pinned);

	if(m_Pinned) m_pPin->setPixmap(*m_pPinnedPixmap);
	else m_pPin->setPixmap(*m_pPinPixmap);
}

void QSidePanel::ChangePinned(bool pinned){

	m_Pinned = pinned;
	Q_EMIT(Pinned(m_Pinned));
}

void QSidePanel::PositionPlusMinus(){
	long xPos, yPos;

	if(PlusPresent(m_Mode)){
		m_pPlus->show();
		xPos = width() - frameWidth() - m_pPlusPixmap->width();
		yPos = height() - frameWidth() - m_pPlusPixmap->height();
		m_pPlus->move(xPos, yPos);
	}
	else{
		m_pPlus->hide();
	}

	if(!MinusPresent(m_Mode)){
		m_pMinus->hide();
	}
	else if(!PlusPresent(m_Mode)){
		m_pMinus->show();
		xPos = width() - frameWidth() - m_pMinusPixmap->width();
		yPos = height() - frameWidth() - m_pMinusPixmap->height();
		m_pMinus->move(xPos, yPos);
	}
	else{
		m_pMinus->show();
		xPos = width() - frameWidth() - m_pMinusPixmap->width();
		yPos = height() - frameWidth() - m_pPlusPixmap->height() - m_pMinusPixmap->height();
		m_pMinus->move(xPos, yPos);
	}
}

void QSidePanel::resizeEvent(QResizeEvent * event){

	PositionPlusMinus();
	QFrame::resizeEvent(event);
}

void QSidePanel::ChangeStatus(PanelStatus status, bool resort){

	m_Status = status;
	Q_EMIT(StatusChanged());
	update();
	if(resort) Q_EMIT(ResortRequested());
}

void QSidePanel::ChangeFailingBrush(QBrush brush){

	m_FailingBrush = brush;
	if(m_Status == Failing) update();
}

void QSidePanel::ChangeFailedBrush(QBrush brush){
	
	m_FailedBrush = brush;
	if(m_Status == Failed) update();
}

void QSidePanel::SidePanelInit(){

    m_pPinPixmap = new QPixmap("../../tabWidgetFiles/qsp-pin.png");
    m_pPinnedPixmap = new QPixmap("../../tabWidgetFiles/qsp-pinned.png");
    m_pPlusPixmap = new QPixmap("../../tabWidgetFiles/qsp-plus.png");
    m_pMinusPixmap = new QPixmap("../../tabWidgetFiles/qsp-minus.png");
    m_pLowerCornerPixmap = new QPixmap("../../tabWidgetFiles/qsp-lowercorner.png");
    m_pSmallLowerCornerPixmap = new QPixmap("../../tabWidgetFiles/qsp-smalllowercorner.png");
    m_pUpperCornerPixmap = new QPixmap("../../tabWidgetFiles/qsp-uppercorner.png");
    m_pBorderPixmap = new QPixmap("../../tabWidgetFiles/qsp-border.png");
    m_pInterruptPixmap = new QPixmap("../../tabWidgetFiles/interrupt.png");
    m_pUavPixmap = new QPixmap("../../tabWidgetFiles/small_uav.png");
    m_pUgvPixmap = new QPixmap("../../tabWidgetFiles/heavy_uav.png");
    m_pPlayPixmap = new QPixmap("../../tabWidgetFiles/play.png");
    m_pPausePixmap = new QPixmap("../../tabWidgetFiles/pause.png");

//    m_pPinPixmap = new QPixmap("/home/haquema1/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/qsp-pin.png");
//    m_pPinnedPixmap = new QPixmap("/home/musadhaque/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/qsp-pinned.png");
//    m_pPlusPixmap = new QPixmap("/home/musadhaque/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/qsp-plus.png");
//    m_pMinusPixmap = new QPixmap("/home/musadhaque/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/qsp-minus.png");
//    m_pLowerCornerPixmap = new QPixmap("/home/musadhaque/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/qsp-lowercorner.png");
//    m_pSmallLowerCornerPixmap = new QPixmap("/home/musadhaque/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/qsp-smalllowercorner.png");
//    m_pUpperCornerPixmap = new QPixmap("/home/musadhaque/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/qsp-uppercorner.png");
//    m_pBorderPixmap = new QPixmap("/home/musadhaque/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/qsp-border.png");
//    m_pInterruptPixmap = new QPixmap("/home/musadhaque/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/interrupt.png");
//    m_pUavPixmap = new QPixmap("/home/musadhaque/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/small_uav.png");
//    m_pUgvPixmap = new QPixmap("/home/musadhaque/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/heavy_uav.png");
//    m_pPlayPixmap = new QPixmap("/home/musadhaque/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/play.png");
//    m_pPausePixmap = new QPixmap("/home/musadhaque/Downloads/soa_sample_app/tabwidget2/tabWidgetFiles/pause.png");

//	if(m_pPinPixmap->isNull()) assert(0);
//	if(m_pPinnedPixmap->isNull()) assert(0);
//	if(m_pPlusPixmap->isNull()) assert(0);
//	if(m_pMinusPixmap->isNull()) assert(0);
//	if(m_pLowerCornerPixmap->isNull()) assert(0);
//	if(m_pSmallLowerCornerPixmap->isNull()) assert(0);
//	if(m_pUpperCornerPixmap->isNull()) assert(0);
//	if(m_pBorderPixmap->isNull()) assert(0);
//	if(m_pInterruptPixmap->isNull()) assert(0);
//	if(m_pUavPixmap->isNull()) assert(0);
//	if(m_pUgvPixmap->isNull()) assert(0);
//	if(m_pPlayPixmap->isNull()) assert(0);
//	if(m_pPausePixmap->isNull()) assert(0);

	// Configure font
	QFont font(FONT_FAMILY, FONT_SIZE, FONT_WEIGHT);
	m_Font = font;
	QFontMetrics fontMetrics(font);
	m_FontMetrics = fontMetrics;
	
	QFont font2(FONT_FAMILY, FONT_SIZE2, FONT_WEIGHT);
	m_Font2 = font2;
	QFontMetrics fontMetrics2(font2);
	m_FontMetrics2 = fontMetrics2;
}

void QSidePanel::SidePanelShutdown(){

	if(m_pPinPixmap) delete(m_pPinPixmap);
	if(m_pPinnedPixmap) delete(m_pPinnedPixmap);
	if(m_pPlusPixmap) delete(m_pPlusPixmap);
	if(m_pMinusPixmap) delete(m_pMinusPixmap);
	if(m_pLowerCornerPixmap) delete(m_pLowerCornerPixmap);
	if(m_pSmallLowerCornerPixmap) delete(m_pSmallLowerCornerPixmap);
	if(m_pUpperCornerPixmap) delete(m_pUpperCornerPixmap);
	if(m_pBorderPixmap) delete(m_pBorderPixmap);
}

int QSidePanel::m_SidePanelInstanceCount = 0;
long QSidePanel::m_ForcedWidth = 365;

QPixmap * QSidePanel::m_pPinPixmap = NULL;
QPixmap * QSidePanel::m_pPinnedPixmap = NULL;
QPixmap * QSidePanel::m_pPlusPixmap = NULL;
QPixmap * QSidePanel::m_pMinusPixmap = NULL;
QPixmap * QSidePanel::m_pLowerCornerPixmap = NULL;
QPixmap * QSidePanel::m_pSmallLowerCornerPixmap = NULL;
QPixmap * QSidePanel::m_pUpperCornerPixmap = NULL;
QPixmap * QSidePanel::m_pBorderPixmap = NULL;
QPixmap * QSidePanel::m_pInterruptPixmap = NULL;
QPixmap * QSidePanel::m_pUavPixmap = NULL;
QPixmap * QSidePanel::m_pUgvPixmap = NULL;
QPixmap * QSidePanel::m_pPlayPixmap = NULL;
QPixmap * QSidePanel::m_pPausePixmap = NULL;

QFont QSidePanel::m_Font;
QFontMetrics QSidePanel::m_FontMetrics = QFontMetrics(m_Font);
QFont QSidePanel::m_Font2;
QFontMetrics QSidePanel::m_FontMetrics2 = QFontMetrics(m_Font2);


