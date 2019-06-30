#ifndef SMUSER_H_INCLUDED
#define SMUSER_H_INCLUDED

class User{
    private:
        //user variables
        string username, password;
    public:
        User(string un, string pass);
        void setUsername(string un);
        void setPassword(string pass);
        string getUsername();
        string getPassword();
};

#endif // SMUSER_H_INCLUDED
