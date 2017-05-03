/****************************************************************************
** Meta object code from reading C++ file 'logicwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../blarg2/logicwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logicwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LogicWidget_t {
    QByteArrayData data[29];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogicWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogicWidget_t qt_meta_stringdata_LogicWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LogicWidget"
QT_MOC_LITERAL(1, 12, 10), // "commitTask"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "taskInfo*"
QT_MOC_LITERAL(4, 34, 5), // "tInfo"
QT_MOC_LITERAL(5, 40, 17), // "actuallySendCoord"
QT_MOC_LITERAL(6, 58, 6), // "coords"
QT_MOC_LITERAL(7, 65, 7), // "newData"
QT_MOC_LITERAL(8, 73, 9), // "actorData"
QT_MOC_LITERAL(9, 83, 6), // "actor*"
QT_MOC_LITERAL(10, 90, 6), // "pActor"
QT_MOC_LITERAL(11, 97, 8), // "siteData"
QT_MOC_LITERAL(12, 106, 5), // "site*"
QT_MOC_LITERAL(13, 112, 5), // "pSite"
QT_MOC_LITERAL(14, 118, 15), // "removeWaypoints"
QT_MOC_LITERAL(15, 134, 7), // "actorID"
QT_MOC_LITERAL(16, 142, 7), // "endTask"
QT_MOC_LITERAL(17, 150, 2), // "id"
QT_MOC_LITERAL(18, 153, 5), // "debug"
QT_MOC_LITERAL(19, 159, 3), // "str"
QT_MOC_LITERAL(20, 163, 14), // "enableTaskDraw"
QT_MOC_LITERAL(21, 178, 9), // "taskShape"
QT_MOC_LITERAL(22, 188, 9), // "taskColor"
QT_MOC_LITERAL(23, 198, 9), // "sendCoord"
QT_MOC_LITERAL(24, 208, 13), // "getBeliefInfo"
QT_MOC_LITERAL(25, 222, 13), // "debuggingFunc"
QT_MOC_LITERAL(26, 236, 7), // "taskSOA"
QT_MOC_LITERAL(27, 244, 13), // "tasksForVideo"
QT_MOC_LITERAL(28, 258, 22) // "checkWaypointsProgress"

    },
    "LogicWidget\0commitTask\0\0taskInfo*\0"
    "tInfo\0actuallySendCoord\0coords\0newData\0"
    "actorData\0actor*\0pActor\0siteData\0site*\0"
    "pSite\0removeWaypoints\0actorID\0endTask\0"
    "id\0debug\0str\0enableTaskDraw\0taskShape\0"
    "taskColor\0sendCoord\0getBeliefInfo\0"
    "debuggingFunc\0taskSOA\0tasksForVideo\0"
    "checkWaypointsProgress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogicWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       5,    1,   92,    2, 0x06 /* Public */,
       7,    1,   95,    2, 0x06 /* Public */,
       8,    1,   98,    2, 0x06 /* Public */,
      11,    1,  101,    2, 0x06 /* Public */,
      14,    1,  104,    2, 0x06 /* Public */,
      16,    1,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,  110,    2, 0x0a /* Public */,
      20,    2,  113,    2, 0x0a /* Public */,
      23,    1,  118,    2, 0x0a /* Public */,
      24,    0,  121,    2, 0x0a /* Public */,
      25,    0,  122,    2, 0x0a /* Public */,
      26,    1,  123,    2, 0x0a /* Public */,
      27,    1,  126,    2, 0x0a /* Public */,
      28,    1,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   21,   22,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void LogicWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogicWidget *_t = static_cast<LogicWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->commitTask((*reinterpret_cast< taskInfo*(*)>(_a[1]))); break;
        case 1: _t->actuallySendCoord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->newData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->actorData((*reinterpret_cast< actor*(*)>(_a[1]))); break;
        case 4: _t->siteData((*reinterpret_cast< site*(*)>(_a[1]))); break;
        case 5: _t->removeWaypoints((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->endTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->debug((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->enableTaskDraw((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->sendCoord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->getBeliefInfo(); break;
        case 11: _t->debuggingFunc(); break;
        case 12: _t->taskSOA((*reinterpret_cast< taskInfo*(*)>(_a[1]))); break;
        case 13: _t->tasksForVideo((*reinterpret_cast< taskInfo*(*)>(_a[1]))); break;
        case 14: _t->checkWaypointsProgress((*reinterpret_cast< taskInfo*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LogicWidget::*_t)(taskInfo * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogicWidget::commitTask)) {
                *result = 0;
            }
        }
        {
            typedef void (LogicWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogicWidget::actuallySendCoord)) {
                *result = 1;
            }
        }
        {
            typedef void (LogicWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogicWidget::newData)) {
                *result = 2;
            }
        }
        {
            typedef void (LogicWidget::*_t)(actor * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogicWidget::actorData)) {
                *result = 3;
            }
        }
        {
            typedef void (LogicWidget::*_t)(site * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogicWidget::siteData)) {
                *result = 4;
            }
        }
        {
            typedef void (LogicWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogicWidget::removeWaypoints)) {
                *result = 5;
            }
        }
        {
            typedef void (LogicWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogicWidget::endTask)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject LogicWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LogicWidget.data,
      qt_meta_data_LogicWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LogicWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogicWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LogicWidget.stringdata0))
        return static_cast<void*>(const_cast< LogicWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LogicWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void LogicWidget::commitTask(taskInfo * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LogicWidget::actuallySendCoord(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LogicWidget::newData(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LogicWidget::actorData(actor * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LogicWidget::siteData(site * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void LogicWidget::removeWaypoints(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void LogicWidget::endTask(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
