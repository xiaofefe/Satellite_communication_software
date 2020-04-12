/****************************************************************************
** Meta object code from reading C++ file 'inputdatawidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inputdatawidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inputdatawidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InputDataWidget_t {
    QByteArrayData data[11];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InputDataWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InputDataWidget_t qt_meta_stringdata_InputDataWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "InputDataWidget"
QT_MOC_LITERAL(1, 16, 17), // "TurntoFirstWindow"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "doSelectTaskName"
QT_MOC_LITERAL(4, 52, 15), // "doSelectCodeing"
QT_MOC_LITERAL(5, 68, 19), // "doSelectOpenOrClose"
QT_MOC_LITERAL(6, 88, 16), // "doSelectEncoding"
QT_MOC_LITERAL(7, 105, 15), // "doSelectLocking"
QT_MOC_LITERAL(8, 121, 16), // "doSelectRFSwitch"
QT_MOC_LITERAL(9, 138, 33), // "doSelectradiofrequencySuppres..."
QT_MOC_LITERAL(10, 172, 19) // "doSelectonlineState"

    },
    "InputDataWidget\0TurntoFirstWindow\0\0"
    "doSelectTaskName\0doSelectCodeing\0"
    "doSelectOpenOrClose\0doSelectEncoding\0"
    "doSelectLocking\0doSelectRFSwitch\0"
    "doSelectradiofrequencySuppression\0"
    "doSelectonlineState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InputDataWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   60,    2, 0x0a /* Public */,
       4,    1,   63,    2, 0x0a /* Public */,
       5,    1,   66,    2, 0x0a /* Public */,
       6,    1,   69,    2, 0x0a /* Public */,
       7,    1,   72,    2, 0x0a /* Public */,
       8,    1,   75,    2, 0x0a /* Public */,
       9,    1,   78,    2, 0x0a /* Public */,
      10,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void InputDataWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InputDataWidget *_t = static_cast<InputDataWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TurntoFirstWindow(); break;
        case 1: _t->doSelectTaskName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->doSelectCodeing((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->doSelectOpenOrClose((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->doSelectEncoding((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->doSelectLocking((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->doSelectRFSwitch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->doSelectradiofrequencySuppression((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->doSelectonlineState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (InputDataWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InputDataWidget::TurntoFirstWindow)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject InputDataWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InputDataWidget.data,
      qt_meta_data_InputDataWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InputDataWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InputDataWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InputDataWidget.stringdata0))
        return static_cast<void*>(const_cast< InputDataWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int InputDataWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void InputDataWidget::TurntoFirstWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
