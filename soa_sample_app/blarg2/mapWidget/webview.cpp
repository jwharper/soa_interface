// System Includes
#include <QGestureEvent>
#include <QPinchGesture>
#include <QApplication>
#include <QWebInspector>
#include <QDebug>
#include <QWebFrame>
#include <QScrollArea>
#include <QHBoxLayout>

// Application Includes
#include "webview.h"
#include "mapwidget.h"


WebView::WebView(QString homeUrl, MapWidget * pParentMapWidget)
    : QWebView(pParentMapWidget), m_pMapWidget(pParentMapWidget),
      m_HomeUrl(homeUrl), m_CurrentUrl(homeUrl), m_pWebFrame(NULL)
{
    Q_UNUSED(homeUrl);
    firstLoad = true;

    //QUrl doesn't like relative paths, so please change accordingly:
    load(QUrl::fromLocalFile("/home/haquema1/Downloads/soa_sample_app/blarg2/mapWidget/Scripts/RVA_derived.htm"));
    show();

    page()->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    connect(this,SIGNAL(loadFinished(bool)), this, SLOT(UpdateOnPageLoad(bool)));
}


void WebView::showWebInspector()
{
    static QWebInspector* pWebInspector = new QWebInspector();

    if(page() != 0)
    {
        pWebInspector->setPage(page());
        pWebInspector->show();
    }
}


void WebView::LoadUrl(QString url)
{
    m_CurrentUrl = url;
    load(QUrl::fromLocalFile(url));
}


void WebView::LoadHome()
{
    m_CurrentUrl = m_HomeUrl;
    load(QUrl::fromLocalFile(m_HomeUrl));
}


void WebView::RefreshPage()
{
    load(QUrl::fromLocalFile(m_CurrentUrl));
}


void WebView::UpdateOnPageLoad(bool ok)
{
    if(!ok)
    {
        //qDebug() << "Something went wrong with the page load";
        return;
    }

    if (firstLoad)
    {
        getWebFrame()->addToJavaScriptWindowObject("gerald", this);
        eval("setWebview(gerald);");
        firstLoad = false;
    }
    Q_EMIT(loaded());
}


void WebView::eval(QString cmd)
{
    getWebFrame()->evaluateJavaScript(cmd);
}


QWebFrame * WebView::getWebFrame()
{
    if (m_pWebFrame == NULL)
        m_pWebFrame = this->page()->mainFrame();
    return m_pWebFrame;
}


void WebView::recvFromJS(QString info)
{
    //Emit signal with the list of coordinates from JS
    Q_EMIT coordRecvFromJS(info);
}

