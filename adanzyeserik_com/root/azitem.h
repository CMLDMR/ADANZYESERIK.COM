#ifndef AZITEM_H
#define AZITEM_H

#include "listitem.h"


namespace AZ {

namespace Key {
static const std::string Collection{"Content"};
static const std::string type{"type"};


enum class Type : std::int32_t{
    DUYURU = 0,
    ETKINLIK,
    PHOTO,
    VIDEO,
    BASINDA
};



}






class Item : public SerikBLDCore::Item
{
public:
    Item(const Key::Type &type);
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
