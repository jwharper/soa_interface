#ifndef WEBVIEW_H
#define WEBVIEW_H

// System Includes
#include <QWebView>
#include <QWebFrame>
#include <QDebug>
#include <QUrl>

// Application Includes

// Forward Declaratoins
class QWebInspector;
class MapWidget;


class WebView: public QWebView{
    Q_OBJECT
public:
    WebView(QString homeUrl, QWidget * pParent = NULL);
    WebView(QString homeUrl, MapWidget * pParentMapWidget);
    Q_SLOT void LoadUrl(QString url);
    Q_SLOT void LoadHome();
    Q_SLOT void RefreshPage();

    void seeMe(){qDebug()<<"WebView here\n";}
    Q_SLOT void eval(QString);

    //Grab info from JS
    Q_INVOKABLE void recvFromJS(QString info);

    //Signal when coordinates are grabbed from JS
    Q_SIGNAL void coordRecvFromJS(QString coordFromJS);


    QWebFrame * getWebFrame();
    Q_SIGNAL void loaded();

    Q_SLOT void showWebInspector();

    QWidget * m_pDebugWidget;


protected:

    MapWidget * m_pMapWidget;
    QString m_HomeUrl;
    QString m_CurrentUrl;
    QWebFrame * m_pWebFrame;
    bool firstLoad;

    Q_SLOT void UpdateOnPageLoad(bool ok);

};

#endif // WEBVIEW_H
