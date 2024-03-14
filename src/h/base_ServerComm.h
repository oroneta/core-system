

#ifndef BASE_SERVERCOMM_H
#define BASE_SERVERCOMM_H


bool checkDic(const std::string& dic);

bool checkAuthCode(const std::string& dic, const std::string& authCode);

void insert(const std::string& dic , const std::string& ReqBody);



#endif 
