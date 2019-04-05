#include<iostream>
#include<thread>
#include<map>
#include<vector>
#include<string>
#include<stdexcept>

#include"rwmutex.h"

using namespace std;

/* A Person; they have a name and a SSN. */
struct Person
{
  string name;
  string SSN;
};

/* A database of Persons.
 * People can be looked up by database ID or by SSN.
 *
 * This database can be used concurrently by multiple threads.
 */
class PeopleDB
{
  private:
    RWmutex mtx;
    vector<string> SSNs; /* Databse ID -> SSN */
    map<string,Person> SSN_to_Person; /* SSN -> Person object */

  public:

    /* Adds a person to the database
     * and returns the Database ID for that Person.
     */
    unsigned int addPerson(Person p)
    {
      Wlock lock(mtx); // Hold a write lock until this function exits
	  this_thread::yield();
		
		 //---------------------PERSONAL CODE------------------------
	cout<<"lcok addPerson"<<endl;
	//-----------------END PERSONAL CODE------------------------
	
      SSNs.push_back(p.SSN);
      SSN_to_Person[p.SSN] = p;

      return SSNs.size() - 1; // Index of new SSN in SSNs vector
    }

    /* Given a SSN, looks up the person in the database.
     * Throws a logic_error exception should the person not be present.
     */
    Person getPersonBySSN(string ssn)
    {
      //Rlock lock(mtx); // Hold a read lock until this function exits
	  //this_thread::yield();
	
	 //---------------------PERSONAL CODE------------------------
	cout<<"getPersonBySSN"<<endl;
	//-----------------END PERSONAL CODE------------------------
	
      // Look through the database and see if the person is present
      auto result = SSN_to_Person.find(ssn);
      if(result == SSN_to_Person.end())
      {
        throw logic_error("Invalid SSN");
      }

	  //---------------------PERSONAL CODE------------------------
	cout<<"getPersonBySSN 2"<<endl;
	//-----------------END PERSONAL CODE------------------------
	  
      // Result is a std::pair with the key (ssn)
      // as the first element and the value (Person object)
      // as the second.
      return result->second;
    }

    /* Given a database ID, looks up the associated person in the database.
     * Throws a logic_error if the ID is not valid.
     */
    Person getPersonByID(unsigned int id)
    {
      Rlock lock(mtx); // Hold a read lock until this function exits
	  this_thread::yield();
	
		 //---------------------PERSONAL CODE------------------------
	cout<<"lock getPersonById"<<endl;
	//-----------------END PERSONAL CODE------------------------
		
      if(id >= SSNs.size())
      {
        throw logic_error("Invalid id");
      }
		
		//---------------------PERSONAL CODE------------------------
	cout<<"lock getPersonById 2"<<endl;
	//-----------------END PERSONAL CODE------------------------
		
      return getPersonBySSN(SSNs[id]);
    }
};

void add(PeopleDB* db)
{
  for(int i = 0; i < 100; i++)
  {
    Person p = {"bob", to_string(i)}; // Make up a name and SSN
	//---------------------PERSONAL CODE------------------------
		cout<<"add "<<p.name<<" "<<p.SSN<<endl;
	//-----------------END PERSONAL CODE------------------------
    db->addPerson(p);
  }
}

void get_one(PeopleDB* db)
{
  for(int i = 0; i < 1000; i++)
  {
	  //---------------------PERSONAL CODE------------------------
	cout<<"get_one i loop "<<i<<endl;
	//-----------------END PERSONAL CODE------------------------
    try
    {
      db->getPersonByID(0);
    }
    catch (...) {} // what's a few exceptions among friends
  }
}

int main()
{
  PeopleDB db;

  thread writer(add, &db); // Add 100 people to the database
  thread reader(get_one, &db); // Repeatedly read from the database

  writer.join();
  reader.join();
  
  cout<<"i am done"<<endl;
  
  return 0;
}
