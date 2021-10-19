#ifndef AZITEM_H
#define AZITEM_H

#include "listitem.h"


namespace AZ {

namespace Key {
static const std::string Collection{"Content"};
static const std::string type{"type"};
static const std::string content{"content"};
static const std::string fileOidList{"fileOidList"};
static const std::string title{"title"};

enum class Type : std::int32_t{
    DUYURU = 0,
    ETKINLIK = 1,
    PHOTO = 2,
    VIDEO = 3,
    BASINDA = 4,
    NOP = 100
};



}






class Item : public SerikBLDCore::Item
{
public:
    Item(const Key::Type &type = Key::Type::NOP);

    Item& setTitle( const std::string &title );
    std::string getTitle() const;

    Item& setContent( const std::string &content );
    std::string getContent() const;

    Item& addFileOid( const std::string &fileOid );
    Item& removeFileOid( const std::string &fileOid );

    std::vector<std::string> getfileOidList() const;

    AZ::Key::Type getType(){

        Key::Type _type = Key::Type::NOP;

        auto val = this->element(Key::type);
        if( val ){
            _type = static_cast<Key::Type>(val->get_int32().value);
        }
        return _type;
    }

    Item& setType( AZ::Key::Type _mType );
};








class ItemManager : public SerikBLDCore::ListItem<Item>
{
public:
    ItemManager( SerikBLDCore::DB* _mDB );


    virtual void onList(const QVector<Item> *mlist) override;

    virtual void errorOccured(const std::string &errorText) override;

    const std::string &mLastError() const;

private:
    std::string _mLastError;
};

}


#endif // AZITEM_H
