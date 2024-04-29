#include <string>

class Student
{
    public:
        explicit Student(std::string n, int a): 
            name{n} , age{a}
        {
         }
        void setName(std::string n) {
            name= n;
        }
        void setAge(int a){
            age =a;
        }
        std::string getName() const{
            return name;
        }
        int getAge() const{
            return age;
        }

        bool isOlder()const{
            bool older;
            if(age >= 18){
                older = true;
            }else{
                older=false;
            }
            return older;
        }

        
    private:
    std::string name;
    int age;

};