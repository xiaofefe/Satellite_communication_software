/****************************************************************************
** Meta object code from reading C++ file 'navlistview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../navlistview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navlistview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NavDelegate_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NavDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NavDelegate_t qt_meta_stringdata_NavDelegate = {
    {
QT_MOC_LITERAL(0, 0, 11) // "NavDelegate"

    },
    "NavDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NavDelegate[] = {

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

void NavDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject NavDelegate::staticMetaObject = {
    { &QStyledItemDelegate::staticMetaObject, qt_meta_stringdata_NavDelegate.data,
      qt_meta_data_NavDelegate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NavDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NavDelegate.stringdata0))
        return static_cast<void*>(const_cast< NavDelegate*>(this));
    return QStyledItemDelegate::qt_metacast(_clname);
}

int NavDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_NavModel_t {
    QByteArrayData data[8];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NavModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NavModel_t qt_meta_stringdata_NavModel = {
    {
QT_MOC_LITERAL(0, 0, 8), // "NavModel"
QT_MOC_LITERAL(1, 9, 8), // "readData"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "path"
QT_MOC_LITERAL(4, 24, 7), // "setData"
QT_MOC_LITERAL(5, 32, 8), // "listItem"
QT_MOC_LITERAL(6, 41, 8), // "collapse"
QT_MOC_LITERAL(7, 50, 5) // "index"

    },
    "NavModel\0readData\0\0path\0setData\0"
    "listItem\0collapse\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NavModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QStringList,    5,
    QMetaType::Void, QMetaType::QModelIndex,    7,

       0        // eod
};

void NavModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NavModel *_t = static_cast<NavModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setData((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: _t->collapse((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NavModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_NavModel.data,
      qt_meta_data_NavModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NavModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NavModel.stringdata0))
        return static_cast<void*>(const_cast< NavModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int NavModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_NavListView_t {
    QByteArrayData data[34];
    char stringdata0[444];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NavListView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NavListView_t qt_meta_stringdata_NavListView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NavListView"
QT_MOC_LITERAL(1, 12, 8), // "readData"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "xmlPath"
QT_MOC_LITERAL(4, 30, 7), // "setData"
QT_MOC_LITERAL(5, 38, 8), // "listItem"
QT_MOC_LITERAL(6, 47, 14), // "setInfoVisible"
QT_MOC_LITERAL(7, 62, 11), // "infoVisible"
QT_MOC_LITERAL(8, 74, 14), // "setLineVisible"
QT_MOC_LITERAL(9, 89, 11), // "lineVisible"
QT_MOC_LITERAL(10, 101, 13), // "setIcoColorBg"
QT_MOC_LITERAL(11, 115, 10), // "icoColorBg"
QT_MOC_LITERAL(12, 126, 11), // "setIcoStyle"
QT_MOC_LITERAL(13, 138, 8), // "IcoStyle"
QT_MOC_LITERAL(14, 147, 8), // "icoStyle"
QT_MOC_LITERAL(15, 156, 11), // "setFoldMode"
QT_MOC_LITERAL(16, 168, 8), // "FoldMode"
QT_MOC_LITERAL(17, 177, 8), // "foldMode"
QT_MOC_LITERAL(18, 186, 12), // "setLineColor"
QT_MOC_LITERAL(19, 199, 9), // "lineColor"
QT_MOC_LITERAL(20, 209, 16), // "setBgNormalColor"
QT_MOC_LITERAL(21, 226, 13), // "bgNormalColor"
QT_MOC_LITERAL(22, 240, 18), // "setBgSelectedColor"
QT_MOC_LITERAL(23, 259, 15), // "bgSelectedColor"
QT_MOC_LITERAL(24, 275, 15), // "setBgHoverColor"
QT_MOC_LITERAL(25, 291, 12), // "bgHoverColor"
QT_MOC_LITERAL(26, 304, 18), // "setTextNormalColor"
QT_MOC_LITERAL(27, 323, 15), // "textNormalColor"
QT_MOC_LITERAL(28, 339, 20), // "setTextSelectedColor"
QT_MOC_LITERAL(29, 360, 17), // "textSelectedColor"
QT_MOC_LITERAL(30, 378, 17), // "setTextHoverColor"
QT_MOC_LITERAL(31, 396, 14), // "textHoverColor"
QT_MOC_LITERAL(32, 411, 14), // "IcoStyle_Cross"
QT_MOC_LITERAL(33, 426, 17) // "IcoStyle_Triangle"

    },
    "NavListView\0readData\0\0xmlPath\0setData\0"
    "listItem\0setInfoVisible\0infoVisible\0"
    "setLineVisible\0lineVisible\0setIcoColorBg\0"
    "icoColorBg\0setIcoStyle\0IcoStyle\0"
    "icoStyle\0setFoldMode\0FoldMode\0foldMode\0"
    "setLineColor\0lineColor\0setBgNormalColor\0"
    "bgNormalColor\0setBgSelectedColor\0"
    "bgSelectedColor\0setBgHoverColor\0"
    "bgHoverColor\0setTextNormalColor\0"
    "textNormalColor\0setTextSelectedColor\0"
    "textSelectedColor\0setTextHoverColor\0"
    "textHoverColor\0IcoStyle_Cross\0"
    "IcoStyle_Triangle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NavListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
      12,  126, // properties
       1,  162, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a /* Public */,
       4,    1,   87,    2, 0x0a /* Public */,
       6,    1,   90,    2, 0x0a /* Public */,
       8,    1,   93,    2, 0x0a /* Public */,
      10,    1,   96,    2, 0x0a /* Public */,
      12,    1,   99,    2, 0x0a /* Public */,
      15,    1,  102,    2, 0x0a /* Public */,
      18,    1,  105,    2, 0x0a /* Public */,
      20,    1,  108,    2, 0x0a /* Public */,
      22,    1,  111,    2, 0x0a /* Public */,
      24,    1,  114,    2, 0x0a /* Public */,
      26,    1,  117,    2, 0x0a /* Public */,
      28,    1,  120,    2, 0x0a /* Public */,
      30,    1,  123,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QStringList,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::QColor,   19,
    QMetaType::Void, QMetaType::QColor,   21,
    QMetaType::Void, QMetaType::QColor,   23,
    QMetaType::Void, QMetaType::QColor,   25,
    QMetaType::Void, QMetaType::QColor,   27,
    QMetaType::Void, QMetaType::QColor,   29,
    QMetaType::Void, QMetaType::QColor,   31,

 // properties: name, type, flags
       7, QMetaType::Bool, 0x00095103,
       9, QMetaType::Bool, 0x00095103,
      11, QMetaType::Bool, 0x00095103,
      14, 0x80000000 | 13, 0x0009510b,
      17, 0x80000000 | 16, 0x0009510b,
      19, QMetaType::QColor, 0x00095103,
      21, QMetaType::QColor, 0x00095103,
      23, QMetaType::QColor, 0x00095103,
      25, QMetaType::QColor, 0x00095103,
      27, QMetaType::QColor, 0x00095103,
      29, QMetaType::QColor, 0x00095103,
      31, QMetaType::QColor, 0x00095103,

 // enums: name, flags, count, data
      13, 0x0,    2,  166,

 // enum data: key, value
      32, uint(NavListView::IcoStyle_Cross),
      33, uint(NavListView::IcoStyle_Triangle),

       0        // eod
};

void NavListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NavListView *_t = static_cast<NavListView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setData((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: _t->setInfoVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setLineVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setIcoColorBg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setIcoStyle((*reinterpret_cast< const IcoStyle(*)>(_a[1]))); break;
        case 6: _t->setFoldMode((*reinterpret_cast< const FoldMode(*)>(_a[1]))); break;
        case 7: _t->setLineColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 8: _t->setBgNormalColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 9: _t->setBgSelectedColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 10: _t->setBgHoverColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 11: _t->setTextNormalColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 12: _t->setTextSelectedColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 13: _t->setTextHoverColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        NavListView *_t = static_cast<NavListView *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getInfoVisible(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getLineVisible(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getIcoColorBg(); break;
        case 3: *reinterpret_cast< IcoStyle*>(_v) = _t->getIcoStyle(); break;
        case 4: *reinterpret_cast< FoldMode*>(_v) = _t->getFoldMode(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->getLineColor(); break;
        case 6: *reinterpret_cast< QColor*>(_v) = _t->getBgNormalColor(); break;
        case 7: *reinterpret_cast< QColor*>(_v) = _t->getBgSelectedColor(); break;
        case 8: *reinterpret_cast< QColor*>(_v) = _t->getBgHoverColor(); break;
        case 9: *reinterpret_cast< QColor*>(_v) = _t->getTextNormalColor(); break;
        case 10: *reinterpret_cast< QColor*>(_v) = _t->getTextSelectedColor(); break;
        case 11: *reinterpret_cast< QColor*>(_v) = _t->getTextHoverColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        NavListView *_t = static_cast<NavListView *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setInfoVisible(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setLineVisible(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setIcoColorBg(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setIcoStyle(*reinterpret_cast< IcoStyle*>(_v)); break;
        case 4: _t->setFoldMode(*reinterpret_cast< FoldMode*>(_v)); break;
        case 5: _t->setLineColor(*reinterpret_cast< QColor*>(_v)); break;
        case 6: _t->setBgNormalColor(*reinterpret_cast< QColor*>(_v)); break;
        case 7: _t->setBgSelectedColor(*reinterpret_cast< QColor*>(_v)); break;
        case 8: _t->setBgHoverColor(*reinterpret_cast< QColor*>(_v)); break;
        case 9: _t->setTextNormalColor(*reinterpret_cast< QColor*>(_v)); break;
        case 10: _t->setTextSelectedColor(*reinterpret_cast< QColor*>(_v)); break;
        case 11: _t->setTextHoverColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject NavListView::staticMetaObject = {
    { &QListView::staticMetaObject, qt_meta_stringdata_NavListView.data,
      qt_meta_data_NavListView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NavListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavListView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NavListView.stringdata0))
        return static_cast<void*>(const_cast< NavListView*>(this));
    return QListView::qt_metacast(_clname);
}

int NavListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 12;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
