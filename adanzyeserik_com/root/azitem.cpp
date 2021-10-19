#include "azitem.h"



AZ::Item::Item(const Key::Type &type)
    :SerikBLDCore::Item(Key::Collection)
{
    if( type != Key::Type::NOP ){
        this->append(Key::type,static_cast<std::int32_t>(type));
    }
}

AZ::Item &AZ::Item::setTitle(const std::string &title)
{
    this->append(AZ::Key::title,title);
    return *this;
}

std::string AZ::Item::getTitle() const
{
    auto val = this->element(AZ::Key::title);
    if( val ){
        return val->get_utf8().value.to_string();
    }
    return "";
}

AZ::Item &AZ::Item::setContent(const std::string &content)
{
    this->append(AZ::Key::content,content);
    return *this;
}

std::string AZ::Item::getContent() const
{
    auto val = this->element(AZ::Key::content);
    if( val ){
        return val->get_utf8().value.to_string();
    }
    return "";
}

AZ::Item &AZ::Item::addFileOid(const std::string &fileOid)
{
    this->pushArray(Key::fileOidList,fileOid);
    return *this;
}

AZ::Item &AZ::Item::removeFileOid(const std::string &fileOid)
{
    this->pullArray(Key::fileOidList,bsoncxx::types::value(bsoncxx::types::b_utf8(fileOid)));
    return *this;
}

std::vector<std::string> AZ::Item::getfileOidList() const
{
    std::vector<std::string> list;

    auto val = this->element(AZ::Key::fileOidList);
    if( val ){
        auto arr = val->get_array().value;
        for( const auto &item : arr ){
            list.push_back(item.get_utf8().value.to_string());
        }
    }
    return list;
}

AZ::Item &AZ::Item::setType(Key::Type _mType)
{
    if( _mType != Key::Type::NOP ){
        this->append(Key::type,static_cast<std::int32_t>(_mType));
    }
    return *this;
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
