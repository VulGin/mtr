#ifndef _SQLITE_DATA_PROVIDER_H
#define _SQLITE_DATA_PROVIDER_H

#include "IDataProvider.h"
#include <string>

struct sqlite3;

namespace mtr
{

class SqliteDataProvider : public IDataProvider
{
public:
    SqliteDataProvider();
    virtual ~SqliteDataProvider();
    virtual MTR_STATUS PublishData( IDataManager * const in_data_manager );
    virtual MTR_STATUS GetData( SymbolHandle const & in_symbol_handle, 
                                AttributeHandle const & in_attribute_handle, 
                                std::vector<Timestamp> const & in_dates, 
                                std::vector<std::pair<Timestamp, double> > * out_data);
    MTR_STATUS OpenDatabase( std::string in_database_name );
    MTR_STATUS ReadCSVFile( std::string in_file_name );
private:
    SqliteDataProvider( SqliteDataProvider const & );
    SqliteDataProvider const & operator=( SqliteDataProvider const & );

    sqlite3 * database_;
};
}

#endif //_SQLITE_DATA_PROVIDER_H
