/****************************************************************************
** Meta object code from reading C++ file 'mapwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../blarg2/mapWidget/mapwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MapWidget_t {
    QByteArrayData data[24];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MapWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MapWidget_t qt_meta_stringdata_MapWidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MapWidget"
QT_MOC_LITERAL(1, 10, 14), // "ManifestsReady"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "endTask"
QT_MOC_LITERAL(4, 34, 2), // "id"
QT_MOC_LITERAL(5, 37, 23), // "ShowWebInspectorRequest"
QT_MOC_LITERAL(6, 61, 8), // "CenterOn"
QT_MOC_LITERAL(7, 70, 6), // "latLng"
QT_MOC_LITERAL(8, 77, 12), // "IncomingData"
QT_MOC_LITERAL(9, 90, 11), // "placeholder"
QT_MOC_LITERAL(10, 102, 10), // "commitTask"
QT_MOC_LITERAL(11, 113, 9), // "taskInfo*"
QT_MOC_LITERAL(12, 123, 5), // "tInfo"
QT_MOC_LITERAL(13, 129, 11), // "updateActor"
QT_MOC_LITERAL(14, 141, 6), // "actor*"
QT_MOC_LITERAL(15, 148, 6), // "pActor"
QT_MOC_LITERAL(16, 155, 10), // "updateSite"
QT_MOC_LITERAL(17, 166, 5), // "site*"
QT_MOC_LITERAL(18, 172, 5), // "pSite"
QT_MOC_LITERAL(19, 178, 12), // "OutgoingData"
QT_MOC_LITERAL(20, 191, 18), // "requestPlaceholder"
QT_MOC_LITERAL(21, 210, 6), // "ZoomIn"
QT_MOC_LITERAL(22, 217, 7), // "ZoomOut"
QT_MOC_LITERAL(23, 225, 9) // "ZoomReset"

    },
    "MapWidget\0ManifestsReady\0\0endTask\0id\0"
    "ShowWebInspectorRequest\0CenterOn\0"
    "latLng\0IncomingData\0placeholder\0"
    "commitTask\0taskInfo*\0tInfo\0updateActor\0"
    "actor*\0pActor\0updateSite\0site*\0pSite\0"
    "OutgoingData\0requestPlaceholder\0ZoomIn\0"
    "ZoomOut\0ZoomReset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,
       5,    0,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   79,    2, 0x0a /* Public */,
       8,    1,   82,    2, 0x0a /* Public */,
      10,    1,   85,    2, 0x0a /* Public */,
      13,    1,   88,    2, 0x0a /* Public */,
      16,    1,   91,    2, 0x0a /* Public */,
      19,    1,   94,    2, 0x0a /* Public */,
      21,    0,   97,    2, 0x0a /* Public */,
      22,    0,   98,    2, 0x0a /* Public */,
      23,    0,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::QString, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MapWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MapWidget *_t = static_cast<MapWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ManifestsReady(); break;
        case 1: _t->endTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ShowWebInspectorRequest(); break;
        case 3: _t->CenterOn((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->IncomingData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->commitTask((*reinterpret_cast< taskInfo*(*)>(_a[1]))); break;
        case 6: _t->updateActor((*reinterpret_cast< actor*(*)>(_a[1]))); break;
        case 7: _t->updateSite((*reinterpret_cast< site*(*)>(_a[1]))); break;
        case 8: { QString _r = _t->OutgoingData((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: _t->ZoomIn(); break;
        case 10: _t->ZoomOut(); break;
        case 11: _t->ZoomReset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MapWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MapWidget::ManifestsReady)) {
                *result = 0;
            }
        }
        {
            typedef void (MapWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MapWidget::endTask)) {
                *result = 1;
            }
        }
        {
            typedef void (MapWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MapWidget::ShowWebInspectorRequest)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MapWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MapWidget.data,
      qt_meta_data_MapWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MapWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MapWidget.stringdata0))
        return static_cast<void*>(const_cast< MapWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MapWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MapWidget::ManifestsReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MapWidget::endTask(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MapWidget::ShowWebInspectorRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
