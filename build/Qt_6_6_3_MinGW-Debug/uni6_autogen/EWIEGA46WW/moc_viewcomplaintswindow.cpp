/****************************************************************************
** Meta object code from reading C++ file 'viewcomplaintswindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../viewcomplaintswindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewcomplaintswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSviewcomplaintswindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSviewcomplaintswindowENDCLASS = QtMocHelpers::stringData(
    "viewcomplaintswindow",
    "on_refreshButton_clicked",
    "",
    "on_statusFilterComboBox_currentIndexChanged",
    "index",
    "on_viewDetailButton_clicked",
    "on_updateStatusButton_clicked",
    "on_addTestDataButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSviewcomplaintswindowENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[21];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[44];
    char stringdata4[6];
    char stringdata5[28];
    char stringdata6[30];
    char stringdata7[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSviewcomplaintswindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSviewcomplaintswindowENDCLASS_t qt_meta_stringdata_CLASSviewcomplaintswindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "viewcomplaintswindow"
        QT_MOC_LITERAL(21, 24),  // "on_refreshButton_clicked"
        QT_MOC_LITERAL(46, 0),  // ""
        QT_MOC_LITERAL(47, 43),  // "on_statusFilterComboBox_curre..."
        QT_MOC_LITERAL(91, 5),  // "index"
        QT_MOC_LITERAL(97, 27),  // "on_viewDetailButton_clicked"
        QT_MOC_LITERAL(125, 29),  // "on_updateStatusButton_clicked"
        QT_MOC_LITERAL(155, 28)   // "on_addTestDataButton_clicked"
    },
    "viewcomplaintswindow",
    "on_refreshButton_clicked",
    "",
    "on_statusFilterComboBox_currentIndexChanged",
    "index",
    "on_viewDetailButton_clicked",
    "on_updateStatusButton_clicked",
    "on_addTestDataButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSviewcomplaintswindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    1,   45,    2, 0x08,    2 /* Private */,
       5,    0,   48,    2, 0x08,    4 /* Private */,
       6,    0,   49,    2, 0x08,    5 /* Private */,
       7,    0,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject viewcomplaintswindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSviewcomplaintswindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSviewcomplaintswindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSviewcomplaintswindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<viewcomplaintswindow, std::true_type>,
        // method 'on_refreshButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_statusFilterComboBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_viewDetailButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_updateStatusButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addTestDataButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void viewcomplaintswindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<viewcomplaintswindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_refreshButton_clicked(); break;
        case 1: _t->on_statusFilterComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_viewDetailButton_clicked(); break;
        case 3: _t->on_updateStatusButton_clicked(); break;
        case 4: _t->on_addTestDataButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *viewcomplaintswindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *viewcomplaintswindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSviewcomplaintswindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int viewcomplaintswindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
