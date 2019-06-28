#ifndef SMUSER_H_INCLUDED
#define SMUSER_H_INCLUDED

class User{
    private:
        //user variables
        string username, password;
    public:
        //constructor for user object
        User(string un, string pass);

        //setter function for User's username
        void setUsername(string un);

        //setter function for User's password
        void setPassword(string pass);

        //getter function for User's username
        string getUsername();

        //getter function for User's password
        string getPassword();
};

#endif // SMUSER_H_INCLUDED
