/*

id.cpp
Armard Alexander
30 Sept 2017

*/

#include <id.h>
#include <cstring>

/*
class ID
{
public:


  void        SetName ( const char* ); // sets the name field
  void        SetAge  ( int );         // sets the age field
  const char* GetName () const;        // returns a const pointer to the name field
  int         GetAge  () const;        // returns the age field by value

  ID (); // name "#" age=-1
  ID (const char* name, int age );
  ~ID ();
  ID (const ID& i)
  ID& operator= (const ID& i);


private:
  char * name_  // the name field
  int    age_   // the age field

};

std::ostream& operator<< (std::ostream& os, const ID& i);
*/



void ID::SetName ( const char* name )
{

   if (name_ != nullptr)
     delete [] name;
size_t size = strlen(name);
name_ = new char [1+size];
name_[size] = '\0';
strcpy(name_, name);
}


void ID::SetAge  ( int age )
{
   age_ = age;
}

const char* ID::GetName () const

{
   return name_;
}


int ID::GetAge  () const

{

   return age_;
}

ID::ID () : name_(nullptr), age_(-1)
{
name_ = new char [2];
name_[0] = '#';
name_[1] = '\0';


}

ID::ID (const char* name, int age ) : name_(nullptr), age_(age)
{

size_t size = strlen(name);
name_ = new char [1+size];
name_[size] = '\0';
strcpy(name_, name);


}

ID::~ID ()
{
if (name_ != nullptr)
delete [] name_;
}

ID::ID (const ID& i) : name_(nullptr), age_(i.age_)
{
size_t size = strlen(i.name_);
name_ = new char [1+size];
name_[size] = '\0';
strcpy(name_,i.name_);

}

ID& ID::operator= (const ID& i)
{
if (this != &i)
 {
delete [] name_;
size_t size = strlen(name_);
name_ = new char [1+size];
name_[size] = '\0';
strcpy(name_,i.name_);
}


return *this;

}




std::ostream& operator<< (std::ostream& os, const ID& i)
{
os << i.GetName() << '\t'
   << i.GetAge();

 return os;
};
