/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Nov 28 19:41:17 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OmegaSquaddApplication/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      34,   28,   11,   11, 0x08,
      72,   11,   11,   11, 0x08,
      93,   11,   11,   11, 0x08,
     115,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     154,   11,   11,   11, 0x08,
     176,   11,   11,   11, 0x08,
     198,   11,   11,   11, 0x08,
     219,   11,   11,   11, 0x08,
     252,  244,   11,   11, 0x0a,
     284,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0initializeMap()\0index\0"
    "currentIndexChangedForESSelector(int)\0"
    "showAboutCETDialog()\0closeAboutCETDialog()\0"
    "AddDiseaseHandler()\0AddSupplyHandler()\0"
    "ViewDiseasesHandler()\0ViewSuppliesHandler()\0"
    "AddShipmentHandler()\0ManageShipmentsHandler()\0"
    "name,id\0setNameIDValue(QString,QString)\0"
    "hideLoadingLabel()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initializeMap(); break;
        case 1: currentIndexChangedForESSelector((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: showAboutCETDialog(); break;
        case 3: closeAboutCETDialog(); break;
        case 4: AddDiseaseHandler(); break;
        case 5: AddSupplyHandler(); break;
        case 6: ViewDiseasesHandler(); break;
        case 7: ViewSuppliesHandler(); break;
        case 8: AddShipmentHandler(); break;
        case 9: ManageShipmentsHandler(); break;
        case 10: setNameIDValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: hideLoadingLabel(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
