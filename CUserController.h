#ifndef CUSERCONTROLLER_H
#define CUSERCONTROLLER_H
#include "CJsonTool.h"
#include "CUser.h"
#include <vector>
#include <iostream>
using namespace std;
//Convention : Label : TL_name
/**
 * @brief The CUserController class
 */
class CUserController {
private:
    CUser *UserConnecter;
public:
    //Constructors and destructors
    CUserController();
    CUserController(const CUserController& Objet);
    ~CUserController();

    /**
     * @brief replace UserConnecter if somebody already connected then check the presence of the user in the file
     * @param username
     * @param password
     * @return
     */
    bool connection(QString username, QString password);

    /**
     * @brief deconnection : deconnect the current user
     */
    void deconnection();

    CUser getUserUserConnecter();

    /**
     * @brief get_list_user : returns a vector of users form the saves file
     * @param JsonFilePath
     * @return vector<CUser>
     */
    static vector<CUser> get_list_user(QString JsonFilePath);

    /**
     * @brief save_list_user : truncates the file then adds the vector to it
     * @param users
     * @param path
     */
    static void save_list_user(vector<CUser> users, QString path);

    /**
     * @brief chek_if_exist : checks if the user already exists
     * @param user
     * @return
     */
    static bool chek_if_exist(CUser& user);

    /**
     * @brief addUser : adds an user to the saves file
     * @param user
     * @return
     */
    static bool addUser(CUser user);


};
#endif // CUSERCONTROLLER_H
