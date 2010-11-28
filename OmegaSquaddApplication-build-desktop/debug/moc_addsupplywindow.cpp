/****************************************************************************
** Meta object code from reading C++ file 'addsupplywindow.h'
**
** Created: Sun Nov 28 17:17:58 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OmegaSquaddApplication/addsupplywindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addsupplywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddSupplyWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      30,   16,   16,   16, 0x0a,
      50,   16,   16,   16, 0x0a,
      74,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AddSupplyWindow[] = {
    "AddSupplyWindow\0\0MapHandler()\0"
    "AddDiseaseHandler()\0CreateShipmentHandler()\0"
    "ManageShipmentHandler()\0"
};

const QMetaObject AddSupplyWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AddSupplyWindow,
      qt_meta_data_AddSupplyWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddSupplyWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddSupplyWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddSupplyWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddSupplyWindow))
        return static_cast<void*>(const_cast< AddSupplyWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AddSupplyWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: MapHandler(); break;
        case 1: AddDiseaseHandler(); break;
        case 2: CreateShipmentHandler(); break;
        case 3: ManageShipmentHandler(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
