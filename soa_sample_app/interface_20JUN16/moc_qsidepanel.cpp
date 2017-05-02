/****************************************************************************
** Meta object code from reading C++ file 'qsidepanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tabwidget2/tabWidgetFiles/OldCode/qsidepanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsidepanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_runningBar_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_runningBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_runningBar_t qt_meta_stringdata_runningBar = {
    {
QT_MOC_LITERAL(0, 0, 10) // "runningBar"

    },
    "runningBar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_runningBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void runningBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject runningBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_runningBar.data,
      qt_meta_data_runningBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *runningBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *runningBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_runningBar.stringdata0))
        return static_cast<void*>(const_cast< runningBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int runningBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_QSidePanel_t {
    QByteArrayData data[30];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSidePanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSidePanel_t qt_meta_stringdata_QSidePanel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QSidePanel"
QT_MOC_LITERAL(1, 11, 7), // "Clicked"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "Pressed"
QT_MOC_LITERAL(4, 28, 8), // "Released"
QT_MOC_LITERAL(5, 37, 13), // "DoubleClicked"
QT_MOC_LITERAL(6, 51, 16), // "SelectionChanged"
QT_MOC_LITERAL(7, 68, 5), // "state"
QT_MOC_LITERAL(8, 74, 13), // "StatusChanged"
QT_MOC_LITERAL(9, 88, 6), // "Pinned"
QT_MOC_LITERAL(10, 95, 6), // "pinned"
QT_MOC_LITERAL(11, 102, 15), // "ResortRequested"
QT_MOC_LITERAL(12, 118, 26), // "ContextMenuActionTriggered"
QT_MOC_LITERAL(13, 145, 8), // "QAction*"
QT_MOC_LITERAL(14, 154, 7), // "pAction"
QT_MOC_LITERAL(15, 162, 15), // "ChangeSelection"
QT_MOC_LITERAL(16, 178, 12), // "ChangePinned"
QT_MOC_LITERAL(17, 191, 10), // "PinClicked"
QT_MOC_LITERAL(18, 202, 10), // "ChangeMode"
QT_MOC_LITERAL(19, 213, 9), // "PanelMode"
QT_MOC_LITERAL(20, 223, 4), // "mode"
QT_MOC_LITERAL(21, 228, 6), // "resort"
QT_MOC_LITERAL(22, 235, 12), // "ChangeStatus"
QT_MOC_LITERAL(23, 248, 11), // "PanelStatus"
QT_MOC_LITERAL(24, 260, 6), // "status"
QT_MOC_LITERAL(25, 267, 18), // "ChangeFailingBrush"
QT_MOC_LITERAL(26, 286, 5), // "brush"
QT_MOC_LITERAL(27, 292, 17), // "ChangeFailedBrush"
QT_MOC_LITERAL(28, 310, 12), // "DecreaseMode"
QT_MOC_LITERAL(29, 323, 12) // "IncreaseMode"

    },
    "QSidePanel\0Clicked\0\0Pressed\0Released\0"
    "DoubleClicked\0SelectionChanged\0state\0"
    "StatusChanged\0Pinned\0pinned\0ResortRequested\0"
    "ContextMenuActionTriggered\0QAction*\0"
    "pAction\0ChangeSelection\0ChangePinned\0"
    "PinClicked\0ChangeMode\0PanelMode\0mode\0"
    "resort\0ChangeStatus\0PanelStatus\0status\0"
    "ChangeFailingBrush\0brush\0ChangeFailedBrush\0"
    "DecreaseMode\0IncreaseMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSidePanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,
       3,    0,  115,    2, 0x06 /* Public */,
       4,    0,  116,    2, 0x06 /* Public */,
       5,    0,  117,    2, 0x06 /* Public */,
       6,    1,  118,    2, 0x06 /* Public */,
       8,    0,  121,    2, 0x06 /* Public */,
       9,    1,  122,    2, 0x06 /* Public */,
      11,    0,  125,    2, 0x06 /* Public */,
      12,    1,  126,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  129,    2, 0x0a /* Public */,
      16,    1,  132,    2, 0x0a /* Public */,
      17,    0,  135,    2, 0x0a /* Public */,
      18,    2,  136,    2, 0x0a /* Public */,
      18,    1,  141,    2, 0x2a /* Public | MethodCloned */,
      22,    2,  144,    2, 0x0a /* Public */,
      22,    1,  149,    2, 0x2a /* Public | MethodCloned */,
      25,    1,  152,    2, 0x0a /* Public */,
      27,    1,  155,    2, 0x0a /* Public */,
      28,    0,  158,    2, 0x0a /* Public */,
      29,    0,  159,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, QMetaType::Bool,   20,   21,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 23, QMetaType::Bool,   24,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, QMetaType::QBrush,   26,
    QMetaType::Void, QMetaType::QBrush,   26,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSidePanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSidePanel *_t = static_cast<QSidePanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Clicked(); break;
        case 1: _t->Pressed(); break;
        case 2: _t->Released(); break;
        case 3: _t->DoubleClicked(); break;
        case 4: _t->SelectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->StatusChanged(); break;
        case 6: _t->Pinned((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->ResortRequested(); break;
        case 8: _t->ContextMenuActionTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 9: _t->ChangeSelection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->ChangePinned((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->PinClicked(); break;
        case 12: _t->ChangeMode((*reinterpret_cast< PanelMode(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->ChangeMode((*reinterpret_cast< PanelMode(*)>(_a[1]))); break;
        case 14: _t->ChangeStatus((*reinterpret_cast< PanelStatus(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 15: _t->ChangeStatus((*reinterpret_cast< PanelStatus(*)>(_a[1]))); break;
        case 16: _t->ChangeFailingBrush((*reinterpret_cast< QBrush(*)>(_a[1]))); break;
        case 17: _t->ChangeFailedBrush((*reinterpret_cast< QBrush(*)>(_a[1]))); break;
        case 18: _t->DecreaseMode(); break;
        case 19: _t->IncreaseMode(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QSidePanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSidePanel::Clicked)) {
                *result = 0;
            }
        }
        {
            typedef void (QSidePanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSidePanel::Pressed)) {
                *result = 1;
            }
        }
        {
            typedef void (QSidePanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSidePanel::Released)) {
                *result = 2;
            }
        }
        {
            typedef void (QSidePanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSidePanel::DoubleClicked)) {
                *result = 3;
            }
        }
        {
            typedef void (QSidePanel::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSidePanel::SelectionChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (QSidePanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSidePanel::StatusChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (QSidePanel::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSidePanel::Pinned)) {
                *result = 6;
            }
        }
        {
            typedef void (QSidePanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSidePanel::ResortRequested)) {
                *result = 7;
            }
        }
        {
            typedef void (QSidePanel::*_t)(QAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSidePanel::ContextMenuActionTriggered)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject QSidePanel::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_QSidePanel.data,
      qt_meta_data_QSidePanel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSidePanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSidePanel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSidePanel.stringdata0))
        return static_cast<void*>(const_cast< QSidePanel*>(this));
    return QFrame::qt_metacast(_clname);
}

int QSidePanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void QSidePanel::Clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QSidePanel::Pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QSidePanel::Released()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void QSidePanel::DoubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void QSidePanel::SelectionChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QSidePanel::StatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void QSidePanel::Pinned(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QSidePanel::ResortRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void QSidePanel::ContextMenuActionTriggered(QAction * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
