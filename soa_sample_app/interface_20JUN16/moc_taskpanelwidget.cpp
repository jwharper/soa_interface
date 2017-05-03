/****************************************************************************
** Meta object code from reading C++ file 'taskpanelwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../taskpanelwidget/taskpanelwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'taskpanelwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TaskPanelWidget_t {
    QByteArrayData data[25];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TaskPanelWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TaskPanelWidget_t qt_meta_stringdata_TaskPanelWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TaskPanelWidget"
QT_MOC_LITERAL(1, 16, 17), // "replacedMapButton"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 12), // "sendTaskInfo"
QT_MOC_LITERAL(4, 48, 9), // "taskInfo*"
QT_MOC_LITERAL(5, 58, 9), // "pTaskInfo"
QT_MOC_LITERAL(6, 68, 17), // "taskShapeAndColor"
QT_MOC_LITERAL(7, 86, 9), // "taskShape"
QT_MOC_LITERAL(8, 96, 9), // "taskColor"
QT_MOC_LITERAL(9, 106, 14), // "actAsMapButton"
QT_MOC_LITERAL(10, 121, 8), // "resetAll"
QT_MOC_LITERAL(11, 130, 6), // "commit"
QT_MOC_LITERAL(12, 137, 5), // "reset"
QT_MOC_LITERAL(13, 143, 6), // "cancel"
QT_MOC_LITERAL(14, 150, 11), // "tieToSlider"
QT_MOC_LITERAL(15, 162, 23), // "enableTaskAreaSelection"
QT_MOC_LITERAL(16, 186, 9), // "updatePts"
QT_MOC_LITERAL(17, 196, 3), // "pts"
QT_MOC_LITERAL(18, 200, 10), // "createTask"
QT_MOC_LITERAL(19, 211, 14), // "mapCoordFromJS"
QT_MOC_LITERAL(20, 226, 10), // "locationJS"
QT_MOC_LITERAL(21, 237, 12), // "taskSelected"
QT_MOC_LITERAL(22, 250, 15), // "enableCommitBtn"
QT_MOC_LITERAL(23, 266, 11), // "sliderMoved"
QT_MOC_LITERAL(24, 278, 4) // "bots"

    },
    "TaskPanelWidget\0replacedMapButton\0\0"
    "sendTaskInfo\0taskInfo*\0pTaskInfo\0"
    "taskShapeAndColor\0taskShape\0taskColor\0"
    "actAsMapButton\0resetAll\0commit\0reset\0"
    "cancel\0tieToSlider\0enableTaskAreaSelection\0"
    "updatePts\0pts\0createTask\0mapCoordFromJS\0"
    "locationJS\0taskSelected\0enableCommitBtn\0"
    "sliderMoved\0bots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaskPanelWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    1,   95,    2, 0x06 /* Public */,
       6,    2,   98,    2, 0x06 /* Public */,
       9,    0,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  104,    2, 0x0a /* Public */,
      11,    0,  105,    2, 0x0a /* Public */,
      12,    0,  106,    2, 0x0a /* Public */,
      13,    0,  107,    2, 0x0a /* Public */,
      14,    0,  108,    2, 0x0a /* Public */,
      15,    0,  109,    2, 0x0a /* Public */,
      16,    1,  110,    2, 0x0a /* Public */,
      18,    0,  113,    2, 0x0a /* Public */,
      19,    1,  114,    2, 0x0a /* Public */,
      21,    0,  117,    2, 0x0a /* Public */,
      22,    0,  118,    2, 0x0a /* Public */,
      23,    1,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,

       0        // eod
};

void TaskPanelWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TaskPanelWidget *_t = static_cast<TaskPanelWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replacedMapButton(); break;
        case 1: _t->sendTaskInfo((*reinterpret_cast< taskInfo*(*)>(_a[1]))); break;
        case 2: _t->taskShapeAndColor((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->actAsMapButton(); break;
        case 4: _t->resetAll(); break;
        case 5: _t->commit(); break;
        case 6: _t->reset(); break;
        case 7: _t->cancel(); break;
        case 8: _t->tieToSlider(); break;
        case 9: _t->enableTaskAreaSelection(); break;
        case 10: _t->updatePts((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->createTask(); break;
        case 12: _t->mapCoordFromJS((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->taskSelected(); break;
        case 14: _t->enableCommitBtn(); break;
        case 15: _t->sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TaskPanelWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TaskPanelWidget::replacedMapButton)) {
                *result = 0;
            }
        }
        {
            typedef void (TaskPanelWidget::*_t)(taskInfo * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TaskPanelWidget::sendTaskInfo)) {
                *result = 1;
            }
        }
        {
            typedef void (TaskPanelWidget::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TaskPanelWidget::taskShapeAndColor)) {
                *result = 2;
            }
        }
        {
            typedef void (TaskPanelWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TaskPanelWidget::actAsMapButton)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject TaskPanelWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TaskPanelWidget.data,
      qt_meta_data_TaskPanelWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TaskPanelWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaskPanelWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TaskPanelWidget.stringdata0))
        return static_cast<void*>(const_cast< TaskPanelWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int TaskPanelWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void TaskPanelWidget::replacedMapButton()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TaskPanelWidget::sendTaskInfo(taskInfo * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TaskPanelWidget::taskShapeAndColor(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TaskPanelWidget::actAsMapButton()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
