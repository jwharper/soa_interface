/****************************************************************************
** Meta object code from reading C++ file 'webview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../blarg2/mapWidget/webview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WebView_t {
    QByteArrayData data[15];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebView_t qt_meta_stringdata_WebView = {
    {
QT_MOC_LITERAL(0, 0, 7), // "WebView"
QT_MOC_LITERAL(1, 8, 15), // "coordRecvFromJS"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "coordFromJS"
QT_MOC_LITERAL(4, 37, 6), // "loaded"
QT_MOC_LITERAL(5, 44, 7), // "LoadUrl"
QT_MOC_LITERAL(6, 52, 3), // "url"
QT_MOC_LITERAL(7, 56, 8), // "LoadHome"
QT_MOC_LITERAL(8, 65, 11), // "RefreshPage"
QT_MOC_LITERAL(9, 77, 4), // "eval"
QT_MOC_LITERAL(10, 82, 16), // "showWebInspector"
QT_MOC_LITERAL(11, 99, 16), // "UpdateOnPageLoad"
QT_MOC_LITERAL(12, 116, 2), // "ok"
QT_MOC_LITERAL(13, 119, 10), // "recvFromJS"
QT_MOC_LITERAL(14, 130, 4) // "info"

    },
    "WebView\0coordRecvFromJS\0\0coordFromJS\0"
    "loaded\0LoadUrl\0url\0LoadHome\0RefreshPage\0"
    "eval\0showWebInspector\0UpdateOnPageLoad\0"
    "ok\0recvFromJS\0info"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   63,    2, 0x0a /* Public */,
       7,    0,   66,    2, 0x0a /* Public */,
       8,    0,   67,    2, 0x0a /* Public */,
       9,    1,   68,    2, 0x0a /* Public */,
      10,    0,   71,    2, 0x0a /* Public */,
      11,    1,   72,    2, 0x09 /* Protected */,

 // methods: name, argc, parameters, tag, flags
      13,    1,   75,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   14,

       0        // eod
};

void WebView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebView *_t = static_cast<WebView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->coordRecvFromJS((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->loaded(); break;
        case 2: _t->LoadUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->LoadHome(); break;
        case 4: _t->RefreshPage(); break;
        case 5: _t->eval((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->showWebInspector(); break;
        case 7: _t->UpdateOnPageLoad((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->recvFromJS((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WebView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebView::coordRecvFromJS)) {
                *result = 0;
            }
        }
        {
            typedef void (WebView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebView::loaded)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject WebView::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_WebView.data,
      qt_meta_data_WebView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WebView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WebView.stringdata0))
        return static_cast<void*>(const_cast< WebView*>(this));
    return QWebView::qt_metacast(_clname);
}

int WebView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void WebView::coordRecvFromJS(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WebView::loaded()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
