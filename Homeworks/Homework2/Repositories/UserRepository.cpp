#include <string>
#include <odb/core.hxx>

#pragma db object
class User
{
    private:
        friend class odb::access;
        User () {}

        #pragma db id
        string email_;

        string name_;
        unsigned short age_;
};

int main(){
    return 0;
}