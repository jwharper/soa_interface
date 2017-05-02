/****************************************************************************
** Meta object code from reading C++ file 'qsidepanelcontainer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tabwidget2/tabWidgetFiles/OldCode/qsidepanelcontainer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsidepanelcontainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QSidePanelContainer_t {
    QByteArrayData data[13];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSidePanelContainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSidePanelContainer_t qt_meta_stringdata_QSidePanelContainer = {
    {
QT_MOC_LITERAL(0, 0, 19), // "QSidePanelContainer"
QT_MOC_LITERAL(1, 20, 16), // "SelectionChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 11), // "QSidePanel*"
QT_MOC_LITERAL(4, 50, 10), // "PanelAdded"
QT_MOC_LITERAL(5, 61, 6), // "pPanel"
QT_MOC_LITERAL(6, 68, 10), // "SortPanels"
QT_MOC_LITERAL(7, 79, 6), // "method"
QT_MOC_LITERAL(8, 86, 11), // "PanelPinned"
QT_MOC_LITERAL(9, 98, 6), // "pinned"
QT_MOC_LITERAL(10, 105, 17), // "SetPanelSelection"
QT_MOC_LITERAL(11, 123, 14), // "pSelectedPanel"
QT_MOC_LITERAL(12, 138, 12) // "PanelClicked"

    },
    "QSidePanelContainer\0SelectionChanged\0"
    "\0QSidePanel*\0PanelAdded\0pPanel\0"
    "SortPanels\0method\0PanelPinned\0pinned\0"
    "SetPanelSelection\0pSelectedPanel\0"
    "PanelClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSidePanelContainer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   60,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x2a /* Public | MethodCloned */,
       8,    1,   64,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,
      10,    0,   70,    2, 0x2a /* Public | MethodCloned */,
      12,    0,   71,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, 0x80000000 | 3,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSidePanelContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSidePanelContainer *_t = static_cast<QSidePanelContainer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SelectionChanged((*reinterpret_cast< QSidePanel*(*)>(_a[1]))); break;
        case 1: _t->PanelAdded((*reinterpret_cast< QSidePanel*(*)>(_a[1]))); break;
        case 2: _t->SortPanels((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SortPanels(); break;
        case 4: _t->PanelPinned((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->SetPanelSelection((*reinterpret_cast< QSidePanel*(*)>(_a[1]))); break;
        case 6: _t->SetPanelSelection(); break;
        case 7: _t->PanelClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QSidePanelContainer::*_t)(QSidePanel * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSidePanelContainer::SelectionChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QSidePanelContainer::*_t)(QSidePanel * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSidePanelContainer::PanelAdded)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject QSidePanelContainer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QSidePanelContainer.data,
      qt_meta_data_QSidePanelContainer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSidePanelContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSidePanelContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSidePanelContainer.stringdata0))
        return static_cast<void*>(const_cast< QSidePanelContainer*>(this));
    return QWidget::qt_metacast(_clname);
}

int QSidePanelContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QSidePanelContainer::SelectionChanged(QSidePanel * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSidePanelContainer::PanelAdded(QSidePanel * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
