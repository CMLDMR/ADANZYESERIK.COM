#include "azitem.h"



AZ::Item::Item(const Key::Type &type)
    :SerikBLDCore::Item(Key::Collection)
{
    this->append(Key::type,static_cast<std::int32_t>(type));
}

AZ::ItemManager::ItemManager(DB *_mDB)
    :SerikBLDCore::ListItem<Item>(_mDB)
{

}

void AZ::ItemManager::onList(const QVector<Item> *mlist)
{



}

void AZ::ItemManager::errorOccured(const std::string &errorText)
{
    this->_mLastError = errorText;
}


namespace AZ {
const std::string &ItemManager::mLastError() const
{
    return _mLastError;
}

}
