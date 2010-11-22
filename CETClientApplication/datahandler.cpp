
#include "datahandler.h"
#include "CaseReport.h"

DataHandler::DataHandler()
{

}

//getCaseReports
//all parameters should be optional/nullable
//parameters are used to shape xml query
QList<CaseReport::CaseReport> DataHandler::getCaseReports(int idFrom, int idTo, int regionID, int dateFrom, int dateTo, int diseaseType, int quantityFrom, int quantityTo)
{
    //create a list to be returned
    QList<CaseReport::CaseReport> returnList;

    //encode parameters to xml query

    //send xml query to  communication component

    //receive xml result from component

    //dissect xml data and populate it into returnList


    //return the list
    return returnList;
}


//getDiseaseTypes
//no parameters passed in because it doesn't make sense
//of course it can be changed
QList<DiseaseType::DiseaseType> DataHandler::getDiseaseTypes()
{
    QList<DiseaseType::DiseaseType> returnList;

    //encode xml query

    //send xml query to  communication component

    //receive xml result from component

    //dissect xml data and populate it into returnList


    //return the list
    return returnList;

}

//getinventory
//follows stylings of get casereport
QList<Inventory::Inventory> DataHandler::DataHandler(int idFrom, int idTo, int regionID, int supplyType, int quantityFrom, int quantityTo)
{
    //create a list to be returned
    QList<Inventory::Inventory> returnList;

    //encode parameters to xml query

    //send xml query to  communication component

    //receive xml result from component

    //dissect xml data and populate it into returnList


    //return the list
    return returnList;
}
