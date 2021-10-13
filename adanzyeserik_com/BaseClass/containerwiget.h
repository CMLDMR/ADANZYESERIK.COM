#ifndef CONTAINERWIGET_H
#define CONTAINERWIGET_H

#include "BaseClass/wtheaders.h"
#include "BaseClass/dbclass.h"

#include <QString>


constexpr int MAJOR = 3;
constexpr int MINOR = 3;
constexpr int REV = 31;
constexpr int COM = 477;

#ifndef LOG
#define LOG std::cout <<"\n"<< __LINE__ << " " << __FUNCTION__ << " -> "
#define LOGEND "\n"
#define LOGN std::cout << "\n"<<__LINE__ << " " << __FUNCTION__ << "\n"
#define LOGSTR(x) std::cout << "\n"<<__LINE__ << " " << __FUNCTION__ << ": "<< x << "\n"
#endif






class ContainerWidget : public WContainerWidget, public UtilityWt
{
public:
    enum ContentType{
        Horizontal,
        Vertical
    };

    ContainerWidget(const std::string &title = "" , ContentType _contentType = Vertical );

    WContainerWidget* Header();
    WContainerWidget* Content();
    WContainerWidget* Footer();

    void setTitleBarBackColor( const std::string& color = Style::color::Purple::MidnightBlue );



    WPushButton *askConfirm( const std::string& question );

    void warnDialog( const std::string &warnMessage );
    void criticDialog( const std::string &criticMessage );
    void informDialog( const std::string &informMessage );
    void informDialog( const std::string &title , const std::string &informMessage );



    ContainerWidget& setDataOid( const std::string &oid ){
        this->setAttributeValue (Style::dataoid,oid);
        return *this;
    }




    std::unique_ptr<WContainerWidget> createButton( const std::string &menuName , const Cursor cursor = Cursor::Auto);


    /**
     * @brief createDialog:  WDialog Oluşturur ve Geri ptr Geri Döndürür.
     * @return
     */
    WDialog* createDialog( const std::string& title = "" );

    void removeDialog( WDialog* mDialog );

    enum ContainerStyleType
    {
        ROW = 0,
        CONTAINERFLUID
    };


    void setContainerStyle(ContainerStyleType type);



    inline std::string rgbaRandom(){

        return WString("{1},{2},{3}").arg (this->getRandom (150,200))
                .arg (this->getRandom (170,220))
                .arg (this->getRandom (180,230)).toUTF8 ();
    }

    void showMessage( std::string title , std::string msg , std::string btnText = "Tamam");


    /**
     * @brief showPopUpMessage : Mesaj Gönder infoType info,msg ve ""
     * @param msg
     * @param infoType info,msg ve boşluk
     */
    void showPopUpMessage(const std::string & msg , const std::string &infoType = "info" );///*msg*/


    ///
    /// \brief removeTitleBar: Eğer Title Mevcutsa Container da Bulunan Başlığı Siler.
    ///
    void removeTitleBar();


private:
    WContainerWidget* mHeaderContainer;
    WContainerWidget* mContentContainer;
    WContainerWidget* mFootContainer;

    WContainerWidget* mTitleBar;
    std::string mTitle;

};



class FileUploaderWidget : public ContainerWidget /*, public DBClass*/
{
public:
    explicit FileUploaderWidget( const std::string &title = "PDF Cevap Yükle" );





    /**
     * @brief isUploaded: Check file is Uploaded
     * @return
     */
    bool isUploaded() const;





    /**
     * @brief The FilterType enum: Selectable File Type
     */
    enum FilterType{
        Pdf,
        Image,
        DWG
    };





    /**
     * @brief setType: File Type
     * @param type: Pdf , Image
     */
    void setType( FilterType type );






    /**
     * @brief fileLocation: Location is FULL PATH
     * @return
     */
    QString fileLocation() const;





    /**
     * @brief doocRootLocation: Location is Without docroot folder
     * @return
     */
    QString doocRootLocation() const;




    /**
     * @brief Uploaded: Signal Triggered When File Uploaded
     * @return
     */
    Signal<NoClass> &Uploaded();

private:
    WFileUpload* mFileUploader;

    QString mFileLocation;
    QString mDoocRootLocation;

    bool mIsUploaded;

    Signal<NoClass> _Uploaded;

    FilterType mType;
};


#endif // CONTAINERWIGET_H
