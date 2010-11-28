/****************************************************************************
** Meta object code from reading C++ file 'adddiseasewindow.h'
**
** Created: Sun Nov 28 17:18:00 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OmegaSquaddApplication/adddiseasewindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adddiseasewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddDiseaseWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      31,   17,   17,   17, 0x0a,
      50,   17,   17,   17, 0x0a,
      74,   17,   17,   17, 0x0a,
      99,   17,   17,   17, 0x0a,
     121,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AddDiseaseWindow[] = {
    "AddDiseaseWindow\0\0MapHandler()\0"
    "AddSupplyHandler()\0CreateShipmentHandler()\0"
    "ManageShipmentsHandler()\0ViewDiseasesHandler()\0"
    "ViewSuppliesHandler()\0"
};

const QMetaObject AddDiseaseWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AddDiseaseWindow,
      qt_meta_data_AddDiseaseWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddDiseaseWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddDiseaseWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddDiseaseWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddDiseaseWindow))
        return static_cast<void*>(const_cast< AddDiseaseWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AddDiseaseWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: MapHandler(); break;
        case 1: AddSupplyHandler(); break;
        case 2: CreateShipmentHandler(); break;
        case 3: ManageShipmentsHandler(); break;
        case 4: ViewDiseasesHandler(); break;
        case 5: ViewSuppliesHandler(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
