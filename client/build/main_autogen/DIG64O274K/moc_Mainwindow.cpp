/****************************************************************************
** Meta object code from reading C++ file 'Mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "inc/Mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainwindow_t {
    QByteArrayData data[13];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainwindow_t qt_meta_stringdata_mainwindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "mainwindow"
QT_MOC_LITERAL(1, 11, 10), // "QPu0_slots"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "QPu1_slots"
QT_MOC_LITERAL(4, 34, 10), // "QPu2_slots"
QT_MOC_LITERAL(5, 45, 11), // "QPu20_slots"
QT_MOC_LITERAL(6, 57, 10), // "QPu3_slots"
QT_MOC_LITERAL(7, 68, 10), // "QPu4_slots"
QT_MOC_LITERAL(8, 79, 10), // "QPu5_slots"
QT_MOC_LITERAL(9, 90, 10), // "QPu6_slots"
QT_MOC_LITERAL(10, 101, 10), // "QPu7_slots"
QT_MOC_LITERAL(11, 112, 10), // "QPu8_slots"
QT_MOC_LITERAL(12, 123, 10) // "QPu9_slots"

    },
    "mainwindow\0QPu0_slots\0\0QPu1_slots\0"
    "QPu2_slots\0QPu20_slots\0QPu3_slots\0"
    "QPu4_slots\0QPu5_slots\0QPu6_slots\0"
    "QPu7_slots\0QPu8_slots\0QPu9_slots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainwindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->QPu0_slots(); break;
        case 1: _t->QPu1_slots(); break;
        case 2: _t->QPu2_slots(); break;
        case 3: _t->QPu20_slots(); break;
        case 4: _t->QPu3_slots(); break;
        case 5: _t->QPu4_slots(); break;
        case 6: _t->QPu5_slots(); break;
        case 7: _t->QPu6_slots(); break;
        case 8: _t->QPu7_slots(); break;
        case 9: _t->QPu8_slots(); break;
        case 10: _t->QPu9_slots(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject mainwindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_mainwindow.data,
    qt_meta_data_mainwindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainwindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
