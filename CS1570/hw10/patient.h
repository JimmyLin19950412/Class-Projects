// Name: Luka Ivicevic
// Section: E
// File: patient.h
// Desc: Class that simulates a patient

#include <iostream>

using namespace std;

#ifndef PATIENT_H
#define PATIENT_H

class Patient
{
  public:
    Patient();
    // Desc: Default constructor for patient class
    // Pre: None
    // Post: Randomly assigns the patient money 0-4000, whether or not alive,
    // and picks random name from a file
    void pay_out(float amount);
    // Desc: Reduces money from patient
    // Pre: Positive integer passed in
    // Post: Subtracts amount from the patient's money
    void modify_health();
    // Desc: Adds amount to the patient's condition
    // Pre: Positive integer passed in
    // Post: Adds amount to the patient's condition
	bool isAlive() const;
	// Desc: Returns true if condition != 0, false if condition == 0
	// Pre: None
	// Post: None
	int getMoney() const;
	// Desc: Returns how much money the patient has
	// Pre: None
	// Post: None
	
	void increaseMH(const int &num);
	// Desc: Increase mental health of patient 
	// Pre: Positive integer passed in
	// Post: Patient's mental health will be increased by num
	void decreaseMH(const int &num);
	// Desc: Decrease mental health of patient 
	// Pre: Positive integer passed in
	// Post: Patient's mental health will be decreased by num
	void setMH(const int &num);
	// Desc: Sets mental health equal to num
	// Pre: Num must be a positive integer
	// Post: m_mental_health is set to num
	void setZeroMH();
	// Desc: Set mental health to 0
	// Pre: None
	// Post: Patient's mental health will be set to 0
	
	void increaseC(const int &num);
	// Desc: Increase condition of patient 
	// Pre: Positive integer passed in
	// Post: Patient's condition will be increased by num
	void decreaseC(const int &num);
	// Desc: Decrease condition of patient 
	// Pre: Positive integer passed in
	// Post: Patient's condition will be decreased by num
	void setC(const int &num);
	// Desc: Sets the condition to the value passed in
	// Pre: Positive int passed in
	// Post: m_condition will be set to num
	void setZeroC();
	// Desc: Set condition to 0
	// Pre: None
	// Post: Patient's condition will be set to 0
	
	void increaseWOP(const int &num);
	// Desc: Increase weight of patient 
	// Pre: Positive integer passed in
	// Post: Patient's weight will be increased by num
	void decreaseWOP(const int &num);
	// Desc: Decrease weight of patient 
	// Pre: Positive integer passed in
	// Post: Patient's weight will be decreased by num
	int getWOP() const;
	// Desc: Returns weight of patient
	// Pre: None
	// Post: Returns weight of patient
	
	void changeName();
	// Desc: Changes the name of the patient to random name from names.dat
	// Pre: None
	// Post: Name of patient is changed
	
	int getMH();
	// Desc: Returns the mental health of the patient
	// Pre: None
	// Post: Returns the mental health of the patient
	
    friend ostream &operator<<(ostream &out, const Patient &victim);
    // Desc: Overloaded insertion operator to easily output the state of the
    // patient
  private:
    float m_money;
    bool m_is_alive;
    int m_condition;
	int m_mental_health;
	int m_wop; // weight of patient
    string m_name;
    void kill();
    // Desc: Checks whether or not the patient is dead
    // Pre: None
    // Post: Updates is_alive based on the liveliness of the patient
};

#endif
